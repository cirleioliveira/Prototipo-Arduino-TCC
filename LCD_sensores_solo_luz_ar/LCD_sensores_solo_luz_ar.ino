#include <LiquidCrystal.h>
#include <Thermistor.h>

LiquidCrystal display_lcd(2,4,10,11,12,13);

const int pino_sensor = A2; // sensor umidade do solo

int valor_total = 1023; 
int valorUmidade = 0; 
float porcentagem = 0;

int pin_ldr = A1; // sensor de luminusidade
Thermistor temp(0); // sensor de temperatura

void setup() {
  display_lcd.begin(16,2);
  display_lcd.clear();
}

void loop() {
  // Sensor de umidade do solo
  valorUmidade = analogRead(pino_sensor); //recebe o valor que esta lendo no sensor
  porcentagem = (valorUmidade / (float)valor_total) * 100; 
  porcentagem = map(valorUmidade, 1023,0,0,100); // valor em porcentagem da umidade

  //display_lcd.print("Status: ");
  //Analisando o status do solo
  if(valorUmidade > 0 && valorUmidade < 400){
    display_lcd.setCursor(2,0);
    display_lcd.print("SOLO MOLHADO");
  }
  
  if(valorUmidade > 400 && valorUmidade < 800){
    display_lcd.setCursor(3,0);
    display_lcd.print("SOLO UMIDO");
  }
  
  if(valorUmidade > 800 && valorUmidade < 1023){
    display_lcd.setCursor(3,0); // Coluna 2, linha 0
    display_lcd.print("SOLO SECO");
  }
  
  //Mostra valor em porcentagem
  display_lcd.setCursor(3,1); // Coluna 2 linha 1
  display_lcd.print("EM: ");
  display_lcd.print(porcentagem);
  display_lcd.print("%");
  display_lcd.print(" ");
  
  delay(3000);
  display_lcd.clear();

  // Mostra a temperatura com o termistor
  int temperatura = temp.getTemp();
  display_lcd.setCursor(0,0);
  display_lcd.print("TEMP.: ");
  display_lcd.print(temperatura);
  display_lcd.write(B11011111); // simbolo de grau ºC
  display_lcd.print("C"); 

  // Mostra a luminosidade com o LDR
  int valor_ldr = analogRead(pin_ldr);
 // valor_ldr = map(valor_ldr, 1023,0,0,100);
  valor_ldr = map(valor_ldr, 0,1023,0,100);
  display_lcd.setCursor(0,1);
  display_lcd.print("LuzAMBIENTE:");
  display_lcd.print(valor_ldr);
  display_lcd.print("%");

  delay(3000);
  display_lcd.clear();
}
