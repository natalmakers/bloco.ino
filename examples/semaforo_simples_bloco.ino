/*
  Semaforo simples Bloco.ino

  Alterna entre dois leds conectados ao Arduino.

  
  Criado em 8 de Dezembro de 2019
  por NatalMakers.com
  
  Este exemplo de Código é de domínio público.

  http://www.arduino.cc/en/Tutorial/Blink
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

// indique abaixo o tempo que cada sinal deve ficar aceso (em segundos)
#define   TEMPO_VERDE_EM_SEGUNDOS   5
#define   TEMPO_VERMELHO_EM_SEGUNDOS   8






/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////





// a função de setup é executada apenas uma vez, quando o arduino é inicializado
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(PINO_DO_LED_VERMELHO, OUTPUT);
  pinMode(PINO_DO_LED_VERDE, OUTPUT);
}

// esta função roda continuamente
void loop() {
  digitalWrite(PINO_DO_LED_VERDE, HIGH);  
  delay(TEMPO_VERDE_EM_SEGUNDOS*1000);                     
  digitalWrite(PINO_DO_LED_VERDE, LOW);    

  digitalWrite(PINO_DO_LED_VERMELHO, HIGH);  
  delay(TEMPO_VERDE_EM_SEGUNDOS*1000);                     
  digitalWrite(PINO_DO_LED_VERMELHO, LOW);
}
