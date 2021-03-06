# การทดลองที่ 4 เรื่อง การเขียนโปรแกรมอินพุทสัญญาณดิจิทัล 
## วัตถุประสงค์ 
  * เพื่อเป็นการศึกษาการนำอินพุทจากภายนอกเข้ามาในตัวไมโครคอนโทรเลอร์
  * เพื่อการนำไปประยุกต์ใช้ประโยชน์
## อุปกรณ์ที่ใช้ 
  1. บอร์ด ESP_01
  2. สายต่อ USB
  3. ตัวแปลง USB to Serial Port
  4. Adapter ต่อ Serial Port กับสายพ่วง และตัวหนีบ
  5. หลอด LED
  6. เซนเซอร์แสง  
## ศึกษาข้อมูลเบื้องต้น 
  * [ESP_01 PlatformIO](https://docs.platformio.org/en/latest/boards/espressif8266/esp01.html)
  * [ตัวอย่างการทดลอง LAB 4](https://youtu.be/nFqoZT26U5k)
  * [โปรแกรม 04](https://github.com/bundit-srihin/lab63b/blob/main/examples/04_Input-Port/src/main.cpp)
## วิธีการทำการทดลอง 
  1. ทำการต่อสาย USB เข้ากับ ตัวแปลงเป็น Serial Port 
  2. ต่อ Adapter กับ Serial Port
  3. นำ ESP_01 ต่อเข้ากับ Serial Port ของ Adapter
  4. ต่อ LED ที่ขาหนีบเส้นสีเหลือง และอีกขาที่เส้นดำ
  5. เปิดโปรแกรมที่จะทำการรัน เข้าโฟลเดอร์ที่บันทึกเอาไว้ `cd pattani` แล้ว `cd 04_Input-Port`
  6. รันคำสั่ง `pio run -t upload`
![S__12099614](https://user-images.githubusercontent.com/80879119/111993865-b1651f80-8b49-11eb-9623-d0fe4da0e445.jpg)
  7. กดปุ่มดำค้างไว้แล้วกดปุ่ม Reset เพื่อให้ ESP_01 รับโปรแกรม
![S__12099616](https://user-images.githubusercontent.com/80879119/111993929-c17cff00-8b49-11eb-9443-9503a5847af7.jpg)
  8. รันคำสั่ง `pio device monitor` เพื่อดูผลที่แสดงผลออกมา
![S__12099617](https://user-images.githubusercontent.com/80879119/111993957-cc379400-8b49-11eb-8413-c2ed73c629f7.jpg)
  9. ทำการนำสายสีขาว แตะที่ 0 V เส้นสีดำ
![S__12099620](https://user-images.githubusercontent.com/80879119/111994145-ff7a2300-8b49-11eb-9e43-6ff0aec5ef5e.jpg)
     นำสายสีขาว แตะที่ สายสีแดง
![S__12099619](https://user-images.githubusercontent.com/80879119/111994336-40723780-8b4a-11eb-962f-c1d9740c043d.jpg)
  10. ลองกดปุ่ม reset
![S__12099621](https://user-images.githubusercontent.com/80879119/111994211-1751a700-8b4a-11eb-9bef-dc9489140821.jpg)
  11. นำ เซนเซอร์แสง ที่ ต่อกับความต้านทาน ต่อขาความต้านทานกับเส้นไฟเลี้ยง สายสีแดง และต่อขาที่ร่วมกันของความต้านทาน กับเซนเซอร์แสง ไว้ที่สายสีขาว แต่ยังไม่ต่อสายสีขาว และขาเซนเซอร์แสงอีกข่้างต่อเส้นสีดำ
![S__12099622](https://user-images.githubusercontent.com/80879119/111994384-4a943600-8b4a-11eb-9960-06fcae16c3e2.jpg)
  12. นำเส้นสีขาวต่อกับ ขาร่วม
![S__12099623](https://user-images.githubusercontent.com/80879119/111994510-6f88a900-8b4a-11eb-9d1c-1bf5ce9fb5b6.jpg)
  13. ปิดหน้าสัมผัสเซนเซอร์ 
![S__12099624](https://user-images.githubusercontent.com/80879119/111994515-70213f80-8b4a-11eb-89ee-cb61ca892fad.jpg) 
## การบันทึกผลการทดลอง 
 เมื่อมีการอินพุทเข้าไป จะมีการ read 0 ทำให้หลอดไฟติด ไม่ว่าจะเ็นการนำสายสีขาวแตะที่สายสีดำ หรือกดปุ่มดำ
![S__12099620](https://user-images.githubusercontent.com/80879119/111994145-ff7a2300-8b49-11eb-9e43-6ff0aec5ef5e.jpg)
![S__12099621](https://user-images.githubusercontent.com/80879119/111994211-1751a700-8b4a-11eb-9bef-dc9489140821.jpg)
## อภิปรายผลการทดลอง 
 เมื่อมีการอินพุทเข้ามา สามารถที่จะโปรแกรมให้ ไมโครคอนโทรเลอร์จะทำการเอ้าพุทออกไปตาม pin ที่เรากำหนดอินพุท และเอ้าพุทเอาไว้
## คำถามหลังการทดลอง 
 ในการทดลองเมื่อไม่มีและมีการอินพุทเข้าที่ pin 0 หรือสายสีขาว จะทำให้โปรแกรมแสดงผลออกมาอย่างไร ???
 * [Ans](https://github.com/bundit-srihin/lab63b/blob/main/Ans_lab.md)
