int pot = A1;

int pb1 = A2;
int pb2 = A3;
int led1 = 4;
int led2 = 5;
int led3 = 6;
int a=13;
int b=12;
int c=11;
int d=10;
int e=9;
int f=8;
int g=7;
int x;
int NilaiLDR = 0;
int y;


void setup() {
  // put your setup code here, to run once:
pinMode(pb1,INPUT);
pinMode(pb2,INPUT_PULLUP);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(a,OUTPUT);
pinMode(b,OUTPUT);
pinMode(c,OUTPUT);
pinMode(d,OUTPUT);
pinMode(e,OUTPUT);
pinMode(f,OUTPUT); 
pinMode(g,OUTPUT);

 Serial.begin(9600);

digitalWrite(led1,0);
digitalWrite(led2,0);
digitalWrite(led3,0);
digitalWrite(a,0);
digitalWrite(b,0);
digitalWrite(c,0);
digitalWrite(d,0);
digitalWrite(e,0);
digitalWrite(f,0);
digitalWrite(g,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  
LDR();
if(digitalRead(pb1)==1){
  digitalWrite(led1,1);
  digitalWrite(led2,0);
  digitalWrite(led3,1);
delay(900);
  digitalWrite(led1,0);
  digitalWrite(led2,1);
  digitalWrite(led3,0);
delay(900);
  digitalWrite(led1,1);
  digitalWrite(led2,1);
  digitalWrite(led3,1);
  delay(900);











if(x == 9){  
  x = 9;
}



if(x == 0){
 nol();
}
if(x == 1){
 satu();
}
if(x == 2){
 dua();
}
if(x == 3){
 tiga();
}
if(x == 4){
 empat();
}
if(x == 5){
 lima();
}



 if (y > 0) { 
nol(); 
  }
   if (y > 1) { 
   satu();
  }
    if (y > 2) { 
dua(); 
  }
   if (y > 3) { 
   tiga();
  }
    if (y > 4) { 
empat(); 
  }
   if (y > 5) { 
   lima();
  }
}
}



void nol(){
digitalWrite(a,1);
digitalWrite(b,1);
digitalWrite(c,1);
digitalWrite(d,1);
digitalWrite(e,1);
digitalWrite(f,1);
digitalWrite(g,0);
}
void satu(){
digitalWrite(a,0);
digitalWrite(b,1);
digitalWrite(c,1);
digitalWrite(d,0);
digitalWrite(e,0);
digitalWrite(f,0);
digitalWrite(g,0);

}
void dua(){
digitalWrite(a,1);
digitalWrite(b,1);
digitalWrite(c,0);
digitalWrite(d,1);
digitalWrite(e,1);
digitalWrite(f,0);
digitalWrite(g,1);

}
void tiga(){
digitalWrite(a,1);
digitalWrite(b,1);
digitalWrite(c,1);
digitalWrite(d,1);
digitalWrite(e,0);
digitalWrite(f,0);
digitalWrite(g,1);

}
void empat(){
digitalWrite(a,0);
digitalWrite(b,1);
digitalWrite(c,1);
digitalWrite(d,0);
digitalWrite(e,0);
digitalWrite(f,1);
digitalWrite(g,1);

}
void lima(){
digitalWrite(a,1);
digitalWrite(b,0);
digitalWrite(c,1);
digitalWrite(d,1);
digitalWrite(e,0);
digitalWrite(f,1);
digitalWrite(g,1);
}


 void LDR(){
  NilaiLDR = map(analogRead(A0),0, 1023, 0, 10);
  Serial.print("Nilai LDR:");
  Serial.println(NilaiLDR);
 }