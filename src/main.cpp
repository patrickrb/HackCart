#include <Arduino.h>
#include <lvgl.h>
#define LGFX_USE_V1
#include <LovyanGFX.hpp>
#include "FT6236.h"
#include <Wire.h>
#include <Ticker.h>
Ticker ticker1;

#define BUZZER_PIN 20

const int i2c_touch_addr = TOUCH_I2C_ADD;

// The Squareline Interface Code
#include "ui.h"
#include "ui_helpers.h"

// Pins for the LCD Backlight and TouchScreen
#define LCD_BL 46
#define SDA_FT6236 38
#define SCL_FT6236 39

unsigned long previousMillis = 0; // Will store the last time the slider value was updated
const long interval = 100;        // interval at which to update the slider value (milliseconds)

int sliderValue = 1;
int speedValue = 0;
int tempValue = 0;
bool incrementingBattery = true;
bool incrementingSpeed = true;
bool incrementingTemp = true;

class LGFX : public lgfx::LGFX_Device
{
  lgfx::Panel_ILI9488 _panel_instance;
  lgfx::Bus_Parallel16 _bus_instance;
  lgfx::Touch_FT5x06 _touch_instance;

public:
  LGFX(void)
  {
    {
      auto cfg = _bus_instance.config();
      cfg.port = 0;
      cfg.freq_write = 80000000;
      cfg.pin_wr = 18;
      cfg.pin_rd = 48;
      cfg.pin_rs = 45;

      cfg.pin_d0 = 47;
      cfg.pin_d1 = 21;
      cfg.pin_d2 = 14;
      cfg.pin_d3 = 13;
      cfg.pin_d4 = 12;
      cfg.pin_d5 = 11;
      cfg.pin_d6 = 10;
      cfg.pin_d7 = 9;
      cfg.pin_d8 = 3;
      cfg.pin_d9 = 8;
      cfg.pin_d10 = 16;
      cfg.pin_d11 = 15;
      cfg.pin_d12 = 7;
      cfg.pin_d13 = 6;
      cfg.pin_d14 = 5;
      cfg.pin_d15 = 4;

      _bus_instance.config(cfg);
      _panel_instance.setBus(&_bus_instance);
    }

    {
      auto cfg = _panel_instance.config();

      cfg.pin_cs = -1;
      cfg.pin_rst = -1;
      cfg.pin_busy = -1;
      cfg.memory_width = 320;
      cfg.memory_height = 480;
      cfg.panel_width = 320;
      cfg.panel_height = 480;
      cfg.offset_x = 0;
      cfg.offset_y = 0;
      cfg.offset_rotation = 0;
      cfg.dummy_read_pixel = 8;
      cfg.dummy_read_bits = 1;
      cfg.readable = true;
      cfg.invert = false;
      cfg.rgb_order = false;
      cfg.dlen_16bit = true;
      cfg.bus_shared = true;

      _panel_instance.config(cfg);
    }
    {
      auto cfg = _touch_instance.config();

      cfg.x_min = 0;
      cfg.x_max = 319;
      cfg.y_min = 0;
      cfg.y_max = 479;
      cfg.pin_int = -1;
      cfg.bus_shared = false;
      cfg.offset_rotation = 0;

      cfg.i2c_port = 1;
      cfg.i2c_addr = 0x38;
      cfg.pin_sda = 38;
      cfg.pin_scl = 39;
      cfg.freq = 400000;

      _touch_instance.config(cfg);
      _panel_instance.setTouch(&_touch_instance);
    }

    setPanel(&_panel_instance);
  }
};

LGFX tft;

/*Change to your screen resolution*/
static const uint16_t screenWidth = 480;
static const uint16_t screenHeight = 320;

lv_color_t buf_display[screenWidth * screenHeight / 8];
lv_color_t buf_render[screenWidth * screenHeight / 8];
bool buffer_swap = false;

/* Display flushing */
lv_disp_draw_buf_t draw_buf;

void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
  if (buffer_swap)
  {
    lv_color_t *buf = buf_render; // Use the rendering buffer
    memcpy(buf_render, buf_display, screenWidth * screenHeight / 8 * sizeof(lv_color_t));
    memcpy(buf_display, buf, screenWidth * screenHeight / 8 * sizeof(lv_color_t));

    buffer_swap = false;
  }

  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  tft.startWrite();
  tft.setAddrWindow(area->x1, area->y1, w, h);
  tft.writePixels((lgfx::rgb565_t *)&color_p->full, w * h);
  tft.endWrite();

  lv_disp_flush_ready(disp);
}

/*Read the touchpad*/
void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
  uint16_t touchX, touchY;

  bool touched = tft.getTouch(&touchX, &touchY);

  if (touchX > screenWidth || touchY > screenHeight)
  {
    Serial.println("Y or y outside of expected parameters..");
  }
  else
  {
    data->state = touched ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL;
    data->point.x = touchX;
    data->point.y = touchY;
  }
}

void touch_init()
{
  // I2C init
  Wire.begin(SDA_FT6236, SCL_FT6236);
  byte error, address;

  Wire.beginTransmission(i2c_touch_addr);
  error = Wire.endTransmission();

  if (error == 0)
  {
    Serial.print("I2C device found at address 0x");
    Serial.print(i2c_touch_addr, HEX);
    Serial.println("  !");
  }
  else if (error == 4)
  {
    Serial.print("Unknown error at address 0x");
    Serial.println(i2c_touch_addr, HEX);
  }
}

const int speedInterval = 60;
const int SPEED_INCREMENT = 1;
const int MAX_SPEED = 35;
const int MIN_SPEED = 0;

void updateSpeed()
{
  if (incrementingSpeed)
  {
    speedValue += SPEED_INCREMENT;
    if (speedValue >= MAX_SPEED)
    {
      incrementingSpeed = false;
    }
  }
  else
  {
    speedValue -= SPEED_INCREMENT;
    if (speedValue <= MIN_SPEED)
    {
      incrementingSpeed = true;
    }
  }
  lv_arc_set_value(ui_SpeedArc, speedValue);
  lv_label_set_text_fmt(ui_SpeedLabel, "%d", speedValue);
}

void lvgl_loop(void *parameter)
{
  while (true)
  {

    updateSpeed();
    if (incrementingTemp)
    {
      tempValue += 1;
      if (tempValue >= 105)
      {
        incrementingTemp = false;
      }
    }
    else
    {
      tempValue -= 1;
      if (tempValue <= 0)
      {
        incrementingTemp = true;
      }
    }
    lv_slider_set_value(ui_TempSlider, tempValue, LV_ANIM_OFF);
    lv_label_set_text_fmt(ui_TempLabel, "%d", tempValue);

    if (incrementingBattery)
    {
      sliderValue++;
      if (sliderValue >= 99)
      {
        incrementingBattery = false;
      }
    }
    else
    {
      sliderValue--;
      if (sliderValue <= 1)
      {
        incrementingBattery = true;
      }
    }
    lv_slider_set_value(ui_Slider2, sliderValue, LV_ANIM_OFF);
    lv_label_set_text_fmt(ui_batteryint, "%d", sliderValue);
    lv_timer_handler();

    buffer_swap = true; // Set the flag to swap buffers
  }
  vTaskDelete(NULL);
}

void guiHandler()
{
  xTaskCreatePinnedToCore(
      lvgl_loop,   // Function that should be called
      "LVGL Loop", // Name of the task (for debugging)
      20480,       // Stack size (bytes)
      NULL,        // Parameter to pass
      1,           // Task priority
      NULL,        // Task handle
      1);
}

void setup()
{
  Serial.begin(115200); /* prepare for possible serial debug */
  // Buzzer
  // pinMode(BUZZER_PIN, OUTPUT);
  // ledcSetup(4, 5000, 8);
  // ledcAttachPin(BUZZER_PIN, 4);

  tft.begin();        /* TFT init */
  tft.setRotation(1); /* Landscape orientation, flipped */

  delay(500);
  pinMode(LCD_BL, OUTPUT);
  digitalWrite(LCD_BL, HIGH); // Set to maximum brightness

  touch_init();

  lv_init();
  lv_disp_draw_buf_init(&draw_buf, buf_display, NULL, screenWidth * screenHeight / 8);

  /*Initialize the display*/
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  /*Change the following line to your display resolution*/
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);

  /*Initialize the (dummy) input device driver*/
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register(&indev_drv);

  ui_init();
  guiHandler();
}

void loop()
{
  // unsigned long currentMillis = millis();

  // // Calculate the time elapsed since the last update
  // unsigned long timeElapsed = currentMillis - previousMillis;

  // // Update speed based on elapsed time
  // while (timeElapsed >= speedInterval)
  // {
  //   timeElapsed -= speedInterval;
  //   previousMillis += speedInterval;
  // }
}
