// 1
//TAMBAHKAN LED NAMBAH IF DAN PIN MODE 
int x;
int led1=7;
int led2=6;
int led3=8;
void setup() {
  pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
    pinMode(led3,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

 x=analogRead(A0);
 Serial.println(x);
 delay(10);

if(x>300){
  digitalWrite(led3,LOW);
  digitalWrite(led2,HIGH); 
}
if(x<300){
  digitalWrite(led3,HIGH);
  digitalWrite(led2,LOW);
}
if(x<200){
  digitalWrite(led1,LOW);
}
if(x>200){
  digitalWrite(led1,HIGH);
}}