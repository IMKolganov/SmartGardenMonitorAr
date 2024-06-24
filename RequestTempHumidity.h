#ifndef REQUEST_TEMP_HUMIDITY_H
#define REQUEST_TEMP_HUMIDITY_H

#include "TaskTempHumidity.h"
#include <ArduinoJson.h>
#include <DHT.h>

class RequestTempHumidity {
public:
    RequestTempHumidity(DHT* dht, unsigned long interval);
    void handleRequest(JsonDocument& requestDoc, JsonDocument& responseDoc);
    
private:
    TaskTempHumidity* taskTempHumidity;
};

#endif // REQUEST_TEMP_HUMIDITY_H
