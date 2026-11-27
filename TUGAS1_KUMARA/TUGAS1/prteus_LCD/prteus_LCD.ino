#include<LiquidCrystal.h> //memanggil lcd 16x2 
LiquidCrystal lcd(12,11,5,4,3,2);
//urutannya dri RS E D4 D5 D 6 D7
int pinLDR = A0;
int nilaiLDR = 0;
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);

//tampilan awal layar
lcd.setCursor(0,0);
lcd.print("JARAK");

}

void loop() {
  // put your main code here, to run repeatedly:
  nilaiLDR= analogRead(A0);
lcd.setCursor(8,0); //menentukan posisi tulisan atas bawh
lcd.print("NILAI ULTRASONIK");
lcd.print(" ");

lcd.setCursor(0,1);
if(nilaiLDR < 40){
 lcd.print("Status: DEKAT");
 delay(200);
} 

if(nilaiLDR > 40){
  lcd.print("Status: JAUH");
  delay(200);
  
}
delay(200);

lcd.scrollDisplayRight();
delay(20);

}
