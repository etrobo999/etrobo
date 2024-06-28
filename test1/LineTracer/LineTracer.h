#pragma once

#include <opencv2/opencv.hpp>

#ifdef __cplusplus
extern "C" {
#endif

/* 下記の項目は各ロボットに合わせて変えること */

/* カラーセンサの輝度設定 */
constexpr int WHITE_BRIGHTNESS = 180;
constexpr int BLACK_BRIGHTNESS = 10;

/*カメラの閾値設定*/
constexpr int THRESHOLDVALUE = 50;
constexpr int MAXBINARYVALUE = 255;

/*カメラのトリミング*/
constexpr int TRIMY = 280;
constexpr int TRIMH = 30;

/*ブロックエリアの設定*/
constexpr int LB_X1 = 270;
constexpr int LB_X2 = 220;
constexpr int LB_X3 = 170;
constexpr int LB_X4 = 120;

constexpr int RB_X1 = 320;
constexpr int RB_X2 = 370;
constexpr int RB_X3 = 420;
constexpr int RB_X4 = 470;
constexpr int B_W = 50;
constexpr int ALLB_Y1 = 0;
constexpr int ALLB_Y2 = TRIMH;

/* ステアリング操舵量の係数 */
constexpr float STEERING_COEF = 0.2F;

/* 走行基準スピード */
constexpr int BASE_SPEED = 40;

/* ライントレースエッジ切り替え */
constexpr int LEFT_EDGE = -1;
constexpr int RIGHT_EDGE = 1;

#ifdef __cplusplus
}
#endif

const cv::Point upperLeftPoint[4] = {
    {LB_X3, ALLB_Y1},
    {LB_X1, ALLB_Y1},
    {RB_X2, ALLB_Y1},
    {RB_X4, ALLB_Y1}
};
const cv::Point lowerRightPoint[4] = {
    {LB_X4, ALLB_Y2},
    {LB_X2, ALLB_Y2},
    {RB_X1, ALLB_Y2},
    {RB_X3, ALLB_Y2},
};

const int XPoint[8] = {
    RB_X4, RB_X3, RB_X2, RB_X1, LB_X1, LB_X2, LB_X3, LB_X4
};