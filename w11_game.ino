#include <BluetoothSerial.h>
BluetoothSerial BT;  
int m=0;
int n=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  BT.begin("Galaxy A71");//請改名 
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(18,OUTPUT);
  pinMode(19,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (BT.available()) {
    //讀取藍芽資料
    String BTdata=BT.readString();
    
  if(BTdata=="p1 get one point" && m==0){
    digitalWrite(13,HIGH);
    m++;
  }
  else if(BTdata=="p1 get one point" && m==1){
    digitalWrite(12,HIGH);
    m=0;
  }
  
  if(BTdata=="p2 get one point"&& n==0){
    digitalWrite(18,HIGH);
    n++;
  }
  else if(BTdata=="p2 get one point" && n==1){
    digitalWrite(19,HIGH);
    n=0;
  }

  if(BTdata=="new game"){
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    digitalWrite(18,LOW);
    digitalWrite(19,LOW);
    m=0;
    n=0;
  }
  
    //顯示在序列視窗
    Serial.println(BTdata);
  }
  delay(1);
}
