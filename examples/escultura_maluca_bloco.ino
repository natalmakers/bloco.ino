/*
  Escultura Maluca Bloco.ino

  Sorteia entre dois leds conectados ao Arduino.


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
#define   PINO_DO_LED_VERMELHO  5
#define   PINO_DO_LED_VERDE     10

/*
   Regras do jogo:
  O jogo consiste na construção de uma escultura composta apenas por duas cores de peças: verdes e vermelhas.
  Os dois participantes devem combinar de antemão o que será a escultura (uma casa, uma pessoal, um animal, um caramanchão, um personagem, etc)
  Os jogadores devem alternar-se na colocação das peças e a cada rodada o arduino deve ser inicializado para escolher uma cor de peça a ser colocada.


*/




/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////



int num = 0;

// a função de setup é executada apenas uma vez, quando o arduino é inicializado
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(PINO_DO_LED_VERMELHO, OUTPUT);
  pinMode(PINO_DO_LED_VERDE, OUTPUT);

  Serial.begin(9600);

  randomSeed(analogRead(A0));

  long randNumber = random(20) + 20;

  Serial.println(randNumber);
  Serial.println(randNumber % 2);

  num = randNumber % 2;
  for (; randNumber > 0; randNumber--)
  {
    digitalWrite(PINO_DO_LED_VERDE, LOW);
    digitalWrite(PINO_DO_LED_VERMELHO, LOW);

    if ((randNumber % 2) == 1)
    {
      digitalWrite(PINO_DO_LED_VERDE, HIGH);

    }
    else
    {
      digitalWrite(PINO_DO_LED_VERMELHO, HIGH);

    }

    delay(200 - randNumber * 5);

  }


}

// esta função roda continuamente
void loop() {

  long rand2 = random(100);
  if (rand2 < 10) num = 2;
  while (1) {
    digitalWrite(PINO_DO_LED_VERDE, LOW);
    digitalWrite(PINO_DO_LED_VERMELHO, LOW);
    delay(500);
    if (num == 1)
    {
      digitalWrite(PINO_DO_LED_VERDE, HIGH);

      Serial.println("acende led verde");

    }
    else if (num == 0)
    {
      digitalWrite(PINO_DO_LED_VERMELHO, HIGH);
      Serial.println("acende led vermelho");

    } else
    {
      digitalWrite(PINO_DO_LED_VERMELHO, HIGH);
      digitalWrite(PINO_DO_LED_VERDE, HIGH);
      Serial.println("acende os dois leds");
    }

    delay(500);
  }

}
