int x;
byte y;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(3,OUTPUT);
pinMode(5,OUTPUT);
pinMode(A0,INPUT);
Serial.begin(9600);
}

void loop() { 
  // put your main code here, to run repeatedly:
  x=analogRead(A0);
  y=map(x,0,1023,0,255);
  Serial.println(y);
analogWrite(3,y);
analogWrite(5,y);
}

