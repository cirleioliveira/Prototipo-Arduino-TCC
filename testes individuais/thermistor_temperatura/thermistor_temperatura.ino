// Com resistor de 10K
#include <Thermistor.h>                                 //INCLUSÃO DA BIBLIOTECA
 
Thermistor temp(0);                                     //VARIÁVEL DO TIPO THERMISTOR, INDICANDO O PINO ANALÓGICO (A0) EM QUE O TERMISTOR ESTÁ CONECTADO

void setup() {
  Serial.begin(9600);                                  //INICIALIZA A SERIAL
  //delay(1000);                                      //INTERVALO DE 1 SEGUNDO
}
void loop() {
  int temperatura = temp.getTemp();                   //VARIÁVEL DO TIPO INTEIRO QUE RECEBE O VALOR DE TEMPERATURA CALCULADO PELA BIBLIOTECA
  Serial.print("Temperatura: ");                      //IMPRIME O TEXTO NO MONITOR SERIAL
  Serial.print(temperatura);                          //IMPRIME NO MONITOR SERIAL A TEMPERATURA MEDIDA
  Serial.println("°C");                               //IMPRIME O TEXTO NO MONITOR SERIAL
  delay(3000);                                        //INTERVALO DE 1 SEGUNDO
}
