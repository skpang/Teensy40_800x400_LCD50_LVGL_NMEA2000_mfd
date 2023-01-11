// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.3.3
// PROJECT: nmea2000_wind_mfd

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t *ui_Screen1;
lv_obj_t *ui_Screen1_Image1;
lv_obj_t *ui_Screen1_Image2;
lv_obj_t *ui_lbWindDirection;
lv_obj_t *ui_lbWindSpeed;
lv_obj_t *ui_Screen1_Label3;
lv_obj_t *ui_Screen1_Label1;
lv_obj_t *ui_Screen1_Label4;
lv_obj_t *ui_Screen1_Label5;
lv_obj_t *ui_Screen1_Label2;
lv_obj_t *ui_lbWaterTemp;
lv_obj_t *ui_Screen1_Label6;
lv_obj_t *ui_Screen1_Label7;
lv_obj_t *ui_lbCOG;
lv_obj_t *ui_lbSOG;
lv_obj_t *ui_Screen1_Label8;
lv_obj_t *ui_Screen1_Label9;
lv_obj_t *ui_Screen1_Label10;
lv_obj_t *ui_Screen1_Label11;
lv_obj_t *ui_lbEngineRPM;
lv_obj_t *ui_lbAltVolt;
lv_obj_t *ui_Screen1_Label12;
lv_obj_t *ui_Screen1_Label13;
lv_obj_t *ui_Screen1_Label14;
lv_obj_t *ui_Screen1_Label15;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{
ui_Screen1 = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Screen1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Screen1_Image1 = lv_img_create(ui_Screen1);
lv_img_set_src(ui_Screen1_Image1, &ui_img_wind_png);
lv_obj_set_width( ui_Screen1_Image1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Screen1_Image1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Screen1_Image1, 15 );
lv_obj_set_y( ui_Screen1_Image1, 15 );
lv_obj_add_flag( ui_Screen1_Image1, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Screen1_Image1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Screen1_Image2 = lv_img_create(ui_Screen1);
lv_img_set_src(ui_Screen1_Image2, &ui_img_red_pointer_png);
lv_obj_set_width( ui_Screen1_Image2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Screen1_Image2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Screen1_Image2, 224 );
lv_obj_set_y( ui_Screen1_Image2, 37 );
lv_obj_add_flag( ui_Screen1_Image2, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Screen1_Image2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_pivot(ui_Screen1_Image2,16,202);
lv_img_set_angle(ui_Screen1_Image2,2700);

ui_lbWindDirection = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_lbWindDirection, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_lbWindDirection, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_lbWindDirection, -524 );
lv_obj_set_y( ui_lbWindDirection, -29 );
lv_obj_set_align( ui_lbWindDirection, LV_ALIGN_RIGHT_MID );
lv_label_set_text(ui_lbWindDirection,"223");
lv_obj_set_style_text_align(ui_lbWindDirection, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_decor(ui_lbWindDirection, LV_TEXT_DECOR_NONE, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_lbWindDirection, &lv_font_montserrat_48, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_lbWindSpeed = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_lbWindSpeed, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_lbWindSpeed, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_lbWindSpeed, -515 );
lv_obj_set_y( ui_lbWindSpeed, 61 );
lv_obj_set_align( ui_lbWindSpeed, LV_ALIGN_RIGHT_MID );
lv_label_set_text(ui_lbWindSpeed,"16.8");
lv_obj_set_style_text_align(ui_lbWindSpeed, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_lbWindSpeed, &lv_font_montserrat_48, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Screen1_Label3 = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Screen1_Label3, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Screen1_Label3, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Screen1_Label3, -170 );
lv_obj_set_y( ui_Screen1_Label3, -62 );
lv_obj_set_align( ui_Screen1_Label3, LV_ALIGN_CENTER );
lv_label_set_text(ui_Screen1_Label3,"Direction");
lv_obj_set_style_text_color(ui_Screen1_Label3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Screen1_Label3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Screen1_Label3, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Screen1_Label1 = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Screen1_Label1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Screen1_Label1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Screen1_Label1, -114 );
lv_obj_set_y( ui_Screen1_Label1, -42 );
lv_obj_set_align( ui_Screen1_Label1, LV_ALIGN_CENTER );
lv_label_set_text(ui_Screen1_Label1,"o");
lv_obj_set_style_text_align(ui_Screen1_Label1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Screen1_Label1, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Screen1_Label4 = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Screen1_Label4, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Screen1_Label4, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Screen1_Label4, -155 );
lv_obj_set_y( ui_Screen1_Label4, 27 );
lv_obj_set_align( ui_Screen1_Label4, LV_ALIGN_CENTER );
lv_label_set_text(ui_Screen1_Label4,"Wind Speed");
lv_obj_set_style_text_color(ui_Screen1_Label4, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Screen1_Label4, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Screen1_Label4, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Screen1_Label5 = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Screen1_Label5, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Screen1_Label5, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Screen1_Label5, -102 );
lv_obj_set_y( ui_Screen1_Label5, 68 );
lv_obj_set_align( ui_Screen1_Label5, LV_ALIGN_CENTER );
lv_label_set_text(ui_Screen1_Label5,"kt");
lv_obj_set_style_text_color(ui_Screen1_Label5, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Screen1_Label5, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Screen1_Label5, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Screen1_Label2 = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Screen1_Label2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Screen1_Label2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Screen1_Label2, -158 );
lv_obj_set_y( ui_Screen1_Label2, 135 );
lv_obj_set_align( ui_Screen1_Label2, LV_ALIGN_CENTER );
lv_label_set_text(ui_Screen1_Label2,"skpang.co.uk");
lv_obj_set_style_text_color(ui_Screen1_Label2, lv_color_hex(0x545353), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Screen1_Label2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Screen1_Label2, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_lbWaterTemp = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_lbWaterTemp, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_lbWaterTemp, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_lbWaterTemp, -78 );
lv_obj_set_y( ui_lbWaterTemp, -154 );
lv_obj_set_align( ui_lbWaterTemp, LV_ALIGN_RIGHT_MID );
lv_label_set_text(ui_lbWaterTemp,"21.5");
lv_obj_set_style_text_align(ui_lbWaterTemp, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_decor(ui_lbWaterTemp, LV_TEXT_DECOR_NONE, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_lbWaterTemp, &lv_font_montserrat_48, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Screen1_Label6 = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Screen1_Label6, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Screen1_Label6, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Screen1_Label6, 333 );
lv_obj_set_y( ui_Screen1_Label6, -172 );
lv_obj_set_align( ui_Screen1_Label6, LV_ALIGN_CENTER );
lv_label_set_text(ui_Screen1_Label6,"o");
lv_obj_set_style_text_align(ui_Screen1_Label6, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Screen1_Label6, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Screen1_Label7 = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Screen1_Label7, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Screen1_Label7, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Screen1_Label7, 251 );
lv_obj_set_y( ui_Screen1_Label7, -196 );
lv_obj_set_align( ui_Screen1_Label7, LV_ALIGN_CENTER );
lv_label_set_text(ui_Screen1_Label7,"Water Temperature");
lv_obj_set_style_text_color(ui_Screen1_Label7, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Screen1_Label7, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Screen1_Label7, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_lbCOG = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_lbCOG, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_lbCOG, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_lbCOG, -213 );
lv_obj_set_y( ui_lbCOG, 195 );
lv_obj_set_align( ui_lbCOG, LV_ALIGN_RIGHT_MID );
lv_label_set_text(ui_lbCOG,"128");
lv_obj_set_style_text_align(ui_lbCOG, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_decor(ui_lbCOG, LV_TEXT_DECOR_NONE, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_lbCOG, &lv_font_montserrat_48, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_lbSOG = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_lbSOG, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_lbSOG, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_lbSOG, -74 );
lv_obj_set_y( ui_lbSOG, 198 );
lv_obj_set_align( ui_lbSOG, LV_ALIGN_RIGHT_MID );
lv_label_set_text(ui_lbSOG,"21.5");
lv_obj_set_style_text_align(ui_lbSOG, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_decor(ui_lbSOG, LV_TEXT_DECOR_NONE, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_lbSOG, &lv_font_montserrat_48, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Screen1_Label8 = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Screen1_Label8, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Screen1_Label8, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Screen1_Label8, 141 );
lv_obj_set_y( ui_Screen1_Label8, 152 );
lv_obj_set_align( ui_Screen1_Label8, LV_ALIGN_CENTER );
lv_label_set_text(ui_Screen1_Label8,"COG");
lv_obj_set_style_text_color(ui_Screen1_Label8, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Screen1_Label8, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Screen1_Label8, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Screen1_Label9 = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Screen1_Label9, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Screen1_Label9, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Screen1_Label9, 285 );
lv_obj_set_y( ui_Screen1_Label9, 152 );
lv_obj_set_align( ui_Screen1_Label9, LV_ALIGN_CENTER );
lv_label_set_text(ui_Screen1_Label9,"SOG");
lv_obj_set_style_text_color(ui_Screen1_Label9, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Screen1_Label9, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Screen1_Label9, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Screen1_Label10 = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Screen1_Label10, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Screen1_Label10, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Screen1_Label10, 199 );
lv_obj_set_y( ui_Screen1_Label10, 178 );
lv_obj_set_align( ui_Screen1_Label10, LV_ALIGN_CENTER );
lv_label_set_text(ui_Screen1_Label10,"o");
lv_obj_set_style_text_align(ui_Screen1_Label10, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Screen1_Label10, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Screen1_Label11 = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Screen1_Label11, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Screen1_Label11, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Screen1_Label11, 342 );
lv_obj_set_y( ui_Screen1_Label11, 207 );
lv_obj_set_align( ui_Screen1_Label11, LV_ALIGN_CENTER );
lv_label_set_text(ui_Screen1_Label11,"kt");
lv_obj_set_style_text_color(ui_Screen1_Label11, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Screen1_Label11, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Screen1_Label11, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_lbEngineRPM = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_lbEngineRPM, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_lbEngineRPM, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_lbEngineRPM, -103 );
lv_obj_set_y( ui_lbEngineRPM, 83 );
lv_obj_set_align( ui_lbEngineRPM, LV_ALIGN_RIGHT_MID );
lv_label_set_text(ui_lbEngineRPM,"2356");
lv_obj_set_style_text_align(ui_lbEngineRPM, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_decor(ui_lbEngineRPM, LV_TEXT_DECOR_NONE, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_lbEngineRPM, &lv_font_montserrat_48, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_lbAltVolt = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_lbAltVolt, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_lbAltVolt, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_lbAltVolt, -77 );
lv_obj_set_y( ui_lbAltVolt, -28 );
lv_obj_set_align( ui_lbAltVolt, LV_ALIGN_RIGHT_MID );
lv_label_set_text(ui_lbAltVolt,"12.8");
lv_obj_set_style_text_align(ui_lbAltVolt, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_decor(ui_lbAltVolt, LV_TEXT_DECOR_NONE, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_lbAltVolt, &lv_font_montserrat_48, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Screen1_Label12 = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Screen1_Label12, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Screen1_Label12, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Screen1_Label12, 323 );
lv_obj_set_y( ui_Screen1_Label12, 91 );
lv_obj_set_align( ui_Screen1_Label12, LV_ALIGN_CENTER );
lv_label_set_text(ui_Screen1_Label12,"RPM");
lv_obj_set_style_text_color(ui_Screen1_Label12, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Screen1_Label12, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Screen1_Label12, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Screen1_Label13 = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Screen1_Label13, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Screen1_Label13, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Screen1_Label13, 335 );
lv_obj_set_y( ui_Screen1_Label13, -21 );
lv_obj_set_align( ui_Screen1_Label13, LV_ALIGN_CENTER );
lv_label_set_text(ui_Screen1_Label13,"V");
lv_obj_set_style_text_color(ui_Screen1_Label13, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Screen1_Label13, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Screen1_Label13, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Screen1_Label14 = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Screen1_Label14, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Screen1_Label14, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Screen1_Label14, 273 );
lv_obj_set_y( ui_Screen1_Label14, -74 );
lv_obj_set_align( ui_Screen1_Label14, LV_ALIGN_CENTER );
lv_label_set_text(ui_Screen1_Label14,"Alternator Voltage");
lv_obj_set_style_text_color(ui_Screen1_Label14, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Screen1_Label14, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Screen1_Label14, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Screen1_Label15 = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Screen1_Label15, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Screen1_Label15, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Screen1_Label15, 280 );
lv_obj_set_y( ui_Screen1_Label15, 43 );
lv_obj_set_align( ui_Screen1_Label15, LV_ALIGN_CENTER );
lv_label_set_text(ui_Screen1_Label15,"Engine Speed");
lv_obj_set_style_text_color(ui_Screen1_Label15, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Screen1_Label15, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Screen1_Label15, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

}

void ui_init( void )
{
lv_disp_t *dispp = lv_disp_get_default();
lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
lv_disp_set_theme(dispp, theme);
ui_Screen1_screen_init();
lv_disp_load_scr( ui_Screen1);
}
