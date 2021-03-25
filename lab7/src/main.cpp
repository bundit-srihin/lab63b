#include <Arduino.h>
#include <ESP8266WiFi.h>
//#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "FL_12345WIFI_2.4G";
const char* password = "19116691129";

const char* ssidR = "MY-wifi";
const char* passwordR = "12345678";

IPAddress local_ip(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

ESP8266WebServer server(80);

int cnt = 0;

void setup(void){
        Serial.begin(115200);

        pinMode(0, INPUT);
        pinMode(2, OUTPUT);
        Serial.println("\n\n\n");

        int val = digitalRead(0);
        Serial.printf("======= read %d\n", val);
  
        if(val==1) {
                  WiFi.mode(WIFI_STA);
                  WiFi.begin(ssid, password);
                  while (WiFi.status() != WL_CONNECTED) {
                          delay(500);
                          Serial.print(".");
                  }
                  Serial.print("\n\nIP address: ");
                  Serial.println(WiFi.localIP());

                  server.onNotFound([]() {
                          server.send(404, "text/plain", "Path Not Found");
                  });

                  server.on("/on", []() {
                          digitalWrite(2, HIGH);
                          server.send(200, “text/plain”, “LED on”);
                  });

                  server.on("/off", []() {
                          digitalWrite(2, LOW);
                          server.send(200, “text/plain”, “LED off”);
                  });

                  server.on("/on-off", []() {
                          digitalWrite(2, HIGH);
                          delay(3 * 1000);
                          digitalWrite(2, LOW);
                          delay(3 * 1000);
                          digitalWrite(2, HIGH);
                          delay(3 * 1000);
                          server.send(200, “text/plain”, “LED on-off”);
                  });

                  server.begin();
                  Serial.println("HTTP server started");
        } else {
                  Serial.println("NOW!!...ERROR...");
                  Serial.begin(115200);

                  WiFi.softAP(ssid, password);
                  WiFi.softAPConfig(local_ip, gateway, subnet);
                  delay(100);

                  server.onNotFound([]() {
                          server.send(404, "text/plain", "Path Not Found");
                  });

                  server.on("/", []() {
                          digitalWrite(2, HIGH);
                          delay(5 * 1000);
                          digitalWrite(2, LOW);
                          delay(5 * 1000);
                          digitalWrite(2, HIGH);
                          delay(5 * 1000);
                          server.send(200, "text/plain", "MY-wifi");
                  });

                  server.begin();
                  Serial.println("HTTP server started");
	                }
	                Serial.println("\n\n");
                  
        }
}

void loop(void){
  server.handleClient();
	
}
