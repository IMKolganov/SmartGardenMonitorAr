#include "RequestTempHumidity.h"

RequestTempHumidity::RequestTempHumidity(DHT* dht, unsigned long interval) {
    taskTempHumidity = new TaskTempHumidity(interval, dht);
}

void RequestTempHumidity::handleRequest(JsonDocument& requestDoc, JsonDocument& responseDoc) {
    taskTempHumidity->Callback();
    float temperature = taskTempHumidity->getTemperature();
    float humidity = taskTempHumidity->getHumidity();

    responseDoc["sensor"] = "temp_humidity";

    if (!isnan(humidity) && !isnan(temperature)) {    
      responseDoc["temperature"] = temperature;
      responseDoc["humidity"] = humidity;
    } else {
        responseDoc["error"] = "Failed to read temperature and humidity sensor";
    }
}
