

#include <Arduino.h>
#include "skp_lvgl.h"
#include <lvgl.h>
#include <Wire.h>

#include <GSL1680.h>
#include "SSD1963.h"

#include "ui.h"
#include "ui_helpers.h"

#define WAKE 255
#define INTRPT 20

GSL1680 ts = GSL1680();
uint16_t TouchY;
uint16_t TouchX;
bool     TouchZ = false;

int oldTouchX = 0;
int oldTouchY = 0;

static const uint16_t screenWidth  = 800;  //800x480
static const uint16_t screenHeight = 480;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * 10 ];
extern SSD1963 lcd;

/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{ 
   uint16_t width = (area->x2 - area->x1 +1);
   uint16_t height = (area->y2 - area->y1+1);
 
   lcd.writeRect(area->x1, area->y1, width, height, (uint16_t *)color_p);
   lv_disp_flush_ready(disp); /* tell lvgl that flushing is done */
   
}

bool my_touchpad_read(lv_indev_t * indev, lv_indev_data_t * data)
{
  uint16_t touchX, touchY;

          int NBFinger = ts.dataread();
          // Retrieve a point  
          for(int i=0; i<NBFinger; i++){
                touchX = ts.readFingerX(i);
                touchY = ts.readFingerY(i);
          
                if ((touchX != oldTouchX) || (touchY != oldTouchY))
                {
                    //  Serial.print("x= ");
                   //   Serial.print(touchX,DEC);
                    //  Serial.print(" y= ");
                   //   Serial.println(touchY,DEC);
                      
                      oldTouchY = touchY;
                      oldTouchX = touchX;
                      data->state = LV_INDEV_STATE_PR; 
                      data->point.x = touchX;
                      data->point.y = touchY;
                
                }else
                {
                    data->point.x = oldTouchX;
                    data->point.y = oldTouchY;
                    data->state =LV_INDEV_STATE_REL;
                }
          }

  
    return 0;
}

void skp_lvgl_init(void)
{
    Serial.println("lvgl init");
    ts.begin(WAKE, INTRPT);
   
    lv_init();
    lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth * 10 );

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init( &disp_drv );
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    //disp_drv.sw_rotate = LV_DISP_ROT_180;
    disp_drv.rotated = LV_DISP_ROT_NONE;
    disp_drv.sw_rotate = 1;
    lv_disp_drv_register( &disp_drv );

    /*Initialize the (dummy) input device driver*/
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init( &indev_drv );
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register( &indev_drv );
 
    ui_init();
  
}
