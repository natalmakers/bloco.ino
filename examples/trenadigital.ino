
// indique abaixo o numero do pino onde estão os leds
#define   ULTRASSONICO_FIO_AMARELO       8
#define   ULTRASSONICO_FIO_VERDE       10
#define   INTERVALO_ENTRE_MEDICOES     1


// LEMBRE-SE DE CONECTAR OS FIOS
// AZUL AO GND
// LARANJA AO 5V

//Variaveis para sensor ultrassonico

float TempoEcho = 0;
const float VelocidadeSom_mpors = 340;//em metros por segundo
const float VelocidadeSom_mporus = 0.000340;//em metros por microsegundo

#include <Servo.h>

Servo myservo;  // Obje

int pos = 0;    // variable to store the servo position

void setup() {

  pinMode(ULTRASSONICO_FIO_AMARELO, OUTPUT);
  digitalWrite(ULTRASSONICO_FIO_AMARELO, LOW);
  pinMode(ULTRASSONICO_FIO_VERDE, INPUT); // configura pino ECHO como entrada

  Serial.begin(9600);
  delay(100);

  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  float val;

  //Envia pulso para o disparar o sensor
  DisparaPulsoUltrassonico();
  //Mede o tempo de duracao do sinal no pino de leitura(us)
  TempoEcho = pulseIn(ULTRASSONICO_FIO_VERDE, HIGH);
  val = CalculaDistancia(TempoEcho);

  Serial.print(val);
  Serial.print(" ");
  int pos = 0;
  pos = map((int)val, 0, 200, 180, 0 );

  Serial.println(pos);



  delay(INTERVALO_ENTRE_MEDICOES * 100);

  myservo.write(pos);              // tell servo to go to position in variable 'pos'
  delay(15);                       // waits 15 ms for the servo to reach the position

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
  return ( 100 * (tempo_us * VelocidadeSom_mporus) / 2 );
}
