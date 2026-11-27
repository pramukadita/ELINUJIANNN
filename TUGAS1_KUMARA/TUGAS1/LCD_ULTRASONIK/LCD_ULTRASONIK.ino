#include <LiquidCrystal.h>

// Inisialisasi LCD (RS=12, E=11, D4=5, D5=4, D6=3, D7=2)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define pinTrig 8
#define pinEcho 9

// Jumlah sampel untuk meratakan data (semakin besar semakin stabil, tapi agak lambat merespons)
const int jumlahSampel = 5; 

void setup() {
  Serial.begin(9600);
  
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print(" Inisialisasi... ");
  delay(1500);
  lcd.clear();
}

void loop() {
  long totalDurasi = 0;

  // Mengambil beberapa sampel pembacaan dalam satu waktu
  for (int i = 0; i < jumlahSampel; i++) {
    digitalWrite(pinTrig, LOW);
    delayMicroseconds(2);
    digitalWrite(pinTrig, HIGH);
    delayMicroseconds(10);
    digitalWrite(pinTrig, LOW);

    // Ambil durasi
    totalDurasi += pulseIn(pinEcho, HIGH, 25000); // Timeout 25ms agar tidak freeze jika meleset
    delay(10); // Jeda antar sampel
  }

  // Hitung rata-rata durasi dari sampel yang diambil
  long rataDurasi = totalDurasi / jumlahSampel;
  
  // Konversi rata-rata durasi menjadi centimeter
  int jarak = rataDurasi * 0.034 / 2;

  // Tampilkan ke LCD dengan format rapi (diberi spasi agar sisa angka lama tertutup)
  lcd.setCursor(0, 0);
  lcd.print("Jarak Sensor:   ");
  
  lcd.setCursor(0, 1);
  lcd.print("                "); 
  lcd.setCursor(0, 1);
  lcd.print(jarak);
  lcd.print(" cm   ");

  // Tampilkan ke Serial Monitor
  Serial.print("Jarak Stabil: ");
  Serial.print(jarak);
  Serial.println(" cm");

  delay(100); // Jeda pembacaan loop
}