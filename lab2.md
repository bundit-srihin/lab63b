# การทดลองที่ 2 เรื่อง การเขียนโปรแกรมค้นหาไวไฟ  
## วัตถุประสงค์ 
  * เพื่อเป็นการใช้งาน ความสามารถที่ ไมโครคอนโทรเลอร์ ESP_01 มี
  * เพื่อเป็นการทำความเข้าใจการเขียนโปรแกรมลงไมโครคอนโทรเลอร์
  * เพื่อศึกษาการทำงานของการค้นหาไวไฟ
## อุปกรณ์ที่ใช้ 
  1. บอร์ด ESP_01
  2. สายต่อ USB
  3. ตัวแปลง USB to Serial Port 
## ศึกษาข้อมูลเบื้องต้น
  * [ESP_01 PlatformIO](https://docs.platformio.org/en/latest/boards/espressif8266/esp01.html)
  * [ตัวอย่างการทดลอง LAB 2](https://youtu.be/yBjab0UNuB8)
  * [โปรแกรม 02](https://github.com/bundit-srihin/lab63b/tree/main/examples/02_Scan-Wifi)
## วิธีการทำการทดลอง 
  1. ทำการต่อสาย USB เข้ากับ ตัวแปลงเป็น Serial Port เพื่อต่อเข้ากับ ESP_01
  2. นำ ESP_01 ต่อเข้ากับ Serial Port
  3. เปิดโปรแกรมที่จะทำการรัน เข้าโฟลเดอร์ที่บันทึกเอาไว้ `cd pattani` แล้ว `cd 02_Scan-Wifi`
  4. รันคำสั่ง `pio run -t upload`
![S__12099594](https://user-images.githubusercontent.com/80879119/111988217-c8ecda00-8b42-11eb-9fb2-69a3315d0013.jpg)
  5. กดปุ่มดำค้างไว้แล้วกดปุ่ม Reset เพื่อให้ ESP_01 รับโปรแกรม
![S__12099596](https://user-images.githubusercontent.com/80879119/111988264-dd30d700-8b42-11eb-9e62-d6fbf365755c.jpg)
  6. รันคำสั่ง `pio device monitor` เพื่อดูผลที่แสดงผลออกมา
![S__12099597](https://user-images.githubusercontent.com/80879119/111988329-f46fc480-8b42-11eb-851c-d2fd02a292a3.jpg)
![S__12099598](https://user-images.githubusercontent.com/80879119/111988393-081b2b00-8b43-11eb-9141-67f770ae1d66.jpg)
  7. ลองกดปุ่ม reset 
![S__12099599](https://user-images.githubusercontent.com/80879119/111988397-09e4ee80-8b43-11eb-87c5-4ce2b275e26e.jpg)
## การบันทึกผลการทดลอง
 ไมโครคอนโทรเลอร์จะทำการค้นหาไวไฟในบริเวณนั้น ตามความแรงของสัญญาณที่สามารถจับได้
![S__12099598](https://user-images.githubusercontent.com/80879119/111988393-081b2b00-8b43-11eb-9141-67f770ae1d66.jpg)
## อภิปรายผลการทดลอง 
 ไมโครคอนโทรเลอร์ที่มีโมดูลไวไฟ สามารถที่่จะทำงานเกี่ยวกับไวไฟตามโปรแกรมที่เขียนไว้
## คำถามหลังการทดลอง 
