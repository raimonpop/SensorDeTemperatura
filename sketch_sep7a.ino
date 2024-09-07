// Libreria del sensor de temperatura
#include <DHT.h>

// Pin en la placa del sesnor de temperatura
#define DHTPIN 2

// Tipo de sensor de temperatura
#define DHTTYPE DHT11


// Inicializamos el sensor DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Inicializacion de el puerto serial del arduino 
  Serial.begin(9600);
  
  // Inicializacion de la recoleccion de datos del sensior
  dht.begin();
}

void loop() {

  delay(5000);  // Espera 5 segundos entre lecturas

  // Guardado de los datos en variables
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
