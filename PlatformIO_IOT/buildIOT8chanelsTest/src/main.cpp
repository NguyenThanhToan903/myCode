#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

const char *ssid = "4Cs Coffee";
const char *password = "4csxinchao";

bool ledState[] = {0, 0};
const int LED_PIN[] = {13, 2};

#define index 0

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

    giá trị<p>%TEMP%</p>
    <p><button id="button">%STATE%</button></p>
</body>
</html>
)rawliteral";

void notifyClient()
{
  ws.textAll(String(ledState[index]));
}

String processor(const String &s)
{
  Serial.println(s);
  if (s == "TEMP")
  {
    if (ledState[index] == 1)
    {
      return "ON";
    }
    else
    {
      return "OFF";
    }
  }
  return String();
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

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/html", index_html, processor); });

  server.begin();
}

void loop()
{
  digitalWrite(LED_PIN[index], ledState[index]);
}