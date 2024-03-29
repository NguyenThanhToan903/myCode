#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

const char *ssid = "4Cs caffee";
const char *password = "4csxinchao";

bool ledState[] = {0, 0};
const int LED_PIN[] = {13, 2};

int index = 0;

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

const char index_html[] PROGMEM = R"rawliteral(
    <!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>esp32-websocket-server</title>
</head>
<body>
    Hello
</body>
</html>
)rawliteral";

void notifyClient()
{
    ws.textAll(String(ledState[index]));
}

void setup()
{
    Serial.begin(115200);

    pinMode(LED_PIN[index], OUTPUT);
    digitalWrite(LED_PIN[index], LOW);
    pinMode(LED_PIN[index + 1], OUTPUT);
    digitalWrite(LED_PIN[index + 1], LOW);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.println("Connecting to WiFi..");
    }

    Serial.println(WiFi.localIP());

    server.begin();
}

void loop()
{
    digitalWrite(LED_PIN[index], ledState[index]);
}