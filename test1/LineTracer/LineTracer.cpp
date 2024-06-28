#include <opencv2/opencv.hpp>
#include "app.h"
#include "LineTracer.h"
#include <stdio.h>
#include <iostream>

/* 関数プロトタイプ宣言 */

static void Capture(void);
/*static void motor_cntrol(void);*/

/* ライントレースタスク(100msec周期で関数コールされる) */
void tracer_task(intptr_t &unused) {
    Capture();

    /* タスク終了 */
    ext_tsk();
}

static void Capture(void){
    cv::VideoCapture camera(0);
    if (!camera.isOpened()) {
        std::cerr << "Error: Camera could not be opened." << std::endl;
        return;
    }

    cv::Mat frame;
    camera >> frame;
    if (frame.empty()) {
        std::cerr << "Error: Frame is empty." << std::endl;
        return;
    }
    std::cout << "Cols: " << frame.cols << ", Rows: " << frame.rows << std::endl;
    frame = frame(cv::Rect(0, TRIMY, frame.cols, TRIMH));
    cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY);
    cv::threshold(frame, frame, THRESHOLDVALUE, MAXBINARYVALUE, cv::THRESH_BINARY_INV);

    
    for (int i = 0; i < 4; ++i) {
        cv::rectangle(frame, upperLeftPoint[i], lowerRightPoint[i], cv::Scalar(0, 0, 255), 1);
        
    }
    uint16_t detectionFlags = 0;
    for (int i = 0; i < 8; ++i) {
        if(cv::countNonZero(frame(cv::Rect(XPoint[i], 0, B_W, ALLB_Y2))) >= 150 ){
            detectionFlags |= (1 << i);
        } else { 
            detectionFlags |= (0 << i);
        }
    }
    /*motor_cntrol(detectionFlags)*/
    return;
}
/* 走行モータ制御 
static void motor_cntrol(detectionResults){
    switch (detectionFlags)
    {
    
    
    default:
        break;
    }
    ev3_motor_set_power(left_motor, 100);
    ev3_motor_set_power(right_motor, 100);
    return;
}*/
