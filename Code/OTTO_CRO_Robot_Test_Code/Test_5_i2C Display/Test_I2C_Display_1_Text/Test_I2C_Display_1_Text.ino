//  Only OTTO_CRO_v.1.1/v.1.2
// 7.4.2025.
/** Info
https://github.com/mkfrey/u8g2-hal-esp-idf

 **/
//  Include necessary headers:
#include <Arduino.h>
#include <U8g2lib.h>
// #include <SPI.h> // If using SPI
#include <Wire.h> // If using I2C

// Configure the HAL for your display: spi.

      #define PIN_MOSI  23 // Example: Replace with your actual MOSI pin
      #define PIN_SCK   18 // Example: Replace with your actual SCK pin
      #define PIN_CS    3  // Example: Replace with your actual CS pin
      #define PIN_DC    4    // Example: Replace with your actual DC pin
      #define PIN_RESET -1  // Example: Replace with your actual reset pin

      // U8G2_SSD1306_128X64_NONAME_F_4W_SW_SPI u8g2(U8G2_R0, PIN_SCK, PIN_MOSI, PIN_CS, PIN_DC, PIN_RESET);
     
      // for OTTO CRO with ESP32S3  SDA = GPIO 11 , SCL = GPIO 12
      #define SDA_PIN 11 // Example: Replace with your actual SDA pin
      #define SCL_PIN 12 // Example: Replace with your actual SCL pin
      //ovo radi na Arduino uno
  U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL_PIN, /* data=*/ SDA_PIN);
// Eksperiment 
//U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0, /* clock=*/ SCL_PIN, /* data=*/ SDA_PIN); 
      // Initialize the display in setup(): 
  void setup() {
   u8g2.begin();
   u8g2.setFlipMode(0); // Optional: Adjust display orientation
}

// Use the u8g2 object in loop(): 

   void loop() {
     u8g2.clearBuffer();          // Clear the internal memory
     //u8g2.setFont(u8g2_font_ncenB08_tr); // Choose a font
     //u8g2.setFont(u8g2_font_profont11_mf); // Choose a font
     u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
     u8g2.drawStr(10,50,"OTTO Robot v.1.2 !"); // Draw some text
     u8g2.sendBuffer();           // Transfer data to the display
     delay(1000);                 // Display for 1 second
   }