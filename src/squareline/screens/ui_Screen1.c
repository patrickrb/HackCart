// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_Screen1_screen_init(void)
{
ui_Screen1 = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Screen1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Image1 = lv_img_create(ui_Screen1);
lv_img_set_src(ui_Image1, &ui_img_background_png);
lv_obj_set_width( ui_Image1, LV_SIZE_CONTENT);  /// 480
lv_obj_set_height( ui_Image1, LV_SIZE_CONTENT);   /// 320
lv_obj_set_align( ui_Image1, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image1, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Image2 = lv_img_create(ui_Screen1);
lv_img_set_src(ui_Image2, &ui_img_middle_circles_png);
lv_obj_set_width( ui_Image2, LV_SIZE_CONTENT);  /// 569
lv_obj_set_height( ui_Image2, LV_SIZE_CONTENT);   /// 320
lv_obj_set_align( ui_Image2, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image2, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Image3 = lv_img_create(ui_Screen1);
lv_img_set_src(ui_Image3, &ui_img_right_empty_gauge_png);
lv_obj_set_width( ui_Image3, LV_SIZE_CONTENT);  /// 569
lv_obj_set_height( ui_Image3, LV_SIZE_CONTENT);   /// 320
lv_obj_set_align( ui_Image3, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image3, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image3, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Slider2 = lv_slider_create(ui_Screen1);
lv_slider_set_value( ui_Slider2, 50, LV_ANIM_OFF);
if (lv_slider_get_mode(ui_Slider2)==LV_SLIDER_MODE_RANGE ) lv_slider_set_left_value( ui_Slider2, 0, LV_ANIM_OFF);
lv_obj_set_width( ui_Slider2, 150);
lv_obj_set_height( ui_Slider2, 160);
lv_obj_set_x( ui_Slider2, 74 );
lv_obj_set_y( ui_Slider2, 1 );
lv_obj_set_align( ui_Slider2, LV_ALIGN_CENTER );
lv_obj_set_style_bg_color(ui_Slider2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Slider2, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_Slider2, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Slider2, 0, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_Slider2, &ui_img_right_full_gauge_png, LV_PART_INDICATOR | LV_STATE_DEFAULT );

lv_obj_set_style_bg_color(ui_Slider2, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Slider2, 0, LV_PART_KNOB| LV_STATE_DEFAULT);

ui_BatteryPercentage = lv_obj_create(ui_Screen1);
lv_obj_set_width( ui_BatteryPercentage, 55);
lv_obj_set_height( ui_BatteryPercentage, 33);
lv_obj_set_x( ui_BatteryPercentage, 114 );
lv_obj_set_y( ui_BatteryPercentage, -55 );
lv_obj_set_align( ui_BatteryPercentage, LV_ALIGN_CENTER );
lv_obj_set_flex_flow(ui_BatteryPercentage,LV_FLEX_FLOW_ROW);
lv_obj_set_flex_align(ui_BatteryPercentage, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
lv_obj_clear_flag( ui_BatteryPercentage, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_BatteryPercentage, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_BatteryPercentage, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_BatteryPercentage, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_batteryint = lv_label_create(ui_BatteryPercentage);
lv_obj_set_width( ui_batteryint, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_batteryint, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_batteryint, 121 );
lv_obj_set_y( ui_batteryint, -54 );
lv_obj_set_align( ui_batteryint, LV_ALIGN_CENTER );
lv_label_set_text(ui_batteryint,"100");
lv_obj_set_style_text_color(ui_batteryint, lv_color_hex(0xEEEEEE), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_batteryint, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_batteryint, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label2 = lv_label_create(ui_BatteryPercentage);
lv_obj_set_width( ui_Label2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label2, 100 );
lv_obj_set_y( ui_Label2, -42 );
lv_obj_set_align( ui_Label2, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label2,"%");
lv_obj_set_style_text_color(ui_Label2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label2, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_SpeedArc = lv_arc_create(ui_Screen1);
lv_obj_set_width( ui_SpeedArc, 150);
lv_obj_set_height( ui_SpeedArc, 150);
lv_obj_set_x( ui_SpeedArc, 2 );
lv_obj_set_y( ui_SpeedArc, 1 );
lv_obj_set_align( ui_SpeedArc, LV_ALIGN_CENTER );
lv_arc_set_value(ui_SpeedArc, 20);
lv_arc_set_bg_angles(ui_SpeedArc,0,900);
lv_arc_set_rotation(ui_SpeedArc,70);
lv_obj_set_style_bg_color(ui_SpeedArc, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_SpeedArc, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_arc_color(ui_SpeedArc, lv_color_hex(0x4040FF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_arc_opa(ui_SpeedArc, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_arc_width(ui_SpeedArc, 10, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_arc_img_src( ui_SpeedArc, &ui_img_speed_gauge_png, LV_PART_INDICATOR | LV_STATE_DEFAULT );

lv_obj_set_style_bg_color(ui_SpeedArc, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_SpeedArc, 0, LV_PART_KNOB| LV_STATE_DEFAULT);

ui_Image4 = lv_img_create(ui_Screen1);
lv_img_set_src(ui_Image4, &ui_img_left_empty_gauge_png);
lv_obj_set_width( ui_Image4, LV_SIZE_CONTENT);  /// 569
lv_obj_set_height( ui_Image4, LV_SIZE_CONTENT);   /// 320
lv_obj_set_align( ui_Image4, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image4, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image4, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_TempSlider = lv_slider_create(ui_Screen1);
lv_slider_set_range(ui_TempSlider, -10,115);
lv_obj_set_width( ui_TempSlider, 214);
lv_obj_set_height( ui_TempSlider, 219);
lv_obj_set_align( ui_TempSlider, LV_ALIGN_CENTER );
lv_obj_set_style_bg_color(ui_TempSlider, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_TempSlider, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_TempSlider, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_TempSlider, 0, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_TempSlider, &ui_img_left_full_gauge_png, LV_PART_INDICATOR | LV_STATE_DEFAULT );

lv_obj_set_style_bg_color(ui_TempSlider, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_TempSlider, 0, LV_PART_KNOB| LV_STATE_DEFAULT);

ui_TempLabel = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_TempLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_TempLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_TempLabel, -110 );
lv_obj_set_y( ui_TempLabel, -13 );
lv_obj_set_align( ui_TempLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_TempLabel,"100");
lv_obj_set_style_text_color(ui_TempLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_TempLabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_TempLabel, &lv_font_montserrat_10, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_SpeedLabel = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_SpeedLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_SpeedLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_SpeedLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_SpeedLabel,"21");
lv_obj_set_style_text_color(ui_SpeedLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_SpeedLabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_SpeedLabel, &lv_font_montserrat_34, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label3 = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Label3, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label3, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label3, -1 );
lv_obj_set_y( ui_Label3, 22 );
lv_obj_set_align( ui_Label3, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label3,"MPH");
lv_obj_set_style_text_color(ui_Label3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label3, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

}
