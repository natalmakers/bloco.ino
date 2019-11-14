#include "blocolib.h"
void setup() {
  
  Serial.begin(9600);

}

void loop() {
  int temp_externa = LerTemperatura(A0);
  int temp_interna = LerTemperatura(A1);
  //Função que para mostrar o valor de uma variavel no indicador gouge
  //indicadorTemperatura(entrada,saida);
  indicadorTemperatura(temp_externa,9);
  
}
