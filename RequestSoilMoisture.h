#ifndef REQUEST_SOIL_MOISTURE_H
#define REQUEST_SOIL_MOISTURE_H

#include "TaskSoilMoisture.h"
#include <ArduinoJson.h>

class RequestSoilMoisture {
public:
    RequestSoilMoisture(unsigned long interval);
    void handleRequest(JsonDocument& requestDoc, JsonDocument& responseDoc);
    
private:
    TaskSoilMoisture* taskSoilMoisture;
};

#endif // REQUEST_SOIL_MOISTURE_H
