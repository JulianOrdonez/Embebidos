/*#include <Arduino.h>

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
*/
#include <Wire.h>
#include <Arduino.h>
#include <SHTSensor.h>

SHTSensor sht;
// Para usar un sensor especifico en vez de probar el bus use este comando:
// SHTSensor sht(SHTSensor::SHT3X);

void setup() {

  Wire.begin();
  Serial.begin(115200);
  delay(100); // Retardo para permitir que el puerto serie se ajuste

  if (sht.init()) {
      Serial.print("init(): Exitoso\n");
  } else {
      Serial.print("init(): Fallido\n");
  }
  sht.setAccuracy(SHTSensor::SHT_ACCURACY_MEDIUM); // only supported by SHT3x

}

void loop() {
  
  if (sht.readSample()) {
      Serial.print("SHT:\n");
      Serial.print("  RH: ");
      Serial.print(sht.getHumidity(), 2);
      Serial.print("\n");
      Serial.print("  T:  ");
      Serial.print(sht.getTemperature(), 2);
      Serial.print("\n");
  } else {
      Serial.print("Error en readSample()\n");
  }

  delay(1000);
}