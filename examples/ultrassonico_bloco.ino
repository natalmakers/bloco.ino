/*
  Sensor Ultrassonico Bloco.ino

  Mostra a medição de distâncias em centímetros com o sensor ultrassonico


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
#define   ULTRASSONICO_FIO_AMARELO       9
#define   ULTRASSONICO_FIO_VERDE       10
#define   INTERVALO_ENTRE_MEDICOES     2


// LEMBRE-SE DE CONECTAR OS FIOS 
// AZUL AO GND
// LARANJA AO 5V



/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////


//Variaveis para sensor ultrassonico

float TempoEcho=0;
const float VelocidadeSom_mpors = 340;//em metros por segundo
const float VelocidadeSom_mporus = 0.000340;//em metros por microsegundo
  
void setup()
{
 
   // configura pino de Trigger como saída e inicializa com nivel baixo
  pinMode(ULTRASSONICO_FIO_AMARELO,OUTPUT);
  digitalWrite(ULTRASSONICO_FIO_AMARELO,LOW); 
  pinMode(ULTRASSONICO_FIO_VERDE,INPUT);// configura pino ECHO como entrada
  
  Serial.begin(9600);
  delay(100);
  
 

}


void loop()
{
  float val;

   //Envia pulso para o disparar o sensor
   DisparaPulsoUltrassonico();
   //Mede o tempo de duracao do sinal no pino de leitura(us)
   TempoEcho = pulseIn(ULTRASSONICO_FIO_VERDE, HIGH);
   val = CalculaDistancia(TempoEcho);

   Serial.println(val);
   
  
  delay(INTERVALO_ENTRE_MEDICOES*1000);
}

//Funcao para enviar o pulso de trigger
void DisparaPulsoUltrassonico()
{
 // Para fazer o HC-SR04 enviar um pulso ultrassonico, nos temos
 // que enviar para o pino de trigger um sinal de nivel alto
 // com pelo menos 10us de duracao
 digitalWrite(ULTRASSONICO_FIO_AMARELO, HIGH);
 delayMicroseconds(10);
 digitalWrite(ULTRASSONICO_FIO_AMARELO, LOW);
 }
 
 //Funcao para calcular a distancia em metros
 float CalculaDistancia(float tempo_us)
 {  
   return ( 100*(tempo_us* VelocidadeSom_mporus) / 2 );
 }
