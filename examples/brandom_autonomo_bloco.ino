#include <Ultrasonic.h>


/*
  Brandom Autonomo Bloco.ino

  Programa autonomo do Brandom


  Criado em 14 de Novembro de 2019
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

#define ULTRASSONICO_FIO_AMARELO  12
#define ULTRASSONICO_FIO_VERDE     13

// LEMBRE-SE DE CONECTAR OS FIOS 
// AZUL AO GND
// LARANJA AO 5V


//  aqui vc deve indicar com quantos centimetros do obstáculo 
// o Brandom precisa mudar de direção

#define DISTANCIA_DE_VISAO_EM_CM     15




/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////






/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////


const int motorA1 =  6;
const int motorA2  = 7;
const int motorB1 =  8;
const int motorB2 =  9;

const int voz = 2;

Ultrasonic ultrasonic(ULTRASSONICO_FIO_AMARELO, ULTRASSONICO_FIO_VERDE);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode( motorA1 , OUTPUT);
  pinMode( motorA2 , OUTPUT);

  pinMode( motorB1 , OUTPUT);
  pinMode( motorB2 , OUTPUT);
  pinMode( voz , OUTPUT);
}

void loop() {

 int p = random(1000);
  if (p < 30)
  {
      digitalWrite( voz, HIGH);      delay(10 + random(100));      digitalWrite( voz, LOW);       delay(20);
  }

  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();

  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);

  Serial.print(" CM: ");
  Serial.print(cmMsec);
  delay(40);

  int x = random(1000);
  if (x < 25)
  {

    byte palavra = 3 + random(20);
    for (byte i = 0; i < palavra; i++)
    {
      digitalWrite( voz, HIGH);
      delay(10 + random(100));
      digitalWrite( voz, LOW);
      delay(20);
    }
    digitalWrite( motorA1 , LOW); digitalWrite( motorA2 , HIGH); digitalWrite( motorB1 , HIGH); digitalWrite( motorB2 , LOW); delay(10*random(200));
    digitalWrite( voz, HIGH);      delay(10 + random(100));      digitalWrite( voz, LOW);       delay(20);
    digitalWrite( motorA1 , HIGH); digitalWrite( motorA2 , LOW); digitalWrite( motorB1 , HIGH); digitalWrite( motorB2 , LOW); delay(10*random(200));
    digitalWrite( voz, HIGH);      delay(10 + random(100));      digitalWrite( voz, LOW);       delay(20);

    digitalWrite( motorA1 , LOW); digitalWrite( motorA2 , HIGH); digitalWrite( motorB1 , HIGH); digitalWrite( motorB2 , LOW); delay(10*random(200));
    digitalWrite( voz, HIGH);      delay(10 + random(100));      digitalWrite( voz, LOW);       delay(20);

    digitalWrite( motorA1 , LOW); digitalWrite( motorA2 , HIGH); digitalWrite( motorB1 , LOW); digitalWrite( motorB2 , HIGH); delay(10*random(200));


  }

  if (cmMsec > DISTANCIA_DE_VISAO_EM_CM) {
    Serial.println("andando");
    digitalWrite( motorA1 , HIGH);
    digitalWrite( motorA2 , LOW);

    digitalWrite( motorB1 , HIGH);
    digitalWrite( motorB2 , LOW);

  }  else if (cmMsec <= DISTANCIA_DE_VISAO_EM_CM) {



    Serial.println("parando, virando");
    digitalWrite( motorA1 , LOW);
    digitalWrite( motorA2 , LOW);

    digitalWrite( motorB1 , LOW);
    digitalWrite( motorB2 , LOW);

    delay(500);

    byte palavra = 3 + random(20);
    for (byte i = 0; i < palavra; i++)
    {
      digitalWrite( voz, HIGH);
      delay(10 + random(100));
      digitalWrite( voz, LOW);
      delay(20);
    }



    // ATRAS
    digitalWrite( motorA1 , LOW);
    digitalWrite( motorA2 , HIGH);

    digitalWrite( motorB1 , LOW);
    digitalWrite( motorB2 , HIGH);

    delay(500);

    if (random(1, 11) < 6)
    {
      digitalWrite( motorA1 , LOW);
      digitalWrite( motorA2 , HIGH);

      digitalWrite( motorB1 , HIGH);
      digitalWrite( motorB2 , LOW);

      delay(100 * random(20));

    }
    else

    {

      digitalWrite( motorA1 , HIGH);
      digitalWrite( motorA2 , LOW);

      digitalWrite( motorB1 , LOW);
      digitalWrite( motorB2 , HIGH);

      delay(100 * random(20));


    }
  }
}
