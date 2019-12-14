/*
  Cronometro Bloco.ino

  Cria um contador de tempo para exercícios com prazos

  Criado em 8 de Desembro de 2019
  por NatalMakers.com

  Este exemplo de Código é de domínio público.

*/


/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
// Esta é a área de parametrização do seu programa //////////
// Bloco.ino. Altere os parâmetros indicados abaixo /////////
// obter diferentes comportamentos em seu projeto  //////////
/////////////////////////////////////////////////////////////


// indique abaixo o numero do servo e o tempo do cronometro
#define   PINO_SERVO_MOTOR       9
#define   TEMPO_EM_SEGUNDOS     30







/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////



#include <Servo.h>



Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {

  myservo.attach(PINO_SERVO_MOTOR);
  
  for (int i = 0; i < 180; ++i) { myservo.write(i); delay(10);}
  for (int i = 180; i >0; --i) { myservo.write(i); delay(10);}
}

void loop() {

  for (int i = 0; i < 180; ++i) { myservo.write(i); delay(6*TEMPO_EM_SEGUNDOS);}

  for (int i = 180; i >0; --i) { myservo.write(i); delay(1);}



  


}
