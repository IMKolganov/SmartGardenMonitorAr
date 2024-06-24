#include "TaskTempHumidity.h"
#include <ArduinoJson.h>

TaskTempHumidity::TaskTempHumidity(unsigned long interval, DHT* dht)
    : Task(interval, TASK_FOREVER, nullptr), dht(dht), temperature(NAN), humidity(NAN) {
}

void TaskTempHumidity::Callback() {
    humidity = dht->readHumidity();
    temperature = dht->readTemperature();

    JsonDocument doc;
    doc["sensor"] = "temp_humidity";
    if (!isnan(humidity) && !isnan(temperature)) {    
        doc["humidity"] = humidity;
        doc["temperature"] = temperature;
    } else {
        doc["error"] = "Failed to read temperature and humidity sensor";
    }

    //serializeJson(doc, Serial);
    //Serial.println();
}

float TaskTempHumidity::getTemperature() {
    return temperature;
}

float TaskTempHumidity::getHumidity() {
    return humidity;
}
