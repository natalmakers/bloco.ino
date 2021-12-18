/*
  Velocidade Ultrassom Bloco.ino
  Realiza a medição da velocidade de um objeto que se aproxima do sensor ultrassônico
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


// indique abaixo o numero do pino onde estão os fios
#define   ULTRASSONICO_FIO_AMARELO     10
#define   ULTRASSONICO_FIO_VERDE       9
#define   SERVO_FIO_LARANJA            6

// Intervalo de tempo em segundos entre as medições
#define   INTERVALO_ENTRE_MEDICOES     0.1


// LEMBRE-SE DE CONECTAR OS DEMAIS FIOS
// AZUL (ULTRASSOM) AO GND
// LARANJA (ULTRASSOM) AO 5V
// MARROM (SERVO) AO GND
// VERMELHO (SERVO) AO 5V

float valant = 0;
float maximo = 0;
float minimo = 0;

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////


//Variaveis para sensor ultrassonico

float TempoEcho = 0;
const float VelocidadeSom_mpors = 340;//em metros por segundo
const float VelocidadeSom_mporus = 0.000343;//em metros por microsegundo

void setup()
{
  // configura pino de Trigger como saída e inicializa com nivel baixo
  pinMode(ULTRASSONICO_FIO_AMARELO, OUTPUT);
  digitalWrite(ULTRASSONICO_FIO_AMARELO, LOW);
  pinMode(ULTRASSONICO_FIO_VERDE, INPUT); // configura pino ECHO como entrada

  Serial.begin(9600);
  delay(100);

  analogWrite(SERVO_FIO_LARANJA, 0);
  delay(5000);
}

void loop()
{
  float val;
  float vel;

  //Envia pulso para o disparar o sensor
  DisparaPulsoUltrassonico();
  //Mede o tempo de duracao do sinal no pino de leitura(us)
  TempoEcho = pulseIn(ULTRASSONICO_FIO_VERDE, HIGH);
  val = CalculaDistancia(TempoEcho);

  vel = (val - valant) / 0.1;

  int angulo = (maximo <= 5) ? maximo * 50 : 250;

  analogWrite(SERVO_FIO_LARANJA, val * 2);
  Serial.print(maximo);
  Serial.print(" ");
  Serial.print(minimo);
  Serial.print(" ");

  Serial.println(vel);
  valant = val;
  maximo = (maximo > 5) ? 5 : maximo;

  maximo = (vel > maximo) ? vel : maximo - 0.1;
  minimo = (vel < minimo) ? vel : minimo + 0.1;

  delay(INTERVALO_ENTRE_MEDICOES * 1000);
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
  return ( -1 * (tempo_us * VelocidadeSom_mporus) / 2 );
}
