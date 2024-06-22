#include <ArduinoJson.h>
#include <TaskScheduler.h>

extern Task taskSoilMoisture;
extern DHT dht;

Task taskSoilMoisture(1000, TASK_FOREVER, []() {
  int soilMoisture = analogRead(A0);  // Считываем данные с датчика влажности почвы
  JsonDocument doc;
  
  doc["sensor"] = "soil_moisture";
  if (soilMoisture >= 0 && soilMoisture <= 550) {
    doc["value"] = soilMoisture;
  } else {
    doc["error"] = "Failed to read soil moisture sensor";
  }
  
  serializeJson(doc, Serial);         
  Serial.println();
});
