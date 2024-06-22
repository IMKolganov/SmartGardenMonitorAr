#include <ArduinoJson.h>
#include <TaskScheduler.h>
#include "DHT.h"

extern Task taskSoilMoisture;
extern Task taskTempHumidity;
extern DHT dht;

Scheduler scheduler;

void setup() {
  delay(1000);
  Serial.begin(9600);
  dht.begin();

  scheduler.init();
  scheduler.addTask(taskSoilMoisture);
  scheduler.addTask(taskTempHumidity);

  taskSoilMoisture.enable();
  taskTempHumidity.enable();
}

void loop() {
  scheduler.execute();
}
