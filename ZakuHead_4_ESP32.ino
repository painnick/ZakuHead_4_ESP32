/*********
  Rui Santos
  Complete instructions at https://RandomNerdTutorials.com/esp32-cam-projects-ebook/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files.
  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
*********/

#define USE_SERIAL_DEBUG

#include "Arduino.h"
#include "soc/soc.h"             // disable brownout problems
#include "soc/rtc_cntl_reg.h"    // disable brownout problems

#include "zaku_leds.h"
#include "zaku_servo.h"

void initCameraServer();
void startCameraServer();

void setup() {
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); //disable brownout detector

  #ifdef USE_SERIAL_DEBUG
  Serial.begin(115200);
  Serial.setDebugOutput(false);
  #endif

  zakuServo.setup();

  mono_eye_leds.red(4);
  mono_eye_leds.orange(2);
  
  initCameraServer();
  startCameraServer();
}

void loop() {
  
}
