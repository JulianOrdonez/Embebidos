#include <Arduino.h>

// put function declarations here:
int numero=10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("numero ="+String(numero));//Imprime numero 10
  duplicar(&numero);//[]
  delay(1000);
}

void duplicar(int * puntero){
  * puntero = * puntero * 2;
  Serial.print("numero ="+String(numero));
}
