#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

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

int testScreen(String command);

void setup()   {                
    Serial.begin(9600);

    Spark.function("display", displayText);

  pinMode(D7, OUTPUT);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC);
  
  // init done
  
  display.clearDisplay();

  display.setTextSize(1.5);
  display.setTextColor(WHITE);
  display.println("Spruce");
  display.display();
  delay(2000);

  
}

int displayText(String command)
{

    display.clearDisplay();
    display.setCursor(0,0);
    display.println(command);
    display.display();

    delay(2000);

    digitalWrite(D7, HIGH);

    delay(2000);

    digitalWrite(D7, LOW);

    delay(2000);

  return 1;

}

void loop() {
      
//
//    digitalWrite(D7, (isVibrating) ? HIGH : LOW);
//    isVibrating = !isVibrating;
//    delay(2500);
    
}