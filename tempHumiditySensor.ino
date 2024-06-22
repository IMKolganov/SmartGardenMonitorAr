#include <ArduinoJson.h>
#include <TaskScheduler.h>
#include "DHT.h"

extern Task taskTempHumidity;
extern DHT dht;

Task taskTempHumidity(2000, TASK_FOREVER, []() {
  float humidity = dht.readHumidity();      // Считываем влажность
  float temperature = dht.readTemperature(); // Считываем температуру
  JsonDocument doc;
  doc["sensor"] = "temp_humidity";
  if (!isnan(humidity) && !isnan(temperature)) {    
    doc["humidity"] = humidity;
    doc["temperature"] = temperature;
  } else {
    doc["error"] = "Failed to read temperature and humidity sensor";
  }
  
  serializeJson(doc, Serial);
  Serial.println();
});
