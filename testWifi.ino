#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include <WiFiClient.h>

WiFiClient client;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);Serial.println();

  WiFi.begin("Wifi_Printer", "uyock4699pe");
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println("Tidak konek... cobain lagi");
  }
  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
  }

void loop() {
  // put your main code here, to run repeatedly:

}
