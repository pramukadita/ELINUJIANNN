#include <LiquidCrystal.h>

// Inisialisasi LCD (RS=12, E=11, D4=5, D5=4, D6=3, D7=2)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define pinTrig 8
#define pinEcho 9

void setup() {
  Serial.begin(9600); // Mengaktifkan Serial Monitor
  
  pinMode(pinTrig, OUTPUT); // Menetapkan pinTrig sebagai output
  pinMode(pinEcho, INPUT);  // Menetapkan pinEcho sebagai input

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print(" Cek Jarak... ");
  delay(1500);
  lcd.clear();
}

void loop() {
  // Pastikan pinTrig bernilai LOW sebelum mengirim pulsa
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(2);
  
  // Kirim pulsa trigger HIGH selama 10 mikrodetik
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);

  // Hitung durasi dan ubah menjadi centimeter
  long durasi = pulseIn(pinEcho, HIGH);
  int jarak = durasi * 0.034 / 2;

  // Tampilkan ke LCD
  lcd.setCursor(0, 0);
  lcd.print("Jarak Sensor:   "); // Spasi untuk membersihkan sisa teks
  
  lcd.setCursor(0, 1);
  lcd.print("                "); // Membersihkan baris bawah
  lcd.setCursor(0, 1);
  lcd.print(jarak);
  lcd.print(" cm");

  // Tampilkan ke Serial Monitor
  Serial.print("Jarak Sensor: ");
  Serial.print(jarak);
  Serial.println(" cm");

  delay(200);
}