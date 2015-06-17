#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include "WebServer.h"

#define PREFIX ""
WebServer webserver(PREFIX, 80);

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

void helloCmd(WebServer &server, WebServer::ConnectionType type, char *, bool)
{
  /* this line sends the standard "we're all OK" headers back to the
     browser */
  server.httpSuccess();

  /* if we're handling a GET or POST, we can output our data here.
     For a HEAD request, we just stop after outputting headers. */
  if (type != WebServer::HEAD)
  {
    /* this defines some HTML text in read-only memory aka PROGMEM.
     * This is needed to avoid having the string copied to our limited
     * amount of RAM. */
    P(helloMsg) = "<h1>Hello, World!</h1>";

    /* this is a special form of print that outputs from PROGMEM */
    server.printP(helloMsg);
  }
}

void setup()   {                
    Serial.begin(9600);

  pinMode(D7, OUTPUT);
  
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC);
  
  // init done
  
  display.clearDisplay();

  display.setTextSize(1.5);
  display.setTextColor(WHITE);
  display.println("Shoe Request");
  display.println("Type: Para Black");
  display.println("Size: 10 1/2");
  display.println("Qty: 2");
  display.display();
  delay(2000);

   /* setup our default command that will be run when the user accesses
     * the root page on the server */
    webserver.setDefaultCommand(&helloCmd);

    /* run the same command if you try to load /index.html, a common
     * default page name */
    webserver.addCommand("index.html", &helloCmd);

    /* start the webserver */
    webserver.begin();
  
}

void loop() {
      
//
//    digitalWrite(D7, (isVibrating) ? HIGH : LOW);
//    isVibrating = !isVibrating;
//    delay(2500);

     char buff[64];
      int len = 64;

      /* process incoming connections one at a time forever */
      webserver.processConnection(buff, &len);
    
}