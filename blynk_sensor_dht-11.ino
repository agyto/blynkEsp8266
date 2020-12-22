#define BLYNK_PRINT Serial
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

/*
 * PERHATIAN !
 * Sketch -> include library -> manage libraries; dan install library "Dht for esp"
 * Konfigurasikan pengaturan dibawah ini
*/
char token[] = "Token blynk dari email";
char WifiSSID[] = "Nama hotspot";
char Pass[] = "Password hotspot";
#define DHTTYPE DHT11 // Sensor yang akan diakses yaitu DHT11, DHT22, AM2303, AM2321, DHT21, atau AM2301
#define DHTPIN 4 //Pin yang dijadikan pembacaan sensor yaitu pada pin digital 4

/* ---------------------------------------------------------------------------------- */

DHT dht(DHTPIN, DHTTYPE); 
BlynkTimer timer;

void cekSuhuDanKelembapan()
{
  float h = dht.readHumidity(); //pembacaan kelembaban
  float t = dht.readTemperature(); //pembacaan suhu

  if (isnan(h) || isnan(t)) {
    Serial.println("Gagal membaca data dari sensor DHT");
    return;
  }

  Blynk.virtualWrite(V0, t);
}

void setup()
{
  // Aktifkan debug
  Serial.begin(9600);
  Serial.println("Debugging information:");
  Serial.setDebugOutput(true);

  Blynk.begin(token, WifiSSID, Pass, "blynk-cloud.com", 8080);
  dht.begin();
  timer.setInterval(1000L, cekSuhuDanKelembapan);
}

void loop()
{
  Blynk.run();
  timer.run();
}
