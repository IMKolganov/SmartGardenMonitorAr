#include "RequestSoilMoisture.h"

RequestSoilMoisture::RequestSoilMoisture(unsigned long interval) {
    taskSoilMoisture = new TaskSoilMoisture(interval);
}

void RequestSoilMoisture::handleRequest(JsonDocument& requestDoc, JsonDocument& responseDoc) {
    taskSoilMoisture->Callback();
    int soilMoisture = taskSoilMoisture->getMoistureLevel();

    responseDoc["sensor"] = "soil_moisture";

    if (soilMoisture >= 1 && soilMoisture <= 550) {
        responseDoc["moisture"] = soilMoisture;
    } else {
        responseDoc["error"] = "Failed to read soil moisture sensor";
    }
}
