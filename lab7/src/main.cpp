#include <Arduino.h>
#include <ESP8266WiFi.h>
//#include <WiFiClient.h>
#include <ESP8266WebServer.h>

//ssid กับ password ของ wifi ที่จะเชื่อมต่อ
const char* ssid = "FL_12345WIFI_2.4G";
const char* password = "19116691129";

//ssid password กับ ip address ของ wifi ที่จะสร้าง
const char* ssid_E = "MY-wifi";
const char* password_E = "12345678";
IPAddress local_ip(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

//HTML code
const String HtmlHtml = "<html><head>"
    "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\" /></head>";
const String HtmlHtmlClose = "</html>";
const String HtmlTitle = "<h1>ESP8266 WebServer control</h1><br/>\n";
const String HtmlCenter = "<center>";
const String HtmlCloseCenter = "</center>";
const String HtmlButton_ON = "<a href=\"Off\"><button style=\"display: block; background-color: #00FF00;  height: 50px; width: 100px;\">ON</button></a><br/>";
const String HtmlButton_OFF = "<a href=\"On\"><button style=\"display: block; background-color: #FF0000; height: 50px; width: 100px;\">OFF</button></a><br/>";

String myState, myButtons;

void handleRoot(){
	digitalWrite(2, LOW);
	Serial.print("READY");
	myState = "<big>LED is now <b>OFF</b></big><br/>\n";
	myButton = HtmlButton_OFF;
	response();
}

void handleOn(){
	digitalWrite(2, HIGH);
	Serial.print("ON");
	myState = "<big>LED is now <b>ON</b></big><br/>\n";
	myButton = HtmlButton_ON;
	response();
}

void handleOff(){
	digitalWrite(2, LOW);
	Serial.print("OFF");
	myState = "<big>LED is now <b>ON</b></big><br/>\n";
	myButton = HtmlButton_OFF;
	response();
}

void response(){
  String myTEXT = HtmlHtml + HtmlCenter;
	
  myTEXT += HtmlTitle;
  myTEXT += myState;
  myTEXT += myButtons;
  myTEXT += HtmlCloseCenter;
  myTEXT += HtmlHtmlClose;
	
  server.send (200, "text/html", myTEXT);

}

ESP8266WebServer server(80);

int cnt = 0;

void setup(){
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
			server.send(404, "text/html", "Path Not Found");
		});

                server.on("/", handleRoot);
                server.on("/on", handleOn);
                server.on("/off", handleOff);

                server.begin();
                Serial.println("HTTP server started");
        } else {
                Serial.println("NOW!!...ERROR...");
                Serial.begin(115200);

                WiFi.softAP(ssid_E, password_E);
                WiFi.softAPConfig(local_ip, gateway, subnet);
                delay(100);

                server.onNotFound([]() {
                        server.send(404, "text/html", "Path Not Found");
                });

                server.on("/", []() {
                        digitalWrite(2, HIGH);
                        delay(3 * 1000);
                        digitalWrite(2, LOW);
                        delay(3 * 1000);
                        server.send(200, "text/html", "MY-wifi");
                });

                server.begin();
                Serial.println("HTTP server started");      
        }
}

void loop(){
	server.handleClient();
	
}
