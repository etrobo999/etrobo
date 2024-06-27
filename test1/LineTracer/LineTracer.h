#ifdef __cplusplus
extern "C" {
#endif

/* 下記の項目は各ロボットに合わせて変えること */

/* カラーセンサの輝度設定 */
#define WHITE_BRIGHTNESS  (180)
#define BLACK_BRIGHTNESS  (10) 

/*カメラの閾値設定*/
#define THRESHOLDVALUE (50)
#define MAXBINARYVALUE (255)

/*カメラのトリミング*/
#define TRIMY (1220)
#define TRIMH (30)

/*ブロックエリアの設定*/
#define LB_X1 (540)
#define LB_X2 (420) 
#define LB_X3 (360) 
#define LB_X4 (300) 
#define LB_X5 (240) 

#define RB_X1 (600) 
#define RB_X2 (660)
#define RB_X3 (720) 
#define RB_X4 (800) 
#define RB_X5 (860)
#define B_W (60)
#define ALLB_Y1 (0) 
#define ALLB_Y2 (TRIMH)

/* ステアリング操舵量の係数 */
#define STEERING_COEF     (0.2F) 

/* 走行基準スピード */
#define BASE_SPEED        (40) 

/* ライントレースエッジ切り替え */
#define LEFT_EDGE         (-1) 
#define RIGHT_EDGE        (1) 

#ifdef __cplusplus
}
#endif
