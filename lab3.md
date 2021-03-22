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
## วิธีการทำการทดลอง 
  1. ทำการต่อสาย USB เข้ากับ ตัวแปลงเป็น Serial Port 
  2. ต่อ Adapter กับ Serial Port
  3. นำ ESP_01 ต่อเข้ากับ Serial Port ของ Adapter
  4. เปิดโปรแกรมที่จะทำการรัน เข้าโฟลเดอร์ที่บันทึกเอาไว้ `cd examples` แล้ว `cd 03_Output-Port`
  5. รันคำสั่ง `pio run -t upload`
  6. กดปุ่มดำค้างไว้แล้วกดปุ่ม Reset เพื่อให้ ESP_01 รับโปรแกรม
  7. รันคำสั่ง `pio device monitor` เพื่อดูผลที่แสดงผลออกมา
  8. ลองกดปุ่ม reset
  9. ถอดบอร์ดออกจาก Serial Port ของ Adapter แล้วนำไปต่อกับ Serial Port ของ Relay 
  10. พร้อมต่อไฟ 5 V เข้า Relay  
## การบันทึกผลการทดลอง 
## อภิปรายผลการทดลอง 
## คำถามหลังการทดลอง 

