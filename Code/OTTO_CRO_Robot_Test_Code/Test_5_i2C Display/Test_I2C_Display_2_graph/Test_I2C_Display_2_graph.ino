//  Only OTTO_CRO_v.1.1/v.1.2
// 7.4.2025.
/** Info
https://github.com/mkfrey/u8g2-hal-esp-idf
https://lonelybinary.com/blogs/learn/oled-0-96#:~:text=Open%20sidebar,OLED

 **/
//  Include necessary headers:
#include <Arduino.h>
#include <U8g2lib.h>
// #include <SPI.h> // If using SPI
#include <Wire.h> // If using I2C
#include "bitmap.h" // <-- RENAME THIS to match the generated code's filename suggestion


// OLED TEXT ROW number, vertical position
const byte ROW[5] = {0, 15, 31, 47, 63};

// Configure the HAL for your display: spi.

      //#define PIN_MOSI  23 // Example: Replace with your actual MOSI pin
      //#define PIN_SCK   18 // Example: Replace with your actual SCK pin
      //#define PIN_CS    3  // Example: Replace with your actual CS pin
      //#define PIN_DC    4    // Example: Replace with your actual DC pin
      //#define PIN_RESET -1  // Example: Replace with your actual reset pin

      // U8G2_SSD1306_128X64_NONAME_F_4W_SW_SPI u8g2(U8G2_R0, PIN_SCK, PIN_MOSI, PIN_CS, PIN_DC, PIN_RESET);
     
      // for OTTO CRO with ESP32S3  SDA = GPIO 11 , SCL = GPIO 12
      #define SDA_PIN 11 // Example: Replace with your actual SDA pin
      #define SCL_PIN 12 // Example: Replace with your actual SCL pin

      U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL_PIN, /* data=*/ SDA_PIN);

      // Initialize the display in setup(): 
  void setup() {
   u8g2.begin();
   u8g2.setFlipMode(0); // Optional: Adjust display orientation
   // for Debug
   Serial.begin(115200);
   Serial.println("u8g2 started");  
}

// Use the u8g2 object in loop(): 

   void loop() {
     u8g2.clearBuffer();          // Clear the internal memory
     //u8g2.setFont(u8g2_font_ncenB08_tr); // Choose a font
      u8g2.setFont(u8g2_font_ncenB08_tr);
     u8g2.drawStr(10,10,"OTTO CRO Robot"); // Draw some text
      u8g2.drawStr(15, 50, "Demo Code");
     u8g2.sendBuffer();           // Transfer data to the display
     delay(1000);                 // Display for 1 second
      u8g2.clearBuffer(); // clear the internal memory
 
  // Draw the bitmap at position (0, 0)
  // u8g2.drawXBMP(x_pos, y_pos, bitmap_width, bitmap_height, bitmap_data);
  // Use the width and height mentioned in the generated code comments.
  u8g2.drawXBMP(0, 0, 128, 64, majica_bitmap); // <-- Use the array name from generated code
  Serial.println("Code working!");
  u8g2.sendBuffer(); // transfer internal memory to the display
  delay(5000); 
   }