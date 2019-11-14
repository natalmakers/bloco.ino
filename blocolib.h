#ifndef BLOCOLIB_H
#define BLOCOLIB_H
#endif

#include "thermistor.h"
#include "HardwareSerial.h"
#include <Servo.h>

#define NTC_PIN       A0
#define SAIDA         1
#define ENRADA_IMPUT  0

int v = 0;
int v_old = 0;

Servo myservo;  // create servo object to control a servo
void EscreverNumeros(float n) {
  Serial.println(n);
}

void EscreverFrases(String n) {
  Serial.println(n);
}
//============delay=================
void Aguardar(float n) {
  delay(n * 1000);
}
//============delay=================

//===============LED===================
void ModoOperacao(byte n, byte m) {
  pinMode(n, m);
}

void LigarLed(byte n) {
  digitalWrite(n, 1);
}

void DesligarLed(byte n) {
  digitalWrite(n, 0);
}
//===============LED===================

//============Temperatura================
float LerTemperatura(byte pin) {

  byte NTC_PIN =  pin;
  THERMISTOR thermistor(NTC_PIN,        // Analog pin
                        10000,          // Nominal resistance at 25 ºC
                        3950,           // thermistor's beta coefficient
                        10000);         // Value of the series resistor
  uint16_t temp;

  temp = thermistor.read();

  float t = temp / 10.0;
  if (t > 32) {
    t = 32;
  }
  if (t < 20) {
    t = 20;
  }
  return t;

}
//============Temperatura================

int indicadorTemperatura(int n, byte m) {
  myservo.attach(m);

  v = map(n, 20, 32, 0, 180);

  if (v == myservo.read()) {
    Serial.println("igual");
  }
  else {
    if (v > myservo.read()) {
      for (int i = myservo.read(); i <= v; i++) {
        myservo.write(i);
        delay(100);
      }
    }
    if (v < myservo.read()) {
      for (int i = myservo.read(); i >= v; i--) {
        myservo.write(i);
        delay(100);
      }
    }
  }
  return v;
}
