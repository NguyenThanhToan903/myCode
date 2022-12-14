#include <WiFi.h>
#include <SPIFFS.h>
#include <ESPAsyncWebServer.h>

const char* ssid = "Relative"
const char* password = "1234123412"

const int LEDPIN = 2;

String ledState;

AsyncWebServer server(80);
