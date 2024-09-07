// Libreria del sensor de temperatura
// Libreria del sensor de temperatura
#include <DHT.h>

#define DHTPIN 2

#define DHTTYPE DHT11


// Inicializamos el sensor DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  dht.begin();
}

void loop() {

  delay(5000);  // Espera 5 segundos entre lecturas

  // put your main code here, to run repeatedly:
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  // Verificar si los valores son válidos antes de enviarlos
  if (isnan(t) || isnan(h)) {
    Serial.println("Error al leer los datos del sensor");
    return;
  }

  // Construcción del JSON correctamente formateado
  String json = "{ \"temperature\": " + String(t) + ", \"humidity\": " + String(h) + " }";
  
  // Enviar el JSON por el puerto serie
  Serial.println(json);
  
}
