
/*
  Controlando os motores de um robô com potenciometros Bloco.ino



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


/*

 EFETUE AS CONEXÕES CONFORME O PASSO A PASSO PARA O CONTROLE 
 
*/





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


int x = map(analogRead(A0),0,1023,-10,10);
int y = map(analogRead(A1),0,1023,-10,10);


analogWrite(in1,(x*25));
digitalWrite(in2,(x<0));

analogWrite(in4,(y*25));
digitalWrite(in3,(y<0));

delay(1);



}
