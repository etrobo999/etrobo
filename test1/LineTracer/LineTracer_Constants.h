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
constexpr int LB_X1 = 540;
constexpr int LB_X2 = 420;
constexpr int LB_X3 = 360;
constexpr int LB_X4 = 300;
constexpr int LB_X5 = 240;

constexpr int RB_X1 = 600;
constexpr int RB_X2 = 660;
constexpr int RB_X3 = 720;
constexpr int RB_X4 = 800;
constexpr int RB_X5 = 860;
constexpr int B_W = 60;
constexpr int ALLB_Y1 = 0;
constexpr int ALLB_Y2 = TRIMH;

const cv::Point upperLeftPoint[5] = { 
    {LB_X5, ALLB_Y1}, 
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
    {RB_X5, ALLB_Y2} 
};

const int XPoint[10] ={
    LB_X5, LB_X4, LB_X3, LB_X2, LB_X1, RB_X1, RB_X2, RB_X3, RB_X4, RB_X5
}