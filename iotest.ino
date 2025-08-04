#include <iocontrol.h>
#include <ESP8266WiFi.h>

// Название панели на сайте iocontrol.ru
const char* myPanelName = "cr_dacha";
int status;

// Название переменных как на сайте iocontrol.ru
const char* VarName_sw_1 = "sw_1";  // автомат скваженного насоса
const char* VarName_sw_2 = "sw_2";  // автомат водопроводного насоса
const char* VarName_sw_3 = "sw_3";
const char* VarName_sw_4 = "sw_4";
const char* VarName_sw_5 = "sw_5";
const char* VarName_sw_6 = "sw_6";

const char* ssid = "Dacha";
const char* password = "flower100101";

// Создаём объект клиента
WiFiClient client;

// Создаём объект iocontrol, передавая в конструктор название панели и клиента
iocontrol mypanel(myPanelName, client);

void setup()
{
    Serial.begin(115200);
    WiFi.begin(ssid, password);

    // Ждём подключения
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(500);
    }
    // Вызываем функцию первого запроса к сервису
    mypanel.begin();

}


void loop()
{

    // ************************ ЧТЕНИЕ ************************

    // Чтение значений переменных из сервиса
    status = mypanel.readUpdate();
    // Если статус равен константе OK...
    if (status == OK) {
        // Выводим текст в последовательный порт
        Serial.println("------- Read OK -------");
        // Записываем считанный из сервиса значения в переменные
        long io_sw_1 = mypanel.readInt(VarName_sw_1);   // целочисленная переменна
        Serial.println((String)"io_sw_1 = "+io_sw_1);
        long io_sw_2 = mypanel.readInt(VarName_sw_2);   // целочисленная переменна
        Serial.println((String)"io_sw_2 = "+io_sw_2);
        long io_sw_3 = mypanel.readInt(VarName_sw_3);   // целочисленная переменна
        Serial.println((String)"io_sw_3 = "+io_sw_3);
        long io_sw_4 = mypanel.readInt(VarName_sw_4);   // целочисленная переменна
        Serial.println((String)"io_sw_4 = "+io_sw_4);
        long io_sw_5 = mypanel.readInt(VarName_sw_5);   // целочисленная переменна
        Serial.println((String)"io_sw_5 = "+io_sw_5);
        long io_sw_6 = mypanel.readInt(VarName_sw_6);   // целочисленная переменна
        Serial.println((String)"io_sw_6 = "+io_sw_6);
        
    } 

    // ************************ ЗАПИСЬ ************************
    
    // Записываем  значение в переменную для отпраки в сервис
    
    // Отправляем переменные из контроллера в сервис
    status = mypanel.writeUpdate();
    // Если статус равен константе OK...
    if (status == OK) {
        // Выводим текст в последовательный порт
        Serial.println("------- Write OK -------");
    }


}
