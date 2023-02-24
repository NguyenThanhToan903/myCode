#include <ESPAsyncWebServer.h>
#include <WebSocketsServer.h>

// Khởi tạo đối tượng ESPAsyncWebServer
AsyncWebServer server(80);

// Khai báo biến cho các relay
int relay1 = 2;
int relay2 = 3;
int relay3 = 4;
int relay4 = 5;
int relay5 = 6;
int relay6 = 7;

// Callback function khi nhận được websocket message
void onWebSocketEvent(uint8_t client_num, WStype_t type, uint8_t *payload, size_t length)
{
  if (type == WStype_TEXT)
  {
    // Chuyển đổi message nhận được từ string sang số nguyên
    int value = atoi((char *)payload);

    // Kiểm tra relay nào được điều khiển
    if (client_num == 0)
    {
      digitalWrite(relay1, value);
    }
    else if (client_num == 1)
    {
      digitalWrite(relay2, value);
    }
    else if (client_num == 2)
    {
      digitalWrite(relay3, value);
    }
    else if (client_num == 3)
    {
      digitalWrite(relay4, value);
    }
    else if (client_num == 4)
    {
      digitalWrite(relay5, value);
    }
    else if (client_num == 5)
    {
      digitalWrite(relay6, value);
    }
  }
}

void setup()
{
  // Khởi tạo các relay
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(relay5, OUTPUT);
  pinMode(relay6, OUTPUT);

  // Cấu hình đường dẫn và callback cho các trang web
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/index.html"); });
  server.on("/styles.css", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/styles.css", "text/css"); });
  server.on("/script.js", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/script.js", "application/javascript"); });

  // Khởi tạo đối tượng WebSocketsServer
  WebSocketsServer webSocket
