#ifndef TASKTEMP_HUMIDITY_H
#define _TASK_INLINE

#include <DHT.h>
#include <TaskScheduler.h>

class TaskTempHumidity : public Task {
public:
    TaskTempHumidity(unsigned long interval, DHT* dht);
    void Callback();
    
    float getTemperature();
    float getHumidity();

private:
    DHT* dht;
    float temperature;
    float humidity;
};

#endif // TASKTEMP_HUMIDITY_H
