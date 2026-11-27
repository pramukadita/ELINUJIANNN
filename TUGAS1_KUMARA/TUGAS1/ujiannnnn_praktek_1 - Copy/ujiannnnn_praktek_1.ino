//buat lampu 7 segment menggunakan 7 kaki common anoda 
//PB1 KLIK = +
//PB2 KLK = -
//potensio untuk led kuninggggggg
//ldr untuk led hijauuuu      
//led merah kedapp kedippp                                                              
int a=13;
int b=12;
int c=11;
int d=10;
int e=9;
int f=8;
int g=7;
int pb=A2;
int pb2=A3;
int x;
int led1=4;
int led2=5;
int led3=6;
int y;
int nilaiLDR = 0;



void setup() {

  // put your setup code here, to run once
  pinMode(pb,INPUT);
   pinMode(pb2,INPUT_PULLUP);
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
    pinMode(c,OUTPUT);
      pinMode(d,OUTPUT);
        pinMode(e,OUTPUT);
          pinMode(f,OUTPUT);
            pinMode(g,OUTPUT);
             pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lampuindikator();
if(digitalRead(pb)==1){
  x++;
  delay(50);
}  
if (digitalRead(pb2)==0){
  x--;
  delay(50);
}

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
if(x == 6){
 enam();
}
if(x == 7){
 tujuh();
}
if(x == 8){
 delapan();
}
if(x == 9){
 sembilan();
}




POT();
LDR();


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
void enam(){
digitalWrite(a,1);
digitalWrite(b,0);
digitalWrite(c,1);
digitalWrite(d,1);
digitalWrite(e,1);
digitalWrite(f,1);
digitalWrite(g,1);

}
void tujuh(){
digitalWrite(a,1);
digitalWrite(b,1);
digitalWrite(c,1);
digitalWrite(d,0);
digitalWrite(e,0);
digitalWrite(f,0);
digitalWrite(g,0);

}
void delapan(){
digitalWrite(a,1);
digitalWrite(b,1);
digitalWrite(c,1);
digitalWrite(d,1);
digitalWrite(e,1);
digitalWrite(f,1);
digitalWrite(g,1);

}
void sembilan(){
digitalWrite(a,1);
digitalWrite(b,1);
digitalWrite(c,1);
digitalWrite(d,1);
digitalWrite(e,0);
digitalWrite(f,1);
digitalWrite(g,1);



}
void POT(){
   y = map(analogRead(A1), 0, 1023, 0, 256);
  Serial.print("Nilai POT: ");
  Serial.println(y);
  if (y > 128) { 
    digitalWrite(led2, HIGH); 
  }
   if (y < 128) { 
    digitalWrite(led2, LOW); 
  }
}
void LDR(){
  
 nilaiLDR = analogRead(A0);
  Serial.print("Nilai LDR: ");
  Serial.println(nilaiLDR);

  if (nilaiLDR > 300) { 
    digitalWrite(led3, HIGH); 
  }
   if (nilaiLDR < 300) { 
    digitalWrite(led3, LOW); 
  }
}
void lampuindikator(){
  digitalWrite(led1,LOW);
delay(500);

digitalWrite(led1,HIGH);
delay(500);
}

