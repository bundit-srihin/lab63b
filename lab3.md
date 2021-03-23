# การทดลองที่ 3 เรื่อง การเขียนโปรแกรมเอ้าพุทสัญญาณดิจิทัล  
## วัตถุประสงค์ 
  * เพื่อดูการเอ้าพุทของไมโครคอนโทรเลอร์
  * เพื่อการนำเอ้าพุทไมโครคอนโทรเลอร์ที่โปรแกรมแล้วไปใช้ประโยชน์
## อุปกรณ์ที่ใช้ 
  1. บอร์ด ESP_01
  2. สายต่อ USB
  3. ตัวแปลง USB to Serial Port
  4. Adapter ต่อ Serial Port กับสายพ่วง และตัวหนีบ
  5. หลอด LED
  6. รีเลย์ 
## ศึกษาข้อมูลเบื้องต้น 
  * [ESP_01 PlatformIO](https://docs.platformio.org/en/latest/boards/espressif8266/esp01.html)
  * [ตัวอย่างการทดลอง LAB 3 part 1](https://youtu.be/CCnN1WJsXQY)
  * [ตัวอย่างการทดลอง LAB 3 part 2](https://youtu.be/6JnhaUILGuw)
  * [โปรแกรม 03](https://github.com/bundit-srihin/lab63b/tree/main/examples/03_Output-Port)
## วิธีการทำการทดลอง 
  1. ทำการต่อสาย USB เข้ากับ ตัวแปลงเป็น Serial Port 
  2. ต่อ Adapter กับ Serial Port
  3. หนีบหลอด LED ตามรูป
![S__12099603](https://user-images.githubusercontent.com/80879119/111989196-09992300-8b44-11eb-869a-acca201a06dd.jpg)
  4. นำ ESP_01 ต่อเข้ากับ Serial Port ของ Adapter
  5. เปิดโปรแกรมที่จะทำการรัน เข้าโฟลเดอร์ที่บันทึกเอาไว้ `cd pattani` แล้ว `cd 03_Output-Port`
  6. รันคำสั่ง `pio run -t upload`
![S__12099604](https://user-images.githubusercontent.com/80879119/111989225-161d7b80-8b44-11eb-9581-24df450e09fe.jpg)
  7. กดปุ่มดำค้างไว้แล้วกดปุ่ม Reset เพื่อให้ ESP_01 รับโปรแกรม
![S__12099605](https://user-images.githubusercontent.com/80879119/111989634-9b089500-8b44-11eb-9523-b2f3efe3de5e.jpg)
  8. รันคำสั่ง `pio device monitor` เพื่อดูผลที่แสดงผลออกมา
![S__12099606](https://user-images.githubusercontent.com/80879119/111989700-b2478280-8b44-11eb-8abf-816b304c0566.jpg)
![S__12099607](https://user-images.githubusercontent.com/80879119/111989734-bc698100-8b44-11eb-8204-3c02d6a73071.jpg)
  9. ลองกดปุ่ม reset
![S__12099608](https://user-images.githubusercontent.com/80879119/111989866-e9b62f00-8b44-11eb-92d7-0a9542c6d172.jpg)
  10. ถอดบอร์ดออกจาก Serial Port ของ Adapter แล้วนำไปต่อกับ Serial Port ของ Relay
  11. พร้อมต่อไฟ 5 V เข้า Relay
## การบันทึกผลการทดลอง 
 การเอ้าพุทของสัญญาณ จะเป็นการปิดเปิด หลอด LED ลับไปมา ตามโปรแกรมที่ออกแบบไว้
![S__12099607](https://user-images.githubusercontent.com/80879119/111989734-bc698100-8b44-11eb-8204-3c02d6a73071.jpg)
## อภิปรายผลการทดลอง 
 การเอ้าพุทของสัญญาณเป็นการปล่อยแรงดัน ทำให้หลอด LED ติด
## คำถามหลังการทดลอง 

