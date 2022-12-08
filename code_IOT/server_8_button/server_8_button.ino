#include <WiFi.h>
#include <EEPROM.h>

#define EEPROM_SIZE 8

const char* ssid = "Relative";
const char* password = "1234123412";

WiFiServer server(80);

String header;

int output26State = 0;
int output25State = 0;
int output17State = 0;
int output16State = 0;
int output27State = 0;
int output4State = 0;
int output2State = 0;
int output13State = 0;


const int output26 = 26;
const int output25 = 25;
const int output17 = 17;
const int output16 = 16;
const int output27 = 27;
const int output4 = 4;  //14 = 1 là mach reboot lien tục
const int output2 = 2;  //12 = 1 là mach klong khoi dong dc hoặc ko nap duoc code => tranh su dung
const int output13 = 13;

unsigned long currentTime = millis();

unsigned long previousTime = 0;
const long timeoutTime = 2000;

void setup(){

  Serial.begin(115200);
  EEPROM.begin(EEPROM_SIZE);

    pinMode(output26, OUTPUT);
    pinMode(output25, OUTPUT);
    pinMode(output17, OUTPUT);
    pinMode(output16, OUTPUT);
    pinMode(output27, OUTPUT);
    pinMode(output4, OUTPUT);
    pinMode(output2, OUTPUT);
    pinMode(output13, OUTPUT);
    
    output26State = EEPROM.read(0);
    output25State = EEPROM.read(1);
    output17State = EEPROM.read(2);
    output16State = EEPROM.read(3);
    output27State = EEPROM.read(4);
    output4State = EEPROM.read(5);
    output2State = EEPROM.read(6);
    output13State = EEPROM.read(7);

    digitalWrite(output26, LOW);
    digitalWrite(output25, LOW);
    digitalWrite(output17, LOW);
    digitalWrite(output16, LOW);
    digitalWrite(output27, LOW);
    digitalWrite(output4, LOW);
    digitalWrite(output2, LOW);
    digitalWrite(output13, LOW);

    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(5000);
      Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println(WiFi.localIP());
    server.begin();
}

void loop(){
  WiFiClient maychu = server.available();
  if(maychu) {
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");
    String currentLine = "";
    while (maychu.connected() && currentTime - previousTime <= timeoutTime) {
      currentTime = millis();
      if (maychu.available()) {
        char c = maychu.read();
        Serial.write(c);
        header += c;
        if (c == '\n') {
          if(currentLine.length() == 0) {
            maychu.println("HTTP/1.1 200 OK");
            maychu.println("Connect-type:text/html");
            maychu.println("Connection: close");
            maychu.println();



            if (header.indexOf("GET /26/on") >= 0) {
                Serial.println("GPIO 26 on");
                output26State = 1;
                digitalWrite(output26, HIGH);
              } else if (header.indexOf("GET /26/off") >= 0) {
                Serial.println("GPIO 26 off");
                output26State = 0;
                digitalWrite(output26, LOW);
              } else if (header.indexOf("GET /25/on") >= 0) {
                Serial.println("GPIO 25 on");
                output25State = 1;
                digitalWrite(output25, HIGH);
              } else if (header.indexOf("GET /25/off") >= 0) {
                Serial.println("GPIO 25 off");
                output25State = 0;
                digitalWrite(output25, LOW);
              } else if (header.indexOf("GET /17/on") >= 0) {
                Serial.println("GPIO 17 on");
                output17State = 1;
                digitalWrite(output17, HIGH);
              } else if (header.indexOf("GET /17/off") >= 0) {
                Serial.println("GPIO 17 off");
                output17State = 0;
                digitalWrite(output17, LOW);
              } else if (header.indexOf("GET /16/on") >= 0) {
                Serial.println("GPIO 16 on");
                output16State = 1;
                digitalWrite(output16, HIGH);
              } else if (header.indexOf("GET /16/off") >= 0) {
                Serial.println("GPIO 16 off");
                output16State = 0;
                digitalWrite(output16, LOW);
              } else if (header.indexOf("GET /27/on") >= 0) {
                Serial.println("GPIO 27 on");
                output27State = 1;
                digitalWrite(output27, HIGH);
              } else if (header.indexOf("GET /27/off") >= 0) {
                Serial.println("GPIO 27 off");
                output27State = 0;
                digitalWrite(output27, LOW);
              } else if (header.indexOf("GET /14/on") >= 0) {
                Serial.println("GPIO 4 on");
                output4State = 1;
                digitalWrite(output4, HIGH);
              } else if (header.indexOf("GET /14/off") >= 0) {
                Serial.println("GPIO 4 off");
                output4State = 0;
                digitalWrite(output4, LOW);
              } else if (header.indexOf("GET /12/on") >= 0) {
                Serial.println("GPIO 2 on");
                output2State = 1;
                digitalWrite(output2, HIGH);
              } else if (header.indexOf("GET /12/off") >= 0) {
                Serial.println("GPIO 2 off");
                output2State = 0;
                digitalWrite(output2, LOW);
              } else if (header.indexOf("GET /13/on") >= 0) {
                Serial.println("GPIO 13 on");
                output13State = 1;
                digitalWrite(output13, HIGH);
              } else if (header.indexOf("GET /13/off") >= 0) {
                Serial.println("GPIO 13 off");
                output13State = 0;
                digitalWrite(output13, LOW);
              }
              maychu.println("<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n<meta charset=\"UTF-8\">\n<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">");
              maychu.println("\n<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n<title>ESP32</title>\n<style>");
              maychu.println("html {\nfont-family: Helvetica;\ndisplay: inline-block;\nmargin: 0px auto;\ntext-align: center;\nfont-size: medium;\n/* display: flexbox; */\n}");
              maychu.println("\n.button {\nbackground-color: rgb(156, 20, 20);\nborder: none;\ncolor: white;\npadding: 30px 120px;\nfont-size: 30px;\nmargin: 0px 2px;\ncursor: pointer;");
              maychu.println("\ndisplay: block;\nbox-sizing:content-box;\nborder-radius: 10px;\n-webkit-transition-duration: 0.5s;\ntransition-duration: 0.5s;\n}");
              maychu.println("\n.button:hover{\nbox-shadow: 0 12px 16px 0 rgba(0,0,0,0.24), 0 17px 50px 0 rgba(0,0,0,0.19);\n}");
              maychu.println("\n.off {\nbackground-color: rgb(85, 85, 85);\n}");
              maychu.println("\n.content {\nmargin: auto;\ndisplay: flex;\nflex-wrap: wrap;\nflex-direction: row;\njustify-content: center;\n}");
              maychu.println("\n.column{\nmargin: 0px 50px;\n}\n.box{\npadding: 10px 10px 1px 10px;\nborder-radius: 12px;\nmargin: 50px 0px;");
              maychu.println("\nwidth: 300px;\nheight: auto;\nbackground-color: aquamarine;\n}\n.box a{\n    text-decoration: none;\n}");
              maychu.println("\n.grey{\nbackground-color: rgba(148, 148, 148, 0.3);\n}\n</style>\n</head>");
              maychu.println("\n<body>\n<div class=\"header\">\n<h1>ESP32 Web Server</h1>\n</div>\n<div class=\"content\">\n<div class=\"column\">");
              
              if (output26State == 0 ) {
                maychu.println("\n<div class=\"box grey\"><p>GPIO 26 - State off</p>\n<p><a href=\"/26/on\"><button class=\"button\">ON</button></a></p></div>");
              } else {
                maychu.println("\n<div class=\"box grey\"><p>GPIO 26 - State on</p>\n<p><a href=\"/26/off\"><button class=\"button off\">OFF</button></a></p></div>");
              } 
              if (output25State == 0 ) {
                maychu.println("\n<div class=\"box grey\"><p>GPIO 25 - State off</p>\n<p><a href=\"/25/on\"><button class=\"button\">ON</button></a></p></div>");
              } else {
                maychu.println("\n<div class=\"box grey\"><p>GPIO 25 - State on</p>\n<p><a href=\"/25/off\"><button class=\"button off\">OFF</button></a></p></div>");
              } 
              if (output17State == 0 ) {
                maychu.println("\n<div class=\"box grey\"><p>GPIO 17 - State off</p>\n<p><a href=\"/17/on\"><button class=\"button\">ON</button></a></p></div>");
              } else {
                maychu.println("\n<div class=\"box grey\"><p>GPIO 17 - State on</p>\n<p><a href=\"/17/off\"><button class=\"button off\">OFF</button></a></p></div>");
              } 
              if (output16State == 0 ) {
                maychu.println("\n<div class=\"box grey\"><p>GPIO 16 - State off</p>\n<p><a href=\"/16/on\"><button class=\"button\">ON</button></a></p></div>");
              } else {
                maychu.println("\n<div class=\"box grey\"><p>GPIO 16 - State on</p>\n<p><a href=\"/16/off\"><button class=\"button off\">OFF</button></a></p></div>");
              }
              maychu.println("\n</div><div class=\"column\">");
              if (output27State == 0 ) {
                maychu.println("\n<div class=\"box grey\"><p>GPIO 27 - State off</p>\n<p><a href=\"/27/on\"><button class=\"button\">ON</button></a></p></div>");
              } else {
                maychu.println("\n<div class=\"box grey\"><p>GPIO 27 - State on</p>\n<p><a href=\"/27/off\"><button class=\"button off\">OFF</button></a></p></div>");
              } 
              if (output4State == 0 ) {
                maychu.println("\n<div class=\"box grey\"><p>GPIO 4 - State off</p>\n<p><a href=\"/14/on\"><button class=\"button\">ON</button></a></p></div>");
              } else {
              maychu.println("\n<div class=\"box grey\"><p>GPIO 4 - State on</p>\n<p><a href=\"/14/off\"><button class=\"button off\">OFF</button></a></p></div>");
              } 
              if (output2State == 0 ) {
                maychu.println("\n<div class=\"box grey\"><p>GPIO 2 - State off</p>\n<p><a href=\"/12/on\"><button class=\"button\">ON</button></a></p></div>");
              } else {
                maychu.println("\n<div class=\"box grey\"><p>GPIO 2 - State on</p>\n<p><a href=\"/12/off\"><button class=\"button off\">OFF</button></a></p></div>");
              } 
              if (output13State == 0 ) {
                maychu.println("\n<div class=\"box grey\"><p>GPIO 13 - State off</p>\n<p><a href=\"/13/on\"><button class=\"button\">ON</button></a></p></div>");
              } else {
                maychu.println("\n<div class=\"box grey\"><p>GPIO 13 - State oN</p>\n<p><a href=\"/13/off\"><button class=\"button off\">OFF</button></a></p></div>");
              } 

              maychu.println("\n        </div>\n</div>\n</body>\n</html>");
              maychu.println();
              break;
          }
          else 
          {
            currentLine = "";
          }
        }
        else if (c != '\r') {
          currentLine += c;
        }
      }
    }
    header = "";
    EEPROM.commit();
    maychu.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
