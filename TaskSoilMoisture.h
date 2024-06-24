#ifndef TASK_SOIL_MOISTURE_H
#define _TASK_INLINE
#include <TaskScheduler.h>

class TaskSoilMoisture : public Task {
public:
    TaskSoilMoisture(unsigned long interval);

    void Callback();

private:
    // Здесь могут быть приватные переменные и другие методы
};

#endif // TASK_SOIL_MOISTURE_H
