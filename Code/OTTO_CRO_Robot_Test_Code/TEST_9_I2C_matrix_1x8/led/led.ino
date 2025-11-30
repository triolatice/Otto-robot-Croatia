/*
This is a library for our I2C LED Backpacks with OTTO 1.2 

*/

/*************************************************** 
  This is a library for our I2C LED Backpacks
https://github.com/adafruit/Adafruit_LED_Backpack/tree/master/examples
https://xantorohara.github.io/led-matrix-editor
  Designed specifically to work with the Adafruit LED Matrix backpacks 
  ----> http://www.adafruit.com/products/872
  ----> http://www.adafruit.com/products/871
  ----> http://www.adafruit.com/products/870

  These displays use I2C to communicate, 2 pins are required to 
  interface. There are multiple selectable I2C addresses. For backpacks
  with 2 Address Select pins: 0x70, 0x71, 0x72 or 0x73. For backpacks
  with 3 Address Select pins: 0x70 thru 0x77

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/
/* LETERS
A_bmp[] =
{
  0b00000000,
  0b00111100,
  0b01100110,
  0b01100110,
  0b01111110,
  0b01100110,
  0b01100110,
  0b01100110
},
B_bmp[] =
{
  0b00000000,
  0b01111100,
  0b01100110,
  0b01100110,
  0b01111100,
  0b01100110,
  0b01100110,
  0b01111100
},
C_bmp[] =
{
  0b00000000,
  0b00111100,
  0b01100110,
  0b01100000,
  0b01100000,
  0b01100000,
  0b01100110,
  0b00111100
},
D_bmp[] =
{
  0b00000000,
  0b01111100,
  0b01100110,
  0b01100110,
  0b01100110,
  0b01100110,
  0b01100110,
  0b01111100
},
E_bmp[] =
{
  0b00000000,
  0b01111110,
  0b01100000,
  0b01100000,
  0b01111100,
  0b01100000,
  0b01100000,
  0b01111110
},
F_bmp[] =
{
  0b00000000,
  0b01111110,
  0b01100000,
  0b01100000,
  0b01111100,
  0b01100000,
  0b01100000,
  0b01100000
},
G_bmp[] =
{
  0b00000000,
  0b00111100,
  0b01100110,
  0b01100000,
  0b01100000,
  0b01101110,
  0b01100110,
  0b00111100
},
H_bmp[] =
{
  0b00000000,
  0b01100110,
  0b01100110,
  0b01100110,
  0b01111110,
  0b01100110,
  0b01100110,
  0b01100110
},
I_bmp[] =
{
  0b00000000,
  0b00111100,
  0b00011000,
  0b00011000,
  0b00011000,
  0b00011000,
  0b00011000,
  0b00111100
},
J_bmp[] =
{
  0b00000000,
  0b00011110,
  0b00001100,
  0b00001100,
  0b00001100,
  0b01101100,
  0b01101100,
  0b00111000
},
K_bmp[] =
{
  0b00000000,
  0b01100110,
  0b01101100,
  0b01111000,
  0b01110000,
  0b01111000,
  0b01101100,
  0b01100110
},
L_bmp[] =
{
  0b00000000,
  0b01100000,
  0b01100000,
  0b01100000,
  0b01100000,
  0b01100000,
  0b01100000,
  0b01111110
},
M_bmp[] =
{
  0b00000000,
  0b01100011,
  0b01110111,
  0b01111111,
  0b01101011,
  0b01100011,
  0b01100011,
  0b01100011
},
N_bmp[] =
{
  0b00000000,
  0b01100011,
  0b01110011,
  0b01111011,
  0b01101111,
  0b01100111,
  0b01100011,
  0b01100011
},
O_bmp[] =
{
  0b00000000,
  0b00111100,
  0b01100110,
  0b01100110,
  0b01100110,
  0b01100110,
  0b01100110,
  0b00111100
},
P_bmp[] =
{
  0b00000000,
  0b01111100,
  0b01100110,
  0b01100110,
  0b01100110,
  0b01111100,
  0b01100000,
  0b01100000
},
Q_bmp[] =
{
  0b00000000,
  0b00111100,
  0b01100110,
  0b01100110,
  0b01100110,
  0b01101110,
  0b00111100,
  0b00000110
},
R_bmp[] =
{
  0b00000000,
  0b01111100,
  0b01100110,
  0b01100110,
  0b01111100,
  0b01111000,
  0b01101100,
  0b01100110
},
S_bmp[] =
{
  0b00000000,
  0b00111100,
  0b01100110,
  0b01100000,
  0b00111100,
  0b00000110,
  0b01100110,
  0b00111100
},
T_bmp[] =
{
  0b00000000,
  0b01111110,
  0b01011010,
  0b00011000,
  0b00011000,
  0b00011000,
  0b00011000,
  0b00011000
},
U_bmp[] =
{
  0b00000000,
  0b01100110,
  0b01100110,
  0b01100110,
  0b01100110,
  0b01100110,
  0b01100110,
  0b00111110
},
V_bmp[] =
{
  0b00000000,
  0b01100110,
  0b01100110,
  0b01100110,
  0b01100110,
  0b01100110,
  0b00111100,
  0b00011000
},
W_bmp[] =
{
  0b00000000,
  0b01100011,
  0b01100011,
  0b01100011,
  0b01101011,
  0b01111111,
  0b01110111,
  0b01100011
},
X_bmp[] =
{
  0b00000000,
  0b01100011,
  0b01100011,
  0b00110110,
  0b00011100,
  0b00110110,
  0b01100011,
  0b01100011
},
Y_bmp[] =
{
  0b00000000,
  0b01100110,
  0b01100110,
  0b01100110,
  0b00111100,
  0b00011000,
  0b00011000,
  0b00011000
},
Z_bmp[] =
{
  0b00000000,
  0b01111110,
  0b00000110,
  0b00001100,
  0b00011000,
  0b00110000,
  0b01100000,
  0b01111110
},
space_bmp[] =
{
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000
},
a_bmp[] =
{
  0b00000000,
  0b00000000,
  0b00000000,
  0b00111100,
  0b00000110,
  0b00111110,
  0b01100110,
  0b00111110
},
b_bmp[] =
{
  0b00000000,
  0b01100000,
  0b01100000,
  0b01100000,
  0b01111100,
  0b01100110,
  0b01100110,
  0b01111100
},
c_bmp[] =
{
  0b00000000,
  0b00000000,
  0b00000000,
  0b00111100,
  0b01100110,
  0b01100000,
  0b01100110,
  0b00111100
},
d_bmp[] =
{
  0b00000000,
  0b00000110,
  0b00000110,
  0b00000110,
  0b00111110,
  0b01100110,
  0b01100110,
  0b00111110
},
e_bmp[] =
{
  0b00000000,
  0b00000000,
  0b00000000,
  0b00111100,
  0b01100110,
  0b01111110,
  0b01100000,
  0b00111100
},
f_bmp[] =
{
  0b00000000,
  0b00011100,
  0b00110110,
  0b00110000,
  0b00110000,
  0b01111100,
  0b00110000,
  0b00110000
},
g_bmp[] =
{
  0b00000000,
  0b00000000,
  0b00111110,
  0b01100110,
  0b01100110,
  0b00111110,
  0b00000110,
  0b00111100
},
h_bmp[] =
{
  0b00000000,
  0b01100000,
  0b01100000,
  0b01100000,
  0b01111100,
  0b01100110,
  0b01100110,
  0b01100110
},
i_bmp[] =
{
  0b00000000,
  0b00000000,
  0b00011000,
  0b00000000,
  0b00011000,
  0b00011000,
  0b00011000,
  0b00111100
},
j_bmp[] =
{
  0b00000000,
  0b00001100,
  0b00000000,
  0b00001100,
  0b00001100,
  0b01101100,
  0b01101100,
  0b00111000
},
k_bmp[] =
{
  0b00000000,
  0b01100000,
  0b01100000,
  0b01100110,
  0b01101100,
  0b01111000,
  0b01101100,
  0b01100110
},
l_bmp[] =
{
  0b00000000,
  0b00011000,
  0b00011000,
  0b00011000,
  0b00011000,
  0b00011000,
  0b00011000,
  0b00011000
},
m_bmp[] =
{
  0b00000000,
  0b00000000,
  0b00000000,
  0b01100011,
  0b01110111,
  0b01111111,
  0b01101011,
  0b01101011
},
n_bmp[] =
{
  0b00000000,
  0b00000000,
  0b00000000,
  0b01111100,
  0b01111110,
  0b01100110,
  0b01100110,
  0b01100110
},
o_bmp[] =
{
  0b00000000,
  0b00000000,
  0b00000000,
  0b00111100,
  0b01100110,
  0b01100110,
  0b01100110,
  0b00111100
},
p_bmp[] =
{
  0b00000000,
  0b00000000,
  0b01111100,
  0b01100110,
  0b01100110,
  0b01111100,
  0b01100000,
  0b01100000
},
q_bmp[] =
{
  0b00000000,
  0b00000000,
  0b00111100,
  0b01101100,
  0b01101100,
  0b00111100,
  0b00001101,
  0b00001111
},
r_bmp[] =
{
  0b00000000,
  0b00000000,
  0b00000000,
  0b01111100,
  0b01100110,
  0b01100110,
  0b01100000,
  0b01100000
},
s_bmp[] =
{
  0b00000000,
  0b00000000,
  0b00000000,
  0b00111110,
  0b01000000,
  0b00111100,
  0b00000010,
  0b01111100
},
t_bmp[] =
{
  0b00000000,
  0b00000000,
  0b00011000,
  0b00011000,
  0b01111110,
  0b00011000,
  0b00011000,
  0b00011000
},
u_bmp[] =
{
  0b00000000,
  0b00000000,
  0b00000000,
  0b01100110,
  0b01100110,
  0b01100110,
  0b01100110,
  0b00111110
},
v_bmp[] =
{
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b01100110,
  0b01100110,
  0b00111100,
  0b00011000
},
w_bmp[] =
{
  0b00000000,
  0b00000000,
  0b00000000,
  0b01100011,
  0b01101011,
  0b01101011,
  0b01101011,
  0b00111110
},
x_bmp[] =
{
  0b00000000,
  0b00000000,
  0b00000000,
  0b01100110,
  0b00111100,
  0b00011000,
  0b00111100,
  0b01100110
},
y_bmp[] =
{
  0b00000000,
  0b00000000,
  0b00000000,
  0b01100110,
  0b01100110,
  0b00111110,
  0b00000110,
  0b00111100
},
z_bmp[] =
{
  0b00000000,
  0b00000000,
  0b00000000,
  0b00111100,
  0b00001100,
  0b00011000,
  0b00110000,
  0b00111100
  },
 // *?????
  č_bmp[] =
  {
  0b00000000,
  0b00000000,
  0b00000000,
  0b00111100,
  0b00001100,
  0b00011000,
  0b00110000,
  0b00111100
},
 // *?????
ć_bmp[] =
{
  0b00000000,
  0b00000000,
  0b00000000,
  0b00111100,
  0b00001100,
  0b00011000,
  0b00110000,
  0b00111100

down_bmp[] =
{
  0b00111000,
  0b00111000,
  0b00111000,
  0b00111000,
  0b11111110,
  0b01111100,
  0b00111000,
  0b00010000
},
right_bmp[] =
{
  0b00001000,
  0b00001100,
  0b11111110,
  0b11111111,
  0b11111110,
  0b00001100,
  0b00001000,
  0b00000000
},
up_bmp[] =
{
  0b00010000,
  0b00111000,
  0b01111100,
  0b11111110,
  0b00111000,
  0b00111000,
  0b00111000,
  0b00111000
},
left_bmp[] =
{
  0b00010000,
  0b00110000,
  0b01111111,
  0b11111111,
  0b01111111,
  0b00110000,
  0b00010000,
  0b00000000
}};

*/
/*

*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

void setup() {
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");
    Wire.begin(11,12); // ADD this line code  for OTTO v11.1. , v1.2
  matrix.begin(0x70);  // pass in the address
}

static const uint8_t PROGMEM
 
  // add 

  right_bmp[] =
{
  0b00001000,
  0b00001100,
  0b11111110,
  0b11111111,
  0b11111110,
  0b00001100,
  0b00001000,
  0b00000000 },

up_bmp[] =
{
  0b00010000,
  0b00111000,
  0b01111100,
  0b11111110,
  0b00111000,
  0b00111000,
  0b00111000,
  0b00111000 },

left_bmp[] =
{
  0b00010000,
  0b00110000,
  0b01111111,
  0b11111111,
  0b01111111,
  0b00110000,
  0b00010000,
  0b00000000 },

 down_bmp[] =
{
  0b00111000,
  0b00111000,
  0b00111000,
  0b00111000,
  0b11111110,
  0b01111100,
  0b00111000,
  0b00010000 }, 

crtice_bmp[] =
  {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B11000000,
  B00000000,
  B00000000,
  B00000000 },
  //
 smile_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100 },
  neutral_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10111101,
    B10000001,
    B01000010,
    B00111100 },
  frown_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10011001,
    B10100101,
    B01000010,
    B00111100 };

void loop() {

  matrix.clear();
  matrix.drawBitmap(0, 0, down_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(1000);

  matrix.clear();
  matrix.drawBitmap(0, 0, right_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(1000);

  matrix.clear();
  matrix.drawBitmap(0, 0, up_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(1000);

  matrix.clear();
  matrix.drawBitmap(0, 0, left_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(1000);

  matrix.clear();
  matrix.drawBitmap(0, 0, neutral_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(100);
  // drugi pouta 
  matrix.clear();
  matrix.drawBitmap(0, 0, down_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(1000);

  matrix.clear();
  matrix.drawBitmap(0, 0, right_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(1000);

  matrix.clear();
  matrix.drawBitmap(0, 0, up_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(1000);

  matrix.clear();
  matrix.drawBitmap(0, 0, left_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(1000);

  matrix.clear();
  matrix.drawBitmap(0, 0, neutral_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(100);
  

  matrix.clear();
  matrix.drawBitmap(0, 0, crtice_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(1000);

  matrix.clear();
  matrix.drawBitmap(0, 0, smile_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(100);

  matrix.clear();
  matrix.drawBitmap(0, 0, neutral_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(100);

  matrix.clear();
  matrix.drawBitmap(0, 0, frown_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(100);
// Custom ADD OTTO CRO



// End custom add
  matrix.clear();      // clear display
  matrix.drawPixel(0, 0, LED_ON);  
  matrix.writeDisplay();  // write the changes we just made to the display
  delay(500);

  matrix.clear();
  matrix.drawLine(0,0, 7,7, LED_ON);
  matrix.writeDisplay();  // write the changes we just made to the display
  delay(500);

  matrix.clear();
  matrix.drawRect(0,0, 8,8, LED_ON);
  matrix.fillRect(2,2, 4,4, LED_ON);
  matrix.writeDisplay();  // write the changes we just made to the display
  delay(500);

  matrix.clear();
  matrix.drawCircle(3,3, 3, LED_ON);
  matrix.writeDisplay();  // write the changes we just made to the display
  delay(500);

  matrix.setTextSize(1);
  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix.setTextColor(LED_ON);
  for (int8_t x=0; x>=-36; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print("Hello");
    matrix.writeDisplay();
    delay(100);
  }
  matrix.setRotation(3);
  for (int8_t x=7; x>=-36; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print("World");
    matrix.writeDisplay();
    delay(100);
  }
  matrix.setRotation(0);
}