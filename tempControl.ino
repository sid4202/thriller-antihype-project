#include <TroykaDHT.h>

int motorOut = 11;
int tempOut = 10;
int dhtOut = 4;

DHT dht(dhtOut, DHT11);

float temp;
float tempDiff = 4.00;
bool firstTemp=true;

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(tempOut, OUTPUT);
  pinMode(motorOut, OUTPUT);
  digitalWrite(tempOut, HIGH);
}

void loop() {
  delay(1000);
  dht.read();
  if(firstTemp&&dht.getTemperatureC()>0.00){
    temp = dht.getTemperatureC();
    firstTemp=false;
  }
  Serial.println("| Temperature " + String(dht.getTemperatureC()) + " C | Needed " + String(temp-dht.getTemperatureC()+tempDiff) + " C | Started from " + String(temp) +" C |" );
  if(dht.getTemperatureC()-temp>=tempDiff){
    digitalWrite(motorOut, HIGH);
  }
  else{
    digitalWrite(motorOut, LOW);
  }
}