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

void onMessage(WebSocketClient client, char* message) {
  Serial.print("Received: ");
  Serial.println(message);
}

int isVibrating = 0;

void setup()   {                
    Serial.begin(9600);

    client.onMessage(onMessage);
    client.connect("https://appointments.spruce.me"); 
  //client.connect("appointments.spruce.me", 443, 'https'); 
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
      
    client.monitor();
    delay(3000);
    client.send("Hello World!");
      
    //digitalWrite(D7, (isVibrating) ? HIGH : LOW);
    //isVibrating = !isVibrating;
    //delay(2500);
    
}

void onMessage(WebSocketClient client, char* message) {
  Serial.print("Received: ");
  Serial.println(message);
}
