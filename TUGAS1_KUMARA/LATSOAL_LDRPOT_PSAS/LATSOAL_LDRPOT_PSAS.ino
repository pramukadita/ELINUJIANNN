int potPin;
int ldrPin;
int led = 9;
int nilaiPot,nilaiLDR;
int pwm;

void setup(){
Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
 nilaiPot = analogRead(potPin);
  nilaiLDR = analogRead(ldrPin);
  pwm =  map(nilaiPot, 0, 1023, 0, 255);
  analogWrite(led, pwm);

  if (nilaiLDR < 300) { 
Serial.println("ruangan gelap");
  } else{
Serial.println("ruangan terang");
  }
}
