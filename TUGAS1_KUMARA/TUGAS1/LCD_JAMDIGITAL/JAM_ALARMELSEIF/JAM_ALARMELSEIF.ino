#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int jam = 0;
int menit = 0;
int detik = 0;

int pbjam = 8;     
int pbatur = 9;    
int pbmenit = 10;  
int led1 = 7;      

int modeAtur = 0;  
int alarmjam = 0;
int alarmmenit = 0;

void setup() {
  lcd.begin(16, 2); 
  pinMode(pbjam, INPUT_PULLUP);
  pinMode(pbmenit, INPUT_PULLUP);
  pinMode(pbatur, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  
  lcd.setCursor(0, 0);
  lcd.print("Jam Saiki");
}

void loop() {
  bacaTombol();

  if (modeAtur == 0) {
    detik++;
    delay(1000);
    
    if (detik >= 60) {
      detik = 0;
      menit++;
    }
    
    if (menit >= 60) {
      menit = 0;
      jam++;
    }
    
    if (jam >= 24) {
      jam = 0;
    }
  }

  // Kontrol LED Alarm
  digitalWrite(led1, LOW);
  if (jam == alarmjam && menit == alarmmenit) {
    digitalWrite(led1, HIGH);
  }

  // Tampilan ke LCD berdasarkan mode (baris ke-1)
  lcd.setCursor(0, 1);
  
  if (modeAtur == 0) {
    if (jam < 10) lcd.print("0");
    lcd.print(jam);
    lcd.print(":");
    if (menit < 10) lcd.print("0");
    lcd.print(menit);
    lcd.print(":");
    if (detik < 10) lcd.print("0");
    lcd.print(detik);
    lcd.print("   "); 
  }
  else if (modeAtur == 1) {
    lcd.print("Atur: ");
    if (jam < 10) lcd.print("0");
    lcd.print(jam);
    lcd.print(":");
    if (menit < 10) lcd.print("0");
    lcd.print(menit);
    lcd.print("   "); 
  }
  else if (modeAtur == 2) {
    lcd.print("Alm: "); 
    if (alarmjam < 10) lcd.print("0");
    lcd.print(alarmjam);
    lcd.print(":");
    if (alarmmenit < 10) lcd.print("0");
    lcd.print(alarmmenit);
    lcd.print("   "); 
  }
}

void bacaTombol() {
  if (digitalRead(pbatur) == LOW) {
    delay(10);
    if (digitalRead(pbatur) == LOW) { 
      modeAtur++;
      if (modeAtur > 2) {
        modeAtur = 0;
      }
      
      lcd.clear(); 
      lcd.setCursor(0, 0);
      if (modeAtur == 0) lcd.print("Jam Saiki");
      else if (modeAtur == 1) lcd.print("Set Waktu");
      else if (modeAtur == 2) lcd.print("Set Alarm");
      
      while (digitalRead(pbatur) == LOW) {}
      delay(50);
    }
  }

  if (digitalRead(pbjam) == LOW) {
    delay(50);
    if (digitalRead(pbjam) == LOW) {
      if (modeAtur == 2) {
        alarmjam++;
        if (alarmjam >= 24) alarmjam = 0;
      } else {
        jam++;
        if (jam >= 24) jam = 0;
      }
      
      while (digitalRead(pbjam) == LOW) {}
      delay(50);
    }
  }

  if (digitalRead(pbmenit) == LOW) {
    delay(50);
    if (digitalRead(pbmenit) == LOW) {
      if (modeAtur == 2) {
        alarmmenit++;
        if (alarmmenit >= 60) alarmmenit = 0;
      } else {
        menit++;
        if (menit >= 60) menit = 0;
      }
      
      while (digitalRead(pbmenit) == LOW) {}
      delay(10);
    }
  }
}