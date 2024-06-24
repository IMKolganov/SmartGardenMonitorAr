#include "TaskSoilMoisture.h"
#include "TaskTempHumidity.h"
#include <ArduinoJson.h>

#define DHT_PIN 7
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

TaskSoilMoisture taskSoilMoisture(5000); 
TaskTempHumidity taskTempHumidity(6000, &dht);

void setup() {
    // Инициализация и другие настройки
    Serial.begin(9600);
    dht.begin();    
}

void loop() {
  if (Serial.available() > 0) {
      // Считываем первый доступный символ (предполагая, что приходит однобайтовая команда)
      char command = Serial.read();

      // Обработка команды
      switch (command) {
          case 'S':
              // Выполняем задачу для измерения влажности почвы
              taskSoilMoisture.Callback();
              break;
          case 'T':
              // Выполняем задачу для измерения температуры и влажности
              taskTempHumidity.Callback();
              break;
          default:
              // Неизвестная команда, можно отправить сообщение об ошибке или игнорировать
              Serial.println("Unknown command!");
              break;
      }
  }

    
  //taskSoilMoisture.Callback();
  //taskTempHumidity.Callback();
  
  delay(1000); // Пример задержки
}
