# การทดลองที่ 7 เรื่อง การพัฒนาการเขียนโปรแกรมเพื่อรันบนไมโครคอนโทรเลอร์  
## วัตถุประสงค์
  * เพื่อพัฒนาความรู้ความเข้าใจในการเขียนโปรแกรมลงบนไมโครคอนโทรเลอร์
  * เพื่อเป็นการนำความรู้ที่ได้รับมาพัฒนาโปรแกรม
  * เพื่อเพิ่มความคิดสร้างสรรค์ในการเขียนโปรแกรม
  * เพื่อการลองผิดลองถูกในการโปรแกรมไมโครคอนโทรเลอร์
## อุปกรณ์ที่ใช้ 
  1. บอร์ด ESP_01
  2. สายต่อ USB
  3. ตัวแปลง USB to Serial Port 
  4. Adapter ต่อ Serial Port กับสายพ่วง และตัวหนีบ
  5. หลอด LED
## ศึกษาข้อมูลเบื้องต้น
  * [ESP_01 PlatformIO](https://docs.platformio.org/en/latest/boards/espressif8266/esp01.html)
  * [คลิปอธิบายการทดลอง]()
  * [Code 07](https://github.com/bundit-srihin/lab63b/blob/main/lab7/src/main.cpp)
  * [ภาษาของการเขียนโปรแกรมใช้งานArduino Board](https://arduinothing.blogspot.com/2016/04/arduino-cc.html)
  * [Choompol Boonmee ตัวอย่างการทดลอง](https://github.com/choompol-boonmee/lab63b.git)
  * [คำสั่ง ESP8266](https://links2004.github.io/Arduino/annotated.html)
  * [การควบคุมผ่านทาง Web Server](https://sites.google.com/site/eplearn/wifi/control_via_web_server)
## Code ที่ใช้ในการทดลอง
```
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
```
## วิธีการทำการทดลอง
  1. ทำการดาวน์โหลดตัวโปรแกรม โดยใช้คำสั่ง `git clone` แล้วตามด้วย `https://github.com/bundit-srihin/lab63b.git`
```
git clone https://github.com/bundit-srihin/lab63b.git
```
  2. ทำการต่อสาย USB เข้ากับ ตัวแปลง USB to Serial Port
  3. ทำการต่อตัว Adapter เข้ากับ Serial Port
  4. ทำการต่อ ESP_01 เข้ากับ Serial Port ของ Adapter
  5. เปิดโฟลเดอร์ที่ทำการในที่นี้คือ `cd lab63b` แล้วก็ `cd lab7`
  6. แล้วทำการอัปโหลดโปรแกรมเข้าสู่ไมโครคอนโทรเลอร์ด้วยคำสั่ง `pio run -t upload`
  7. เพื่อให้ทำการอัปโหลดได้ กด port 0 (ปุ่มดำ) ค้างไว้ แลัวกดปุ่ม reset
  8. ทำการแสดงผลที่ไมโครคอนโทรเลอร์แสดงโดยใช้คำสั่ง `pio device monitor`
  9. ลองทำการกดปุ่ม reset 
  10. ทดสอบโดยการเข้า IP Address ที่แสดงออกมา 
  11. ลองกดปุ่มที่มีให้ และสังเกตที่หลอด LED กับ URL
  12. ทำการ นำสายสีขาวที่ต่อออกมาจาก Adapter ต่อเข้าที่สายดำ แล้วทำการทดลอง 7-11 ใหม่อีกครั้ง
  13. นำสายสีขาวออก แล้วกดปุ่มดำค้างแทนทำการมดลอง 7-11 ใหม่อีกครั้ง 
  14. ลองทำการเปลี่ยน HTML code ในบรรทัดที่ 21 หรือ
```
const String HtmlTitle = "<h1>ESP8266 WebServer control</h1><br/>\n";
```
![html code](https://user-images.githubusercontent.com/80879119/113110768-a721e000-9231-11eb-9d68-eaf1401a091e.png)

เป็นดังนี้
```
const String HtmlTitle = "<h2>ESP8266 WebServer control</h2><br/>\n";
```
(เปลี่ยนในส่วนของ h1 เป็น h2 h3 ... h6) ทำการทดลอง 6-11 ใหม่อีกครั้ง
## อภิปรายการทดลอง 
 ในการทดลองผลที่ออกมาจะมีการแบ่งออกเป็นสองแบบใหญ่ๆ คือมีอินพุทเข้าที่ port 0 หรือไม่มีอินพุทเข้า
  * เมื่อไม่มีอินพุทเข้า : จะมีการแสดง read 1 จะผ่านเงื่อนไข if val == 1มีการสร้างเว็บเซฟเวอร์ขึ้น แล้วจะแสดง IP Address นำไปค้นหาในเว็บเบาเซอร์ จะมีการแสดงข้อความออกมาตามเขียนโค้ดเอาไว้ และจะมีปุ่มให้กดทดลองการปิดเปิด LED ผ่านเว็บเซฟเวอร์ที่ทำไว้
  * เมื่อมีการอินพุทเข้า : ในการทดลองนี้จะแสดงเหมือนเป็นการที่เรามีการค้นพบ error แล้วทำการอินพุทเข้าที่ port 0 read 0 ทำให้ไม่เป็นไปตามเงื่อนไขของ if จึงไปรันคำสั่งภายใน else ทำให้เกิดการสร้าง wifi ตาม ssid password และ IP Adress ที่ตั้งเอาไว้
