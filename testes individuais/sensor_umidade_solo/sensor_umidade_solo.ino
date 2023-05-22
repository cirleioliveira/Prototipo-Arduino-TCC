const int pino_sensor = A0;
int valor_total = 1023; int valorUmidade = 0; float porcentagem = 0;

void setup() {
  Serial.begin(9600);
}
void loop() {
  valorUmidade = analogRead(pino_sensor);                             //recebe o valor que esta lendo no sensor
  porcentagem = (valorUmidade / (float)valor_total) * 100;

  //Analisando o status do solo
  Serial.print("Status do solo: ");

  if(valorUmidade > 0 && valorUmidade < 400){
    Serial.print(" esta MOLHADO.");
  }
    if(valorUmidade > 400 && valorUmidade < 800){
    Serial.print(" esta UMIDO.");
  }
    if(valorUmidade > 800 && valorUmidade < 1023){
    Serial.print(" esta SECO.");
  }
   //Mostra valor em porcentagem
   Serial.print(" Percentual da umidade: ");
  Serial.print(porcentagem);
  Serial.print("%");
  Serial.println(" ");
  delay(60000);
}
  
  //Mostra a porta analogica
  /*Serial.print("| Porta analogico: ");
  Serial.print(valorLido);
  Serial.println(" "); 
  delay(1000);
}*/
