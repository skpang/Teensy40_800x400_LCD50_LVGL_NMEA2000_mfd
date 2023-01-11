// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.3.3
// PROJECT: nmea2000_wind_mfd

#ifndef _NMEA2000_WIND_MFD_UI_H
#define _NMEA2000_WIND_MFD_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
  #if __has_include("lvgl.h")
    #include "lvgl.h"
  #elif __has_include("lvgl/lvgl.h")
    #include "lvgl/lvgl.h"
  #else
    #include "lvgl.h"
  #endif
#else
  #include "lvgl.h"
#endif

extern lv_obj_t *ui_Screen1;
extern lv_obj_t *ui_Screen1_Image1;
extern lv_obj_t *ui_Screen1_Image2;
extern lv_obj_t *ui_lbWindDirection;
extern lv_obj_t *ui_lbWindSpeed;
extern lv_obj_t *ui_Screen1_Label3;
extern lv_obj_t *ui_Screen1_Label1;
extern lv_obj_t *ui_Screen1_Label4;
extern lv_obj_t *ui_Screen1_Label5;
extern lv_obj_t *ui_Screen1_Label2;
extern lv_obj_t *ui_lbWaterTemp;
extern lv_obj_t *ui_Screen1_Label6;
extern lv_obj_t *ui_Screen1_Label7;
extern lv_obj_t *ui_lbCOG;
extern lv_obj_t *ui_lbSOG;
extern lv_obj_t *ui_Screen1_Label8;
extern lv_obj_t *ui_Screen1_Label9;
extern lv_obj_t *ui_Screen1_Label10;
extern lv_obj_t *ui_Screen1_Label11;
extern lv_obj_t *ui_lbEngineRPM;
extern lv_obj_t *ui_lbAltVolt;
extern lv_obj_t *ui_Screen1_Label12;
extern lv_obj_t *ui_Screen1_Label13;
extern lv_obj_t *ui_Screen1_Label14;
extern lv_obj_t *ui_Screen1_Label15;


LV_IMG_DECLARE( ui_img_wind_png);   // assets/wind.png
LV_IMG_DECLARE( ui_img_red_pointer_png);   // assets/red_pointer.png




void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
