#include "TaskSoilMoisture.h"
#include <ArduinoJson.h>

TaskSoilMoisture::TaskSoilMoisture(unsigned long interval) 
    : Task(interval, TASK_FOREVER, nullptr), moistureLevel(0) {
}

void TaskSoilMoisture::Callback() {
    moistureLevel = analogRead(A0);//todo: fix
    JsonDocument doc;
  
    doc["sensor"] = "soil_moisture";
    if (moistureLevel >= 0 && moistureLevel <= 550) {
        doc["value"] = moistureLevel;
    } else {
        doc["error"] = "Failed to read soil moisture sensor";
    }
  
    //serializeJson(doc, Serial);         
    //Serial.println();
}

int TaskSoilMoisture::getMoistureLevel() {
  if (moistureLevel >= 0 && moistureLevel <= 550) {
    return moistureLevel;
  }else{
    return 0;
  }
}
