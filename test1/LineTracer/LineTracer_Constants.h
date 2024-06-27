#pragma once

#include <opencv2/opencv.hpp>

/* カラーセンサの輝度設定 */
constexpr int WHITE_BRIGHTNESS = 180;
constexpr int BLACK_BRIGHTNESS = 10;

/* カメラの閾値設定 */
constexpr int THRESHOLDVALUE = 50;
constexpr int MAXBINARYVALUE = 255;

/* カメラのトリミング */
constexpr int TRIMY = 1220;
constexpr int TRIMH = 30;

/* ブロックエリアの設定 */
constexpr int LB_X1 = 440;
constexpr int LB_X2 = 360;
constexpr int LB_X3 = 280;
constexpr int LB_X4 = 200;

constexpr int RB_X1 = 520;
constexpr int RB_X2 = 600;
constexpr int RB_X3 = 680;
constexpr int RB_X4 = 760;
constexpr int B_W = 80;
constexpr int ALLB_Y1 = 0;
constexpr int ALLB_Y2 = TRIMH;

const cv::Point upperLeftPoint[5] = {  
    {LB_X3, ALLB_Y1}, 
    {LB_X1, ALLB_Y1}, 
    {RB_X2, ALLB_Y1}, 
    {RB_X4, ALLB_Y1} 
};
const cv::Point lowerRightPoint[5] = { 
    {LB_X4, ALLB_Y2}, 
    {LB_X2, ALLB_Y2}, 
    {RB_X1, ALLB_Y2}, 
    {RB_X3, ALLB_Y2}, 
};

const int XPoint[10] ={
    RB_X4, RB_X3, RB_X2, RB_X1, LB_X1, LB_X2, LB_X3, LB_X4
}