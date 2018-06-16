#include <ESP8266WiFi.h>

const char* ssid = "Familia Castellon Pineda 2";
const char* password = "Adri51797538";

const char* host = "provincial-receptac.000webhostapp.com";
String url = "/esp.php";


void setup(){
  Serial.begin(115200);
  Serial.println();
  pinMode(2,OUTPUT); 
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");
  
}
void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client;
  if (client.connect(host, 80)){
    client.print(String("GET /") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n" +
                 "\r\n"
                );
    while (client.connected()){
      if (client.available()){
        String line = client.readStringUntil('\n');
        int estado=line.indexOf("ñ");
        String res=line.substring(estado);
        if(res==("ñ1")){
          digitalWrite(2,HIGH);
          }if(res==("ñ0")){
          digitalWrite(2,LOW);
          }
      }
    }
    client.stop();
  }
  else
  {
    client.stop();
  }

}
