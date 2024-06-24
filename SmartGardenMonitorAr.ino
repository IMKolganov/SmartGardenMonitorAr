#include "RequestTempHumidity.h"
#include "RequestSoilMoisture.h"
#include <ArduinoJson.h>

#define DHT_PIN 7
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

RequestTempHumidity requestTempHumidity(&dht, 6000);
RequestSoilMoisture requestSoilMoisture(5000);

void setup() {
    Serial.begin(9600);
    dht.begin();    
}

void loop() {
  if (Serial.available() > 0) {
    String jsonString = Serial.readStringUntil('\n');
    
    JsonDocument requestDoc;
    DeserializationError error = deserializeJson(requestDoc, jsonString);
  
    if (error) {
        Serial.println("Error parsing JSON request");
        return;
    }
  
    String idrequest = requestDoc["idrequest"].as<String>();
    const char* sensor = requestDoc["sensor"];
  
    JsonDocument responseDoc;
    responseDoc["idrequest"] = idrequest;
  
    if (strcmp(sensor, "temp_humidity") == 0) {
      requestTempHumidity.handleRequest(requestDoc, responseDoc);
    } else if (strcmp(sensor, "soil_moisture") == 0) {
      requestSoilMoisture.handleRequest(requestDoc, responseDoc);
    } else {
      responseDoc["status"] = "unknown sensor";
    }
  
    serializeJson(responseDoc, Serial);
      Serial.println();
  }

  // Пример задержки
  delay(1000);
}
