#include <Servo.h>                //Inclui biblioteca do servo.
#include "DFRobotDFPlayerMini.h"  //Inclui biblioteca do modulo mp3.
#include "SoftwareSerial.h"       //Não sei.
#include "Ultrasonic.h"           //Inclui biclioteca sensor ultrasonico.

Servo tampa;  //Nomina o servo.
Servo mao;    //Nomina o servo.

//Variavel
int NumeroAleatorio;  //Define que o botão está liga na porta Analogica 0.
int NumeroAleatorioLed;
int NumeroAleatorioAcao;
int NumeroAleatorioFala;
int NumeroAleatorioFalaAprox;
int NumeroAleatorioAprox;
int botao = A0;   //Define que o botão está liga na porta Analogica 0.
int estadoBotao;  //Variavel que armazena se o botão está com valor em HIGH ou LOW.

//leds
int LedB = 8;
int LedR = 7;
int LedG = 12;

//vibracall
int VibraCall = 4;

//variaveis posição servos
int maoDentro = 10;  //Variavel que armazena o angulo do servo quando a mão está dentro.
int maoFora = 165;   //Variavel que armazena o angulo do servo quando a mão está fora.
int tampaAberta = 35;
int tampaFechada = 90;

//sensor ultrasonico.
Ultrasonic ultrassom(3, 2);
long distancia;

//Definições do modulo mp3.
#define pinRx 10
#define pinTx 11
#define volumeMP3 30
SoftwareSerial playerMP3Serial(pinRx, pinTx);
DFRobotDFPlayerMini playerMP3;

void setup() {
  Serial.begin(9600);

  pinMode(botao, INPUT);
  pinMode(LedR, OUTPUT);
  pinMode(LedG, OUTPUT);
  pinMode(LedB, OUTPUT);
  pinMode(VibraCall, OUTPUT);

  mao.attach(6);    //Define que o servo da mão está ligado ao pino 5.
  tampa.attach(9);  //Define que o servo da mão está ligado ao pino 3.

  //Define posição inicial dos servos ao ligar.
  mao.write(10);              //Dentro
  tampa.write(90);            //Fechada
  randomSeed(analogRead(1));  //Inicializa numero randomico.

  bemvindo();  //Chama o audio de boas vindas sempre que inicia a caixa.
}


void loop() {
  estadoBotao = analogRead(botao);  // Le o valor analogico do botão e armazena dentro da variavel estadoBotao.
  if (estadoBotao >= 1000) {
    botaoOff();
    ledStandByOn();
    Aprox();
  }

  else {
    botaoOn();
    ledStandByOff();
  }
}

void botaoOff() {
  mao.write(maoDentro);
  delay(200);
  tampa.write(tampaFechada);
}

void botaoOn() {
  NumeroAleatorioAcao = random(1, 16);
  while (NumeroAleatorioAcao == 1) {
    if (NumeroAleatorioAcao == 1) {
      falaAcao();
      Acao1();
      break;
    }
  }

  while (NumeroAleatorioAcao == 2) {
    if (NumeroAleatorioAcao == 2) {
      falaAcao();
      Acao2();
      break;
    }
  }
  while (NumeroAleatorioAcao == 3) {
    if (NumeroAleatorioAcao == 3) {
      falaAcao();
      Acao3();
      break;
    }
  }
  while (NumeroAleatorioAcao == 4) {
    if (NumeroAleatorioAcao == 4) {
      falaAcao();
      Acao4();
      break;
    }
  }
  while (NumeroAleatorioAcao == 5) {
    if (NumeroAleatorioAcao == 5) {
      falaAcao();
      Acao5();
      break;
    }
  }
  while (NumeroAleatorioAcao == 6) {
    if (NumeroAleatorioAcao == 6) {
      falaAcao();
      Acao6();
      break;
    }
  }
  while (NumeroAleatorioAcao == 7) {
    if (NumeroAleatorioAcao == 7) {
      falaAcao();
      Acao7();
      break;
    }
  }
   while (NumeroAleatorioAcao == 8) {
    if (NumeroAleatorioAcao == 8) {
      falaAcao();
      Acao8();
      break;
    }
  }
  while (NumeroAleatorioAcao == 9) {
    if (NumeroAleatorioAcao == 9) {
      falaAcao();
      Acao9();
      break;
    }
  }
   while (NumeroAleatorioAcao == 10) {
    if (NumeroAleatorioAcao == 10) {
      falaAcao();
      Acao10();
      break;
    }
  }
     while (NumeroAleatorioAcao == 11) {
    if (NumeroAleatorioAcao == 11) {
      falaAcao();
      Acao11();
      break;
    }
  }
   while (NumeroAleatorioAcao == 12) {
    if (NumeroAleatorioAcao == 12) {
      falaAcao();
      Acao12();
      break;
    }
  }
     while (NumeroAleatorioAcao == 13) {
    if (NumeroAleatorioAcao == 13) {
      falaAcao();
      Acao13();
      break;
    }
  }
       while (NumeroAleatorioAcao == 14) {
    if (NumeroAleatorioAcao == 14) {
      falaAcao();
      Acao14();
      break;
    }
  }
    while (NumeroAleatorioAcao == 15) {
    if (NumeroAleatorioAcao == 15) {
      falaAcao();
      Acao15();
      break;
    }
  }
}

void bemvindo() {
  digitalWrite(VibraCall, HIGH);
  digitalWrite(LedR, HIGH);
  delay(150);
  digitalWrite(VibraCall, LOW);
  delay(100);
  digitalWrite(VibraCall, HIGH);
  digitalWrite(LedR, LOW);
  digitalWrite(LedG, HIGH);
  delay(150);
  digitalWrite(VibraCall, LOW);
  delay(100);
  digitalWrite(VibraCall, HIGH);
  digitalWrite(LedG, LOW);
  digitalWrite(LedB, HIGH);
  delay(150);
  digitalWrite(VibraCall, LOW);
  delay(100);
  digitalWrite(VibraCall, HIGH);
  digitalWrite(LedB, LOW);
  digitalWrite(LedR, HIGH);
  delay(150);
  digitalWrite(VibraCall, LOW);
  delay(100);
  digitalWrite(VibraCall, HIGH);
  digitalWrite(LedR, LOW);
  digitalWrite(LedG, HIGH);
  delay(150);
  digitalWrite(VibraCall, LOW);
  delay(100);
  digitalWrite(VibraCall, HIGH);
  digitalWrite(LedR, HIGH);
  digitalWrite(LedG, HIGH);
  digitalWrite(LedB, HIGH);
  delay(1250);
  digitalWrite(VibraCall, LOW);
  digitalWrite(LedR, LOW);
  digitalWrite(LedG, LOW);
  digitalWrite(LedB, LOW);
  NumeroAleatorio = random(1, 11);  //Gera um numero aleatorio entre 1 e 10.
  playerMP3Serial.begin(9600);
  playerMP3.begin(playerMP3Serial);
  playerMP3.volume(volumeMP3);
  playerMP3.playFolder(1, NumeroAleatorio);
}
void ledStandByOn() {
  NumeroAleatorioLed = random(1, 8);
  if (NumeroAleatorioLed == 1) {
    digitalWrite(LedR, HIGH);
    digitalWrite(LedB, LOW);
    digitalWrite(LedG, LOW);
  }
  if (NumeroAleatorioLed == 2) {
    digitalWrite(LedR, LOW);
    digitalWrite(LedB, HIGH);
    digitalWrite(LedG, LOW);
  }
  if (NumeroAleatorioLed == 3) {
    digitalWrite(LedR, LOW);
    digitalWrite(LedB, LOW);
    digitalWrite(LedG, HIGH);
  }
  if (NumeroAleatorioLed == 4) {
    digitalWrite(LedR, HIGH);
    digitalWrite(LedB, HIGH);
    digitalWrite(LedG, LOW);
  }
  if (NumeroAleatorioLed == 5) {
    digitalWrite(LedR, HIGH);
    digitalWrite(LedB, LOW);
    digitalWrite(LedG, HIGH);
  }
  if (NumeroAleatorioLed == 6) {
    digitalWrite(LedR, LOW);
    digitalWrite(LedB, HIGH);
    digitalWrite(LedG, HIGH);
  }
  if (NumeroAleatorioLed == 7) {
    digitalWrite(LedR, HIGH);
    digitalWrite(LedB, HIGH);
    digitalWrite(LedG, HIGH);
  }
}
void ledStandByOff() {
  digitalWrite(LedB, LOW);
  digitalWrite(LedG, LOW);
  digitalWrite(LedR, LOW);
}

void Aprox(){
  int perto = ultrassom.Ranging(CM);
  NumeroAleatorioAprox = random(1,6);
  Serial.print(NumeroAleatorioAprox);
  if(NumeroAleatorioAprox == 1 || NumeroAleatorioAprox == 3 || NumeroAleatorioAprox == 5){
  if((perto > 10) && (perto < 20)){
    falaAprox();
  }
  }

}

void falaAprox(){
  NumeroAleatorioFalaAprox = random(1, 6);
  playerMP3.playFolder(3, NumeroAleatorioFalaAprox);
  delay(1000);
}

void falaAcao(){
  NumeroAleatorioFala = random(1, 31);
  playerMP3.playFolder(2, NumeroAleatorioFala);
}
void Acao1() {
  delay(1000);
  tampa.write(tampaAberta);
  delay(350);
  mao.write(maoFora);
  delay(550);
  mao.write(maoDentro);
  delay(350);
  tampa.write(tampaFechada);
}
void Acao2() {
  delay(1000);
  unsigned long startTime = millis();
  int i;
  int z = 0;
  digitalWrite(LedR, HIGH);
  digitalWrite(LedG, LOW);
  digitalWrite(LedB, LOW);
  for(i=0 ; i <= 6 ; i+=1){
  tampa.write(50);
  delay(200);
  tampa.write(90);
  delay(200);
  }
  while (millis() - startTime < 15000) {
    distancia = ultrassom.Ranging(CM);
    if (distancia >= 30) {
      tampa.write(90);
      mao.write(10);
    }
    if ((distancia <= 30) && (distancia >= 25)) {
      tampa.write(85);
      mao.write(10);
    }
    if ((distancia <= 25) && (distancia >= 20)) {
      tampa.write(75);
      mao.write(10);
    }
    if ((distancia <= 20) && (distancia >= 15)) {
      tampa.write(65);
      mao.write(10);
    }
    if ((distancia <= 15) && (distancia >= 10)) {
      tampa.write(50);
      delay(150);
      mao.write(110);
    }

    if (distancia < 10) {
      tampa.write(tampaAberta);
      delay(150);
      mao.write(maoFora);
      z=1;
    }
    if ((startTime >= 13500) && (z == 0)) {
      tampa.write(tampaAberta);
      delay(350);
      mao.write(maoFora);
      delay(350);
      mao.write(maoDentro);
      delay(350);
      tampa.write(tampaFechada);
      break;
  }
  }
}
void Acao3() {
  delay(1000);
  int angulo1;
  int angulo2;
  for (angulo1 = tampaFechada; angulo1 >= 0; angulo1 -= 1) {  // Comando que muda a posição do servo de 0 para 180°
    tampa.write(angulo1);                                     // Comando para angulo específico
    delay(35);
  }
  for (angulo2 = maoDentro; angulo2 <= 160; angulo2 += 1) {  // Comando que muda a posição do servo de 0 para 180°
    mao.write(angulo2);                                      // Comando para angulo específico
    delay(35);
  }
}
void Acao4() {
  delay(1000);
  int angulo1;
  int angulo2;
  digitalWrite(LedB, HIGH);
  digitalWrite(LedR, LOW);
  digitalWrite(LedG, LOW);
  for (angulo1 = tampaFechada; angulo1 >= 35; angulo1 -= 1) {  // Comando que muda a posição do servo de 0 para 180°
    tampa.write(angulo1);                                      // Comando para angulo específico
    delay(35);
  }
  for (angulo2 = maoDentro; angulo2 <= 150; angulo2 += 1) {  // Comando que muda a posição do servo de 0 para 180°
    mao.write(angulo2);                                      // Comando para angulo específico
    delay(35);
  }
  mao.write(110);
  digitalWrite(LedB, LOW);
  digitalWrite(LedR, HIGH);
  digitalWrite(LedG, LOW);
  digitalWrite(VibraCall, HIGH);
  delay(2000);
  mao.write(160);
  digitalWrite(VibraCall, LOW);
  delay(350);
  mao.write(maoDentro);
  delay(350);
  tampa.write(tampaFechada);
}
void Acao5() {
  delay(1000);
  int i;
  tampa.write(tampaAberta);
  delay(350);
  for (i = 0; i <= 15; i += 1) {
    mao.write(150);
    delay(100);
    mao.write(110);
    delay(100);
  }
  mao.write(160);
  tampa.write(tampaAberta);
  delay(350);
  mao.write(maoDentro);
  delay(350);
  tampa.write(tampaFechada);
}
void Acao6() {
  delay(1000);
  int i;
  digitalWrite(LedG, HIGH);
  digitalWrite(LedR, LOW);
  digitalWrite(LedB, LOW);
  digitalWrite(VibraCall, HIGH);
  delay(1500);
  digitalWrite(VibraCall, LOW);
  digitalWrite(LedG, LOW);
  for (i = 0; i <= 30; i += 1) {
    digitalWrite(LedR, HIGH);
    delay(50);
    digitalWrite(LedR, LOW);
    delay(50);
  }
  tampa.write(tampaAberta);
  delay(350);
  mao.write(maoFora);
  delay(350);
  mao.write(maoDentro);
  delay(350);
  tampa.write(tampaFechada);
}
void Acao7() {
  delay(1000);
  int i;
  for (i = 0; i <= 10; i += 1) {
    digitalWrite(LedR, HIGH);
    digitalWrite(LedG, LOW);
    digitalWrite(LedB, LOW);
    tampa.write(tampaAberta);
    delay(150);
    tampa.write(tampaFechada);
    digitalWrite(LedR, LOW);
    digitalWrite(LedG, LOW);
    digitalWrite(LedB, LOW);
    delay(150);
  }
  digitalWrite(VibraCall, HIGH);
  tampa.write(tampaAberta);
  delay(350);
  mao.write(maoFora);
  delay(350);
  mao.write(maoDentro);
  delay(250);
  tampa.write(tampaFechada);
  digitalWrite(VibraCall, LOW);
}
void Acao8() {
  delay(1000);
  int angulo2;
  digitalWrite(LedR, LOW);
  digitalWrite(LedG, LOW);
  digitalWrite(LedB, LOW);
  for (angulo2 = 35; angulo2 <= 90; angulo2 += 1) {  
    tampa.write(angulo2);
    delay(200);
  }
  delay(2000);
  digitalWrite(LedR, LOW);
  digitalWrite(LedG, LOW);
  digitalWrite(LedB, HIGH);
  tampa.write(tampaAberta);
  digitalWrite(LedR, LOW);
  digitalWrite(LedG, HIGH);
  digitalWrite(LedB, LOW);
  delay(350);
  mao.write(maoFora);
  digitalWrite(LedR, HIGH);
  digitalWrite(LedG, LOW);
  digitalWrite(LedB, LOW);
  delay(350);
  mao.write(maoDentro);
  digitalWrite(LedR, LOW);
  digitalWrite(LedG, LOW);
  digitalWrite(LedB, LOW);
  delay(250);
  tampa.write(tampaFechada);
}
void Acao9(){
  delay(1000);
  int i;
  int z;
   for (i = 0; i <= 15; i += 1) { 
    digitalWrite(LedR, HIGH);
    digitalWrite(LedG, LOW);
    digitalWrite(LedB, LOW);
    digitalWrite(VibraCall, HIGH);
    delay(100);
    digitalWrite(LedR, LOW);
    digitalWrite(VibraCall, LOW);
    delay(100);
  }
  tampa.write(tampaAberta);
  delay(350);
  mao.write(maoFora);
  delay(550);
  mao.write(maoDentro);
  delay(350);
  tampa.write(tampaFechada);
  for (z = 0; z <= 15; z += 1) { 
    digitalWrite(LedR, HIGH);
    digitalWrite(LedG, LOW);
    digitalWrite(LedB, LOW);
    digitalWrite(VibraCall, HIGH);
    delay(100);
    digitalWrite(LedR, LOW);
    digitalWrite(VibraCall, LOW);
    delay(100);
  }
}
void Acao10(){
  delay(1000);
  int angulo1;
  int angulo2;
  int i;
  delay(1500);
  digitalWrite(VibraCall, HIGH);
  delay(2000);
  for (angulo1 = tampaFechada; angulo1 >= 35; angulo1 -= 1) {
    tampa.write(angulo1);
    delay(35);
  }
  for (angulo2 = maoDentro; angulo2 <= 170; angulo2 += 1) {  
    mao.write(angulo2);                                   
    delay(35);
  }
  mao.write(maoDentro);
  delay(250);
  mao.write(maoFora);
  delay(250);
  mao.write(maoDentro);
  delay(350);
  tampa.write(tampaFechada);
  digitalWrite(VibraCall, LOW);
  for (i = 0; i <= 20; i += 1) {  
    digitalWrite(VibraCall, HIGH);
    digitalWrite(LedR, HIGH);
    digitalWrite(LedG, LOW);
    digitalWrite(LedB, LOW);
    delay(50);
    digitalWrite(VibraCall, LOW);
    digitalWrite(LedR, LOW);
    delay(50);
   }
}
void Acao11(){
  delay(1000);
  int i;
  for (i = 0; i <= 3; i += 1){
    tampa.write(tampaAberta);
    delay(150);
    tampa.write(tampaFechada);
    delay(150);
  }
  tampa.write(tampaAberta);
  delay(250);
  mao.write(maoFora);
  delay(350);
  mao.write(maoDentro);
  delay(350);
  tampa.write(tampaFechada);
}
void Acao12(){
  delay(1000);
 int angulo1;
 int i;
  for (angulo1 = tampaFechada; angulo1 >= 35; angulo1 -= 1) {
    tampa.write(angulo1);
    delay(35);
  }
  digitalWrite(VibraCall, HIGH);
  mao.write(150);
  delay(5000);
  digitalWrite(VibraCall, LOW);
  mao.write(maoFora);
  delay(150);
  mao.write(maoDentro);
  delay(350);
  tampa.write(tampaFechada);
  delay(2000);
  tampa.write(tampaAberta);
  delay(250);
  for (i = 0; i <= 10; i += 1){
    mao.write(140);
    delay(100);
    mao.write(100);
    delay(100);
  }
  mao.write(maoDentro);
  delay(350);
  tampa.write(tampaFechada);
}
void Acao13(){
  delay(1000);
  tampa.write(tampaAberta);
  delay(150);
  tampa.write(tampaFechada);
  delay(2000);
  tampa.write(tampaAberta);
  delay(350);
  mao.write(maoFora);
  delay(350);
  mao.write(maoDentro);
  delay(350);
  tampa.write(tampaFechada);
}
void Acao14(){
  delay(1000);
  int i = 0;
  unsigned long startTime = millis();
  while (millis() - startTime < 15000) {
    distancia = ultrassom.Ranging(CM);
    if (distancia >= 30) {
      tampa.write(90);
      mao.write(10);
    }
    if ((distancia <= 30) && (distancia >= 25)) {
      tampa.write(75);
      mao.write(10);
    }
    if ((distancia <= 25) && (distancia >= 20)) {
      tampa.write(65);
      mao.write(10);
    }
    if ((distancia <= 20) && (distancia >= 15)) {
      tampa.write(45);
      mao.write(10);
    }
    if ((distancia <= 15) && (distancia >= 10)) {
      tampa.write(10);
      delay(150);
      mao.write(110);
    }
     if ((distancia <= 10) && (distancia >= 5)) {
      tampa.write(tampaAberta);
      delay(150);
      mao.write(maoFora);
      i = 1;
    }
    if ((startTime >= 13500) && (i == 0)) {
      tampa.write(tampaAberta);
      delay(350);
      mao.write(maoFora);
      delay(350);
      mao.write(maoDentro);
      delay(350);
      tampa.write(tampaFechada);
      break;
    }
  }
}
void Acao15(){
  delay(1000);
  int i;
  for(i=0; i<=10; i+=1){
    tampa.write(70);
    delay(100);
    tampa.write(90);
    delay(100);
  }
  tampa.write(tampaAberta);
  delay(350);
  mao.write(maoFora);
  delay(350);
  mao.write(maoDentro);
  delay(350);
  tampa.write(tampaFechada);
}
