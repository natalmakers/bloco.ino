/*
  Controlando os motores de um robô com joystick Bloco.ino
  Criado em 16 de Dezembro de 2021
  por NatalMakers.com
  Este exemplo de Código é de domínio público.
*/
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
// Esta é a área de parametrização do seu programa //////////
// Bloco.ino. Altere os parâmetros indicados abaixo /////////
// obter diferentes comportamentos em seu projeto  //////////
/////////////////////////////////////////////////////////////
/*
 EFETUE AS CONEXÕES CONFORME O PASSO A PASSO PARA O CONTROLE 
*/

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

//Joystick
#define PINO_JOYSTICK_X A0
#define PINO_JOYSTICK_Y A1
#define PINO_BOTAO_JOYSTICK  12

//Motores
byte in1 = 9;
byte in2 = 8;
byte in3 = 7;
byte in4 = 6;

//Buzzer
#define buzzer 3

int x;
int y;

void setup() {
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(PINO_BOTAO_JOYSTICK,INPUT_PULLUP);
}

void loop() {

  x = map(analogRead(PINO_JOYSTICK_X), 0, 1023, 10, -10);
  y = map(analogRead(PINO_JOYSTICK_Y), 0, 1023, 10, -10);
  if (x < 4 && x > -4) {
    x = 0;
  }
  if (y < 4 && y > -4) {
    y = 0;
  }
  if (x != 0) {
    analogWrite(in1, x * 25);
    analogWrite(in4, x * 25);
    digitalWrite(in2, (x < 0));
    digitalWrite(in3, (x < 0));
  }
  if (y > 0) {
    analogWrite(in4, y * 25);
    digitalWrite(in3, 0);
    digitalWrite(in1, 0);
    digitalWrite(in2, 0);
  }
  if (y < 0) {
    analogWrite(in1, abs(y * 25));
    digitalWrite(in2, 0);
    digitalWrite(in3, 0);
    digitalWrite(in4, 0);
  }
  if (x == 0 && y == 0) {
    digitalWrite(in2, 0);
    digitalWrite(in4, 0);
    digitalWrite(in3, 0);
    digitalWrite(in1, 0);
  }

  delay(10);

  if(digitalRead(PINO_BOTAO_JOYSTICK)==LOW){
    tone(buzzer,392);
    }
    else{
      noTone(buzzer);
      }
}
