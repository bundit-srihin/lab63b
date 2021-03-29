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
  * [โปรมแกรม 07](https://github.com/bundit-srihin/lab63b/blob/main/lab7/src/main.cpp)
  * [ภาษาของการเขียนโปรแกรมใช้งานArduino Board](https://arduinothing.blogspot.com/2016/04/arduino-cc.html)
  * [Choompol Boonmee](https://github.com/choompol-boonmee/lab63b.git)
  * [คำสั่ง ESP8266](https://links2004.github.io/Arduino/annotated.html)
  * [การควบคุมผ่านทาง Web Server](https://sites.google.com/site/eplearn/wifi/control_via_web_server)
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
  10. ทดสอบโดยการเข้า IP Adress ที่แสดงออกมา 
  11. ลองกดปุ่มที่มีให้ และสังเกตที่หลอด LED กับ URL
  12. ทำการ นำสายสีขาวที่ต่อออกมาจาก Adapter ต่อเข้าที่สายดำ แล้วทำการทดลอง 7-11 ใหม่อีกครั้ง
  13. นำสายสีขาวออก แล้วกดปุ่มดำค้างแทนทำการมดลอง 7-11 ใหม่อีกครั้ง 
  14. ลองทำการเปลี่ยน HTML 

## อภิปรายการทดลอง 
