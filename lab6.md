# การทดลองที่ 6 เรื่อง การเขียนโปรแกรมสร้างไวไฟแอคเซสพอยต์(Wifi AP)
## วัตถุประสงค์ 
  * เพื่อศึกษาการสร้างไวไฟ โดยใช้ไมโครคอนโทรเลอร์เป็นตัวปล่อยสัญญาณ Wifi
## อุปกรณ์ที่ใช้ 
  1. บอร์ด ESP_01
  2. สายต่อ USB
  3. ตัวแปลง USB to Serial Port 
## ศึกษาข้อมูลเบื้องต้น 
  * [ESP_01 PlatformIO](https://docs.platformio.org/en/latest/boards/espressif8266/esp01.html)
  * [ตัวอย่างการทดลอง LAB 6](https://youtu.be/T26DVHePlTs)
  * [โปรแกรม 06](https://github.com/bundit-srihin/lab63b/blob/main/examples/06_Wifi-AP-Web-Server/src/main.cpp)
## วิธีการทำการทดลอง 
  1. ทำการกำหนดชื่อ Wifi และ Password
![S__12099631](https://user-images.githubusercontent.com/80879119/112002962-06596380-8b53-11eb-9ab6-823e75a89dc1.jpg)
  2. กำหนด IP Address ต่างๆ 
  3. ทำการต่อสาย USB เข้ากับ ตัวแปลงเป็น Serial Port เพื่อต่อเข้ากับ ESP_01
  4. นำ ESP_01 ต่อเข้ากับ Serial Port
  5. เปิดโปรแกรมที่จะทำการรัน เข้าโฟลเดอร์ที่บันทึกเอาไว้ `cd pattani` แล้ว `cd 06_Wifi-AP-Web-Server`
  6. รันคำสั่ง `pio run -t upload`
![S__12099633](https://user-images.githubusercontent.com/80879119/112003003-1113f880-8b53-11eb-87f8-2c4063b454fa.jpg)
  7. กดปุ่มดำค้างไว้แล้วกดปุ่ม Reset เพื่อให้ ESP_01 รับโปรแกรม
![S__12099634](https://user-images.githubusercontent.com/80879119/112003059-1f621480-8b53-11eb-9b4a-e81e2d24ed12.jpg)
  8. รันคำสั่ง `pio device monitor` เพื่อดูผลที่แสดงผลออกมา
![S__12099635](https://user-images.githubusercontent.com/80879119/112003103-2be66d00-8b53-11eb-940f-3eb65e9f5b13.jpg)
  9. ลองกดปุ่ม reset 
![S__12099636](https://user-images.githubusercontent.com/80879119/112003136-37399880-8b53-11eb-9083-68e759fae320.jpg)
  10. เพื่อทดสอบใช้ โทรศัพท์ลองค้นหา Wifi ตามชื่อที่ตั้งไว้
![S__12099637](https://user-images.githubusercontent.com/80879119/112003198-43255a80-8b53-11eb-8c2b-0ffadefff915.jpg)
## การบันทึกผลการทดลอง 
 จะเกิดไวไฟตามชื่อและรหัสที่ตั้งไว้
![S__12099637](https://user-images.githubusercontent.com/80879119/112003198-43255a80-8b53-11eb-8c2b-0ffadefff915.jpg)
## อภิปรายผลการทดลอง 
 คอนโทรเลอร์จะทำการปล่อยสัญญาณไวไฟ โดยที่อุปกรณ์อื่นจับสัญญาณได้
## คำถามหลังการทดลอง 
 ในตัวโปรแกรมของการทดลอง `softAP` สำหรับ ESP_01 คืออะไร (ตอบในลักษณะของโหมดการทำงาน)???
 * [Ans](https://github.com/bundit-srihin/lab63b/blob/main/Ans_lab.md)
