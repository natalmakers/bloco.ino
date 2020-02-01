/*
  Janela inteligente Bloco.ino

  Controla a abertura de uma janela conforme a temperatura de uma casa


  Criado em 8 de Dezembro de 2019
  por NatalMakers.com

  Este exemplo de Código é de domínio público.

*/


/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
// Esta é a área de parametrização do seu programa //////////
// Bloco.ino. Altere os parâmetros indicados abaixo /////////
// obter diferentes comportamentos em seu projeto  //////////
/////////////////////////////////////////////////////////////


// indique abaixo o numero do pino onde estão os leds
#define   PINO_SERVO_MOTOR       9
#define   PINO_SENSOR_DE_TEMPERATURA     A0

// calibrando os angulos do seu servo

#define   ANGULO_INICIAL       0
#define   ANGULO_FINAL         180

// definindo a temperatura de ativação

#define TEMPERATURA_ATIVACAO   30





/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////





#include "HardwareSerial.h"
// Temperature for nominal resistance (almost always 25 C)
#define TEMPERATURENOMINAL 25

// Number of ADC samples
#define NUMSAMPLES         5

// ADC resolution
#ifdef PANSTAMP_NRG
#define ADC_RESOLUTION 0xFFF
#else
#define ADC_RESOLUTION 1023
#endif
#define VERBOSE_SENSOR_ENABLED 1


#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = ANGULO_INICIAL;    // variable to store the servo position

void setup() {
  myservo.attach(PINO_SERVO_MOTOR);  // attaches the servo on pin 9 to the servo object
  myservo.write(pos);

  Serial.begin(9600);
}

void loop() {


  if ((temper() > (TEMPERATURA_ATIVACAO * 10)) && pos < ANGULO_FINAL) 
  {
    
    for (pos = ANGULO_INICIAL; pos <= ANGULO_FINAL; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    pos=ANGULO_FINAL;
  }
  if ((temper() < (TEMPERATURA_ATIVACAO * 10))&& pos > ANGULO_INICIAL)
  {
    for (pos = ANGULO_FINAL; pos >= ANGULO_INICIAL; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
     pos=ANGULO_INICIAL;
  }
  Serial.print("Temperatura atual = ");
  Serial.print(temper()/10.0);
  Serial.println(" graus celsius ");
  
  delay(2000);
}


int temper ()
{

  uint8_t analogPin = PINO_SENSOR_DE_TEMPERATURA;
  uint16_t nominalResistance = 10000;
  uint16_t bCoefficient = 3950;
  uint16_t serialResistance = 10000;

  uint8_t i;
  uint16_t sample;
  float average = 0;

  analogReference(DEFAULT);

  // take N samples in a row, with a slight delay
  for (i = 0; i < NUMSAMPLES; i++)
  {
    sample = analogRead(analogPin);
    average += sample;
    delay(10);
  }
  average /= NUMSAMPLES;

#ifdef VERBOSE_SENSOR_ENABLED
  //Serial.print("Average analog reading ");
  //Serial.println(average);
#endif

  // convert the value to resistance
  average = ADC_RESOLUTION / average - 1;
  average = serialResistance * average;

#ifdef VERBOSE_SENSOR_ENABLED
  //Serial.print("Thermistor resistance ");
  //Serial.println(average);
#endif

  float steinhart;
  steinhart = average / nominalResistance;     // (R/Ro)
#ifdef PANSTAMP_NRG
  steinhart = logf(steinhart);                 // ln(R/Ro)
#else
  steinhart = log(steinhart);                  // ln(R/Ro)
#endif
  steinhart /= bCoefficient;                   // 1/B * ln(R/Ro)
  steinhart += 1.0 / (TEMPERATURENOMINAL + 273.15); // + (1/To)
  steinhart = 1.0 / steinhart;                 // Invert
  steinhart -= 273.15;                         // convert to C

#ifdef VERBOSE_SENSOR_ENABLED
  //Serial.print("Temperature ");
  //Serial.print(steinhart);
  //Serial.println(" *C");
#endif

  return (int)(steinhart * 10);


}
