// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library
// Add booton code

const int buttonPin = 1;  // the number of the pushbutton pin
// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the ESP32S3 is connected to the NeoPixels?
 #define PIN        38 // Only OTTO_CRO_v.1.1
//#define PIN        21 // Only OTTO_CRO_v.1.2

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 6 // Popular NeoPixel ring size


// Set up some hex colours:
const long RED    = 0xFF0000;
const long ORANGE = 0xFF8800;
const long YELLOW = 0xFFFF00;
const long GREEN  = 0x00FF00;
const long BLUE   = 0x0000FF;
const long PURPLE = 0xFF00FF;

// Put the colours in an array:
const long RAINBOW[6] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};
//int index = 0;

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

void setup() {
   // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  pixels.clear(); // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
  pixels.clear(); // Set all pixel colors to 'off'
    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:

    // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  //if (buttonState == HIGH) {
    // 
    //pixels.setPixelColor(i, pixels.Color(0, 150, 0));
  //} else {
    // 
    //pixels.setPixelColor(i, pixels.Color(230, 30, 16));
  //}
  pixels.setPixelColor(i, RAINBOW[i]);

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop
  }
}
