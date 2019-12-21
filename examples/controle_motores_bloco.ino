
/*
  controle de motores Bloco.ino

  exercício de controle do motor


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


// acionamento dos pinos de controle da ponte H
#define   MOTOR1_VALOR_A       0
#define   MOTOR1_VALOR_B       0
#define   MOTOR2_VALOR_A       0
#define   MOTOR2_VALOR_B       0



/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////



//motores
byte in1 = 9;
byte in2 = 8;
byte in3 = 7;
byte in4 = 6;


void setup() {

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  

}

void loop() {


digitalWrite(in1,MOTOR1_VALOR_A);
digitalWrite(in2,MOTOR1_VALOR_B);

digitalWrite(in4,MOTOR2_VALOR_A);
digitalWrite(in3,MOTOR2_VALOR_B);

delay(10);



}
