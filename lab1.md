# การทดลองที่ 1 เรื่อง การเขียนโปรแกรมเพื่อรันบนไมโครคอนโทรเลอร์  
## วัตถุประสงค์
  * เพื่อเป็นการศึกษาการเขียนโปรแกรมเพื่อรันบนไมโครคอนโทรเลอร์ 
## อุปกรณ์ที่ใช้ 
  1. บอร์ด ESP_01
  2. สายต่อ USB
  3. ตัวแปลง USB to Serial Port 
## ศึกษาข้อมูลเบื้องต้น
  * [ESP_01 PlatformIO](https://docs.platformio.org/en/latest/boards/espressif8266/esp01.html)
  * [ตัวอย่างการทดลอง LAB 1](https://youtu.be/NLIUsWLEpmg)
## วิธีการทำการทดลอง
  1. ทำการต่อสาย USB เข้ากับ ตัวแปลงเป็น Serial Port เพื่อต่อเข้ากับ ESP_01
  2. นำ ESP_01 ต่อเข้ากับ Serial Port
  3. เปิดโปรแกรมที่จะทำการรัน เข้าโฟลเดอร์ที่บันทึกเอาไว้ `cd examples` แล้ว `cd 01_Serial-Monitor`
  4. รันคำสั่ง `pio run -t upload`
![S__12099586](https://user-images.githubusercontent.com/80879119/111986735-ea4cc680-8b40-11eb-9dc6-f2c1305fb99d.jpg)
  5. กดปุ่มดำค้างไว้แล้วกดปุ่ม Reset เพื่อให้ ESP_01 รับโปรแกรม
![S__12099587](https://user-images.githubusercontent.com/80879119/111986917-1d8f5580-8b41-11eb-9dfd-e45c8231655b.jpg)
![S__12099589](https://user-images.githubusercontent.com/80879119/111986993-33047f80-8b41-11eb-8c5e-20dc960a7a94.jpg)
![S__12099590](https://user-images.githubusercontent.com/80879119/111987051-49aad680-8b41-11eb-90ca-0d115a67b470.jpg)
  6. รันคำสั่ง `pio device monitor` เพื่อดูผลที่แสดงผลออกมา
![S__12099591](https://user-images.githubusercontent.com/80879119/111987056-4c0d3080-8b41-11eb-8ec6-9034a8aa9d0c.jpg)
  7. ลองกดปุ่ม reset 
![S__12099592](https://user-images.githubusercontent.com/80879119/111987194-765eee00-8b41-11eb-94e5-9c4d28c313c5.jpg)
## การบันทึกผลการทดลอง 
 ผลที่แสดงออกมาจะเป็นการนับเพิ่มทีละหนึ่งขึ้นไปเรื่อยๆ
![S__12099591](https://user-images.githubusercontent.com/80879119/111987056-4c0d3080-8b41-11eb-8ec6-9034a8aa9d0c.jpg)
## อภิปรายผลการทดลอง 
 เราสามารถที่จะเขียนโปรแกรมเพื่อที่จะทำการรันบนไมโครคอนโทรเลอร์ ด้วยการเปลี่ยนการทำงานในส่วนของ Loob เพื่อให้ทำตามที่ต้องการ
## คำถามหลังการทดลอง 
 
