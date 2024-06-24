#ifndef TASK_TEMP_HUMIDITY_H
#define _TASK_INLINE
#include <TaskScheduler.h>

#include "DHT.h"

class TaskTempHumidity : public Task {
public:
    TaskTempHumidity(unsigned long interval, DHT* dht);

    void Callback();

private:
    DHT* dht;
    // Здесь могут быть приватные переменные и другие методы
};

#endif // TASK_TEMP_HUMIDITY_H
