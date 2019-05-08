
#include <SoftwareSerial.h>
#include <DHT.h>
#define DHTPIN PIN_PC0
#define DHTTYPE DHT11
#define P_SENSOR PIN_PB0
#define F_SENSOR PIN_PB3
#define G_LED PIN_PC2
#define Y_LED PIN_PC3
#define R_LED PIN_PC4
#define O_LED PIN_PB2
DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial mySerial(PIN_PD1, PIN_PD0); // TX, RX
uint8_t counter;
void setup()
{
  mySerial.begin(9600);
  mySerial.println("DHTxx test!");
  pinMode(P_SENSOR,INPUT);
  pinMode(F_SENSOR,INPUT);
  pinMode(G_LED,OUTPUT);
  pinMode(Y_LED,OUTPUT);
  pinMode(O_LED,OUTPUT);
  pinMode(R_LED,OUTPUT);
  //pinMode(PIN_PD3,OUTPUT);
  counter = 50;
  dht.begin();  
}
void loop()
{
  // set h/t condition after model finished!!
   float h = dht.readHumidity();
   float t = dht.readTemperature();
   int n = digitalRead(P_SENSOR);
   int f = digitalRead(F_SENSOR);
   mySerial.print(n);
   mySerial.print("\t");
   mySerial.print(f);
   mySerial.print("\t");
   
   if(n == 0){
    digitalWrite(PIN_PB2, HIGH);
    }
    else{
      digitalWrite(PIN_PB2, LOW);
    }
   if(f==1){
    digitalWrite(R_LED, HIGH);
   }else{
    digitalWrite(R_LED, LOW);
   }
  if(!isnan(h)&&!isnan(t)){
     mySerial.print(h);
     mySerial.print("\t");
     mySerial.print(t);
    mySerial.print("\t");
     if(h<40 || t > 40){
      digitalWrite(Y_LED, HIGH);
      digitalWrite(G_LED, LOW);
     }
     else{
      digitalWrite(Y_LED, LOW);
      digitalWrite(G_LED, HIGH);
     }
  }
  else{
     mySerial.print("\0");
     mySerial.print("\t");
     mySerial.print("\0");
     mySerial.print("\t");
  }
  
  mySerial.println();
}
