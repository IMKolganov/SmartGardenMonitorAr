#ifndef TASK_SOIL_MOISTURE_H
#define _TASK_INLINE
#include <TaskScheduler.h>

class TaskSoilMoisture : public Task {
public:
    TaskSoilMoisture(unsigned long interval);

    void Callback();

    int getMoistureLevel();

private:
  int moistureLevel;
};

#endif // TASK_SOIL_MOISTURE_H
