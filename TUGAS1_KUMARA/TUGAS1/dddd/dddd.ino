//buat lampu 7 segment menggunakan 7 kaki common anoda
int a=2;
int b=3;
int c=4;
int d=5;
int e=6;
int f=7;
int g=8;
int simpan;
int stuck=1;
int pb=10;

int x;


void setup() {

  // put your setup code here, to run once
Serial.begin(9600);
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
    pinMode(c,OUTPUT);
      pinMode(d,OUTPUT);
        pinMode(e,OUTPUT);
          pinMode(f,OUTPUT);
            pinMode(g,OUTPUT);
            pinMode(pb,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
   x=analogRead(A0);
 Serial.println(x);
  Serial.println(simpan);
 delay(1000);

if(digitalRead(pb)==0){
  simpan=x;
  stuck=0;
}

if(stuck==0){
}

if(x<20){
 nol();
}

if(x>100){
 satu();
}


if(x>200){
 dua();
}


if(x>300){
 tiga();
}

if(x>400){
 empat();
}

if(x>500){
 lima();
}
if(x>560){
  mati();
}
}

void mati(){
  digitalWrite(a,1);
digitalWrite(b,1);
digitalWrite(c,1);
digitalWrite(d,1);
digitalWrite(e,1);
digitalWrite(f,1);
digitalWrite(g,1);
}
void nol(){
digitalWrite(a,0);
digitalWrite(b,0);
digitalWrite(c,0);
digitalWrite(d,0);
digitalWrite(e,0);
digitalWrite(f,0);
digitalWrite(g,1);
}
void satu(){
digitalWrite(a,1);
digitalWrite(b,0);
digitalWrite(c,0);
digitalWrite(d,1);
digitalWrite(e,1);
digitalWrite(f,1);
digitalWrite(g,1);
}
void dua(){
digitalWrite(a,0);
digitalWrite(b,0);
digitalWrite(c,1);
digitalWrite(d,0);
digitalWrite(e,0);
digitalWrite(f,1);
digitalWrite(g,0);
}
void tiga(){
digitalWrite(a,0);
digitalWrite(b,0);
digitalWrite(c,0);
digitalWrite(d,0);
digitalWrite(e,1);
digitalWrite(f,1);
digitalWrite(g,0);
}
void empat(){
digitalWrite(a,1);
digitalWrite(b,0);
digitalWrite(c,0);
digitalWrite(d,1);
digitalWrite(e,1);
digitalWrite(f,0);
digitalWrite(g,0);
}
void lima(){
digitalWrite(a,0);
digitalWrite(b,1);
digitalWrite(c,0);
digitalWrite(d,0);
digitalWrite(e,1);
digitalWrite(f,0);
digitalWrite(g,0);
}
void enam(){
digitalWrite(a,0);
digitalWrite(b,1);
digitalWrite(c,0);
digitalWrite(d,0);
digitalWrite(e,0);
digitalWrite(f,0);
digitalWrite(g,0);
}
void tujuh(){
digitalWrite(a,0);
digitalWrite(b,0);
digitalWrite(c,0);
digitalWrite(d,1);
digitalWrite(e,1);
digitalWrite(f,1);
digitalWrite(g,1);
}
void delapan(){
digitalWrite(a,0);
digitalWrite(b,0);
digitalWrite(c,0);
digitalWrite(d,0);
digitalWrite(e,0);
digitalWrite(f,0);
digitalWrite(g,0);
}
void sembilan(){
digitalWrite(a,0);
digitalWrite(b,0);
digitalWrite(c,0);
digitalWrite(d,0);
digitalWrite(e,1);
digitalWrite(f,0);
digitalWrite(g,0);
}
