/*
  potenciometro mostrador analogico Bloco.ino

  Controla o movimento do ponteiro de um mostrador
  por meio do valor inserido pelo potenciomentro

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
#define   PINO_POTENCIOMETRO     A0






/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////



#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = PINO_POTENCIOMETRO;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(PINO_SERVO_MOTOR);  
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}
