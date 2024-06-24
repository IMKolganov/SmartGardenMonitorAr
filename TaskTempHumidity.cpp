#include "TaskTempHumidity.h"
#include <ArduinoJson.h>

// Определение статического конструктора TaskTempHumidity
static TaskTempHumidity::TaskTempHumidity(unsigned long interval, DHT* dht)
    : Task(interval, TASK_FOREVER, nullptr), dht(dht) {
    // Реализация конструктора, если требуется
}

// Реализация метода Callback для TaskTempHumidity
void TaskTempHumidity::Callback() {
    float humidity = dht->readHumidity();      // Считываем влажность
    float temperature = dht->readTemperature(); // Считываем температуру
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
}
