

/*
  BOARD - NODEMCU ESP8266

  Apresenta o número sorteado em uma página após pressionar o
  botão flash, usando ajax.

  Autores:
  Antonio Braga (www.antonio.mobi)
  Thiago Ferauche (thiago.ferauche@gmail.com)

  Grupo: Santos Hacker Clube


*/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#ifndef APSSID
#define APSSID "SHC"
#define APPSK  "sorteio"
#endif


#include "index.h" // Incluir o arquivo index.h


int botaoSorteio = 0;
int randomSorteio;
const int botaosorteio = 0;
const char *ssid = APSSID;
const char *password = APPSK;

ESP8266WebServer server(80);

/* Acesse via navegador http://192.168.4.1
*/
void handleRoot() {
  String s = MAIN_page;
  server.send(200, "text/html", s); //envia
}

void handleADC() {
  int a = digitalRead(botaosorteio);
  String adcValue = String(a);
  botaoSorteio = digitalRead(botaosorteio);
  if ( botaoSorteio == LOW) {
    randomSorteio = random(0, 100);
    int x = randomSorteio;
    String sorteioValue = String(x);
    server.send(200, "text/plane", sorteioValue);
    delay (1000);
  }


}

void setup(void) {

  pinMode(0, INPUT_PULLUP);
  Serial.begin(115200);
  WiFi.softAP(ssid, password);
  delay(5000);
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  IPAddress myIP = WiFi.softAPIP();
  randomSeed(digitalRead(0));
  server.on("/", handleRoot);
  server.on("/readADC", handleADC);
  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();

}

/*
   Copyright (c) 2015, Majenko Technologies
   All rights reserved.

   Redistribution and use in source and binary forms, with or without modification,
   are permitted provided that the following conditions are met:

 * * Redistributions of source code must retain the above copyright notice, this
     list of conditions and the following disclaimer.

 * * Redistributions in binary form must reproduce the above copyright notice, this
     list of conditions and the following disclaimer in the documentation and/or
     other materials provided with the distribution.

 * * Neither the name of Majenko Technologies nor the names of its
     contributors may be used to endorse or promote products derived from
     this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
   ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
   (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
   LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
   ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
