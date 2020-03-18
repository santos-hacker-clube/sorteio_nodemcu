rar/*

  BOARD - NODEMCU ESP8266

  Apresenta o número sorteado em uma página após pressionar o 
  botão flash
  
  Autores: 
    Antonio Braga (www.antonio.mobi)
    Thiago Ferauche (thiago.ferauche@gmail.com)

  Grupo: Santos Hacker Clube
  
*/

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "ESP-sorteio";
const char* pass = "sorteio";

IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

ESP8266WebServer server(80);

int botaoSorteio = 0;
long randomSorteio = 0;
const int botaosorteio = 0;

void setup() {
  Serial.begin(9600);
  pinMode(0, INPUT_PULLUP);
  delay(1000);
  
  Serial.println("Setando o NodeMcu como soft-AP...");
  WiFi.softAP(ssid, pass);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  
  //rotas do servidor
  //rota para raiz /
  server.on("/", handle_OnConnect);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("Servidor iniciado!");
  
  Serial.println("PRESSIONE <FLASH> PARA SORTEAR UM NUMERO");

  randomSeed(digitalRead(0));

}

void loop() {

  botaoSorteio = digitalRead(botaosorteio);
  if ( botaoSorteio == HIGH) {
    delay(10);

  } else {
    // Sorteia números de 0 - 50
    randomSorteio = random(0, 50);
    Serial.println(randomSorteio);
    delay(1000);
  }

  server.handleClient();
}

void handle_OnConnect() {
  Serial.println(randomSorteio);
  server.send(200, "text/html", SendHTML(randomSorteio));
}

void handle_NotFound() {
  server.send(404, "text/plain", "HTTP 404 - Not Found");
}

String SendHTML(long number) {
  String ptr = "<!DOCTYPE HTML><html>\n";
  ptr += "<head>\n";
  ptr += "</head>\n";
  ptr += "<body>\n";
  ptr += "<h2> ESP8266 Sorteio</h2>\n";
  ptr += "<p> Numero sorteado: ";
  ptr.concat(number);
  ptr += "</p>\n";
  ptr += "</body>\n";
  ptr += "</html>";
  return ptr;
}
