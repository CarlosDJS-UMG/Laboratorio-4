#include <DHT.h>
#include <DHT_U.h>
#define Type DHT11

int dt = 1000;
int pintemp = 2;
DHT HT(pintemp, Type);

float valhum;
float valtempC;
float valtempF;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HT.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  valhum = HT.readHumidity();
  valtempC = HT.readTemperature();
  valtempF = HT.readTemperature(true);
  Serial.print("La humedad realtiva es de: ");
  Serial.print(valhum);
  Serial.print("% / Temperatura: ");
  Serial.print(valtempC);
  Serial.print("°C / ");
  Serial.print(valtempF);
  Serial.println("°F");
  delay(dt);
}