#include <opencv2/opencv.hpp>
#include "app.h"
#include "LineTracer.h"
#include <stdio.h>
#include <iostream>
#include <bitset>

/* 関数プロトタイプ宣言 */

static void Capture(void); 
static void motor_cntrol(uint8_t detectionFlags);

/* ライントレースタスク(100msec周期で関数コールされる) */
void tracer_task(intptr_t unused) {
    Capture();

    /* タスク終了 */
    ext_tsk();
}

static void Capture(void){
    cv::VideoCapture camera(0);
    int retry_count = 0;
    const int max_retries = 5;
    if (!camera.isOpened()) {
        std::cerr << "Error: Camera could not be opened." << std::endl;
        return;
    }
    cv::Mat frame;
    while (retry_count < max_retries) {
        camera >> frame;
        if (frame.empty()) {
            std::cerr << "Error: Frame is empty. Retrying..." << std::endl;
            retry_count++;
            continue;
        }
        break;
    }

    if (frame.empty()) {
        std::cerr << "Error: Frame is empty after maximum retries." << std::endl;
        return;
    }
    std::cout << "Cols: " << frame.cols << ", Rows: " << frame.rows << std::endl;
    frame = frame(cv::Rect(0, TRIMY, frame.cols, TRIMH));
    cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY);
    cv::threshold(frame, frame, THRESHOLDVALUE, MAXBINARYVALUE, cv::THRESH_BINARY_INV);
    
    for (int i = 0; i < 4; ++i) {
        cv::rectangle(frame, upperLeftPoint[i], lowerRightPoint[i], cv::Scalar(0, 0, 255), 1);
        
    }
    uint8_t detectionFlags = 0;
    for (int i = 0; i < 8; ++i) {
        if(cv::countNonZero(frame(cv::Rect(XPoint[i], 0, B_W, ALLB_Y2))) >= 150 ){
            detectionFlags |= (1 << i);
        } else { 
            detectionFlags |= (0 << i);
        }
    }
    std::bitset<8> binary(detectionFlags);
    std::cerr <<  "detectionFlags: " << binary << std::endl;
    motor_cntrol(detectionFlags);
    camera.release();
    return;
}
/* 走行モータ制御 */
static void motor_cntrol(uint8_t detectionFlags){
    switch (detectionFlags)
    {
    /*直進*/
    case 0x18: /*0001 1000*/
    case 0x1c: /*0001 1100*/
    case 0x38: /*0011 1000*/
        ev3_motor_set_power(left_motor, 100);
        ev3_motor_set_power(right_motor, 100);
        break;

    /*微左カーブ*/
    case 0x30: /*0011 0000*/
    case 0x70: /*0111 0000*/
        ev3_motor_set_power(left_motor, 85);
        ev3_motor_set_power(right_motor, 100);
        break;
    
    /*左カーブ*/
    case 0x60: /*0110 0000*/
    case 0xe0: /*1110 0000*/
        ev3_motor_set_power(left_motor, 70);
        ev3_motor_set_power(right_motor, 100);
        break;
    
    /*特左カーブ*/
    case 0xc0: /*1100 0000*/
        ev3_motor_set_power(left_motor, 55);
        ev3_motor_set_power(right_motor, 100);
        break;
    
    /*微右カーブ*/
    case 0x0c: /*0000 1100*/
    case 0x0e: /*0000 1110*/
        ev3_motor_set_power(left_motor, 100);
        ev3_motor_set_power(right_motor, 85);
        break;

    /*右カーブ*/
    case 0x06: /*0000 0110*/
    case 0x07: /*0000 0111*/
        ev3_motor_set_power(left_motor, 100);
        ev3_motor_set_power(right_motor, 70);
        break;

    /*特右カーブ*/
    case 0x03: /*0000 0011*/
        ev3_motor_set_power(left_motor, 100);
        ev3_motor_set_power(right_motor, 55);
        break;

    /*停止*/
    case 0Xff:
        ev3_motor_set_power(left_motor, 0);
        ev3_motor_set_power(right_motor, 0);
        break;    
    default:
        break;
    }
    return;
}
