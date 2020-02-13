#include<WiFi.h>
#include<IOXhop_FirebaseESP32.h>
#define FIREBASE_HOST "iotexpertshub.firebaseio.com"
#define FIREBASE_AUTH "1gfWQGVuevSV5iiGTuetztral92GUAnyKk5ajkX0"
#define WIFI_SSID "sushanth"
#define WIFI_PASSWORD "UnoBetter"

String fireStatus ="";
int C1=0;//counts of the votes
int C2=0;
int C3=0;
int C4=0;
int C5=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(1,INPUT);
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(5,INPUT);
delay(1000);
WiFi.begin(WIFI_SSID,WIFI_PASSWORD);   // sending wifi username and password
Serial.print("Connecting to");
Serial.print(WIFI_SSID);
while(WiFi.status()!=WL_CONNECTED)
{
  Serial.print(".");
  delay(500);
}
Serial.println();
Serial.print("Connected to");
Serial.print("WIFI_SSID");
Serial.print("IP Address is :");
Serial.print(WiFi.localIP());
Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
Firebase.setInt("BJP",0);
Firebase.setInt("AAP",0);
Firebase.setInt("CONG",0);
Firebase.setInt("CPI",0);
Firebase.setInt("SWP",0);
}
void loop() 
{
int B1=digitalRead(1);
int B2=digitalRead(2);
int B3=digitalRead(3);
int B4=digitalRead(4);
int B5=digitalRead(5);
if (B1==1){
C1=C1+1;  
Firebase.pushInt("BJP",C1);   
}
if (B2==1){
C2=C2+1;  
Firebase.pushInt("AAP",C2);   
}
if (B3==1){
C3=C3+1;  
Firebase.pushInt("CONG",C3);   
}  
if (B4==1){
C4=C4+1;  
Firebase.pushInt("CPI",C4);   
}
if (B5==1){
C5=C5+1; 
Firebase.pushInt("SWP",C5);   
}   

  

 }
