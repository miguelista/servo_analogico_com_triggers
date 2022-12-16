// C++
/*-------------------------|
|---VALORES E DEFINIÇÕES---|
|-------------------------*/
#include "Servo.h"

/*LEIA POR FAVOR!-------------------------------|
|Professor, coloquei um resistor de 1000 ohms---|
|no buzzer para que ele não faça muito barulho,-|
|fora isso, não fiz nada de anormal no projeto-*/


Servo servomotor; //define o servo

const int pino_ledvermelho = 2; //pino led vermelho
const int pino_ledazul = 3; //pino led azul
const int buzzer = 4; //Atribui o valor 4 a variavel buzzer
const int pino_potenciometro = A5;  // connecta o pino analógico

int potenciometro; //armazena o valor do potenciometro





/*------------------------|
|----------SETUP----------|
|------------------------*/
void setup()  
{
  
    Serial.begin(9600); //rellógio interno

  
    // saidas // 
   	pinMode(LED_BUILTIN, OUTPUT); //led integrado
  
	pinMode(pino_ledvermelho, OUTPUT); //LEDS
  	pinMode(pino_ledazul, OUTPUT); 

	pinMode(4, OUTPUT); //buzzer
  
  	servomotor.attach(5); //conecta o servo
   	servomotor.write(0); //define seu valor base como 0
  
  
}

/*-------------------------|
|----------CODIGO----------|
|-------------------------*/
void loop()
  
 
  
{
	{
	//pisca a luz do arduino. deixei aqui
  	digitalWrite(LED_BUILTIN, HIGH);
  	delay(1000); 
  	digitalWrite(LED_BUILTIN, LOW);
  	delay(1000);  
      
  }
  
  potenciometro = analogRead(pino_potenciometro);
  //lê o valor do potenciometro (valor entre 0 e 1023)
  
  
  potenciometro = map(potenciometro, 0, 1023, 0, 180); 
  //escala o valor para o utilizar com o servo (entre 0 e 180)
  
  servomotor.write(potenciometro);
  //Ajusta a posição do servo de acordo com o valor do potenciometro
  
  
  Serial.println(potenciometro);
  /*me diz o valor do potenciometro em graus. Usado durante o 
  desenvolvimento. deixei aqui porque achei legal*/
  
  	//trigger de 90 graus
 	if(potenciometro >= 90 && potenciometro < 150) {
    digitalWrite(pino_ledazul, HIGH); // liga o LED
    tone(buzzer, 200); //liga o buzzer; 200hz
    delay(1000);
    noTone(buzzer); //desliga o buzzer
	digitalWrite(pino_ledazul, LOW); // desliga o LED
   	}
  
  
    //trigger de 150 graus
  	if(potenciometro >= 150) {
    digitalWrite(pino_ledvermelho, HIGH); // liga o LED
    tone(buzzer, 800); //liga o buzzer; 800hz
    delay(1000);
    noTone(buzzer); //desliga o buzzer
	digitalWrite(pino_ledvermelho, LOW); // desliga o LED
	}
  
  
  delay(500);
  // espera um segundo
    

  
}