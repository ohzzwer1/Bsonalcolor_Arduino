#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>

#define REDPIN    21
#define GREENPIN  22
#define BLUEPIN   23

const char* ssid = "yubini";
const char* name = "2115888";
const char* password = "mgybsh129864";

AsyncWebServer server(80);
String processor(const String& var){
  return String();
}

void setup(){
  Serial.begin(115200);

  SPIFFS.begin();
  
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/main.html", String(), false, processor);
  });

  server.on("/main.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/main.css", "text/css");
  });

  server.on("/index.html", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });

  server.on("/count_page.html", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/count_page.html", String(), false, processor);
  });

  server.on("/green.html", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/green.html", String(), false, processor);
  });

  server.on("/pink.html", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/pink.html", String(), false, processor);
  });

  server.on("/purple.html", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/purple.html", String(), false, processor);
  });

  server.on("/blue.html", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/blue.html", String(), false, processor);
  });

  server.on("/yellow.html", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/yellow.html", String(), false, processor);
  });

  server.on("/red.html", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/red.html", String(), false, processor);
  });

  server.on("/white.html", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/white.html", String(), false, processor);
  });

  server.on("/orange.html", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/orange.html", String(), false, processor);
  });
  
  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/style.css", "text/css");
  });

  server.on("/result.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/result.css", "text/css");
  });

  server.on("/result.html", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/result.html", String(), false, processor);

    int R, G, B;
    String color;    
    
    if (request->hasParam("color")) {
      color = request->getParam("color")->value();
      if (color=="red") {
          R = 255;
          G = 0;
          B = 0;
      }
      if (color=="orange") {
          R = 255;
          G = 50;
          B = 0;
      }
      if (color=="yellow") {
          R = 255;
          G = 165;
          B = 0;
      }
      if (color=="green") {
          R = 0;
          G = 128;
          B = 0;
      }
      if (color=="blue") {
          R = 30;
          G = 144;
          B = 255;
      }
      if (color=="purple") {
          R = 148;
          G = 0;
          B = 211;
      }
      if (color=="pink") {
          R = 255;
          G = 20;
          B = 100;
      }
      if (color=="white") {
          R = 256;
          G = 200;
          B = 150;
      } 

    }
    analogWrite(REDPIN, R);
    analogWrite(GREENPIN, G);
    analogWrite(BLUEPIN, B);
  });

  server.begin();
}

void loop(){
  
}
