/*********************************************************************
This is an example for our Monochrome OLEDs based on SSD1306 drivers

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/category/63_98

This example is for a 128x64 size display using SPI to communicate
4 or 5 pins are required to interface

Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries.  
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution
*********************************************************************/

#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include "Spark-Websockets.h"

WebSocketClient client;

// If using software SPI (the default case):
#define OLED_MOSI   D0
#define OLED_CLK    D1
#define OLED_DC     D2
#define OLED_CS     D3
#define OLED_RESET  D4
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif



int isVibrating = 0;

void setup()   {                
    Serial.begin(9600);
  
    //while(!Serial.available()); // Wait here until the user presses ENTER in the Serial Terminal

    //client.onMessage(onMessage);
    client.connect("https://appointments.spruce.me");
  
  pinMode(D7, OUTPUT);
  
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC);
  
  // init done
  
  display.clearDisplay();
  
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.println("Spruce!");
  display.display();
  delay(2000);
  
}

void loop() {
      
    // client.monitor();
    // delay(3000);
    // client.send("Hello World!");
      
    //digitalWrite(D7, (isVibrating) ? HIGH : LOW);
    //isVibrating = !isVibrating;
    //delay(2500);
    
}

// void onMessage(WebSocketClient client, char* message) {
//   Serial.print("Received: ");
//   Serial.println(message);
// }
