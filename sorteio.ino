/*

  BOARD - NODEMCU ESP8266

  Aperte um botão e sorteie um número na porta serial.

  Press a button and generate a random number printed on serial port.

  Autor: Antonio Braga (www.antonio.mobi)


*/

int botaoSorteio = 0;
long randomSorteio;
const int botaosorteio = 0;

void setup() {
  Serial.begin(9600);
  pinMode(0, INPUT_PULLUP);
  delay(12000);
  Serial.println("PRESSIONE <FLASH> PARA SORTEAR UM NUMERO");

  randomSeed(digitalRead(0));

}

void loop() {

  botaoSorteio = digitalRead(botaosorteio);
  if ( == HIGH) {
    delay(10);

  } else {
    // Sorteia números de 0 - 50
    randomSorteio = random(0, 50);
    Serial.println(randomSorteio);
    delay(1000);
  }

}
