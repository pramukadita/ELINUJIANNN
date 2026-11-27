// 2

byte x;
void setup() {
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 x=analogRead(A0);
 Serial.println(x);
 delay(100);
}