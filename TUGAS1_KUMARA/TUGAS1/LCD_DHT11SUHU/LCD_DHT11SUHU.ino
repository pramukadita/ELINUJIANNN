#include <LiquidCrystal.h>
#include <DHT.h>

// Inisialisasi LCD (RS=12, E=11, D4=5, D5=4, D6=3, D7=2)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define DHTPIN 8       // Pin DATA DHT11 terhubung ke D8
#define DHTTYPE DHT11  // Menentukan jenis sensor (DHT11)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  
  dht.begin(); // Mengaktifkan sensor DHT11
  
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print(" Cek DHT11... ");
  delay(1500);
  lcd.clear();
}

void loop() {
  // Membaca kelembapan (%) dan suhu (Celsius)
  float kelembapan = dht.readHumidity();
  float suhu = dht.readTemperature();

  // Cek apakah pembacaan gagal
  if (isnan(kelembapan) || isnan(suhu)) {
    lcd.setCursor(0, 0);
    lcd.print("Error Baca DHT  ");
    Serial.println("Gagal membaca dari sensor DHT!");
    delay(2000);
    return;
  }

  // Tampilkan Suhu di Baris 1 LCD
  lcd.setCursor(0, 0);
  lcd.print("Suhu : ");
  lcd.print(suhu, 1); // 1 angka di belakang koma
  lcd.print((char)223); // Karakter derajat (°)
  lcd.print("C  ");

  // Tampilkan Kelembapan di Baris 2 LCD
  lcd.setCursor(0, 1);
  lcd.print("Lembap: ");
  lcd.print(kelembapan, 1);
  lcd.print("%  ");

  // Tampilkan juga ke Serial Monitor
  Serial.print("Suhu: ");
  Serial.print(suhu);
  Serial.print(" °C | Kelembapan: ");
  Serial.print(kelembapan);
  Serial.println(" %");

  delay(2000); // Sensor DHT11 butuh jeda minimal 1-2 detik antar pembacaan
}