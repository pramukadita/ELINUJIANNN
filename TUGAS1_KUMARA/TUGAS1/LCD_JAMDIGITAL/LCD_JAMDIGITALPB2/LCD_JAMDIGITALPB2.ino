#include <LiquidCrystal.h>

// Inisialisasi pin LCD 16x2 (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int jam = 0;
int menit = 0;
int detik = 0;
int pbjam = 8;
int pbatur = 9 ;
int pbmenit =10;
int led=7;

void setup() {
  // Mengatur ukuran LCD 16 kolom dan 2 baris (pengganti lcd.init)
  lcd.begin(16, 2); 
  lcd.setCursor(0, 0);
  lcd.print("Jam saiki");
  pinMode(pbjam,INPUT_PULLUP);
  pinMode(pbmenit,INPUT_PULLUP);
  pinMode(pbatur,INPUT_PULLUP);
  pinMode(LED,OUTPUT);
}

void loop() {
  detik=detik+1;
  delay(1000);
  
  if (detik >= 59) {
    detik = 0;
    menit++;
  }
  
  if (menit >= 59) {
    menit = 0;
    jam++;
  }
  
  if (jam >= 24) {
    jam = 0;
  }
  lcd.setCursor(1,1);
  lcd.print(jam);
  lcd.setCursor(3,1);
  lcd.print(";");
  lcd.setCursor(4,1);
  lcd.print(menit);
  lcd.setCursor(6,1);
  lcd.print(";");
  lcd.setCursor(7,1);
  lcd.print(jam);
  
  
  
  lcd.setCursor(0, 1);
  
  if (jam < 10) {
    lcd.print("0");
  }
  lcd.print(jam);
  lcd.print(":");
  
  if (menit < 10) {
    lcd.print("0");
  }
  lcd.print(menit);
  lcd.print(":");
  
  if (detik < 10) {
    lcd.print("0");
  }
  lcd.print(detik);

if (digitalRead(pbjam) == LOW) {
    jam++;
    if (jam >= 24) {
      jam = 0;
    }
  
  }

  if (digitalRead(pbmenit) == LOW) {
    menit++;
    if (menit >= 59) {
      menit = 0;
    }

      if (digitalRead(pbatur) == LOW) {
    menit++;
    if (menit >= 59) {
      menit = 0;
    }

  }
}
  
