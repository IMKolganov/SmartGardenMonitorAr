#include "TaskSoilMoisture.h"
#include <ArduinoJson.h>

// Определение статического конструктора TaskSoilMoisture
static TaskSoilMoisture::TaskSoilMoisture(unsigned long interval)
    : Task(interval, TASK_FOREVER, nullptr) {
    // Реализация конструктора, если требуется
}

// Реализация метода Callback для TaskSoilMoisture
void TaskSoilMoisture::Callback() {
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
}
