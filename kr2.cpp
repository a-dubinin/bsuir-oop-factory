/**
 * Программа реализации фабрики классов.
 * Разработчик - Дубинин А. В. (http://dubinin.net)
 * 02.01.2017
 */

// Подключение файлов из стандартной библиотеки
#include <iostream>

// Открытие пространства имен std
using namespace std;

// Объявление констант
const string CAR        = "легковой автомобиль";
const string SUV        = "кроссовер";
const string VAN        = "фургон";
const string BUS        = "автобус";
const string TRUCK      = "грузовой автомобиль";
const string MOTORCYCLE = "мотоцикл";

const string MSG_SUCCESS  = "Создано транспортное средство типа: ";
const string MSG_FAIL     = " - неизвестный тип транспортного средства";
const string MSG_APP_EXIT = "\nДля выхода из программы нажмите любую клавишу";

/**
 * @interface IVehicle
 * Описывает поведение транспортного средства.
 */
class IVehicle
{
    public:
        /**
         * Виртуальный метод getType() - возвращает тип транспортного средства.
         * @return string
         */
        virtual string getType() = 0;

        /**
         * Виртуальный метод free() - освобождает ресурс (динамическую память),
         * занятый объектом транспортного средства.
         * @return void
         */
        virtual void free() = 0;
};

/**
 * @interface IVehicleFactory
 * Описывает поведение фабрики.
 */
class IVehicleFactory
{
    public:
        /**
         * Статический метод create() - создает объект транспортного средства,
         * если объявлен класс для такого типа транспортного средства.
         * @param string
         * @return IVehicle|NULL
         */
        static IVehicle* create(string type);
};

/**
 * @class Car реализует интерфейс IVehicle
 * Класс легкового автомобиля.
 */
class Car: public IVehicle
{
    public:
        string getType()
        {
            return CAR;
        }
        void free()
        {
            delete this;
            return;
        }
};

/**
 * @class Suv реализует интерфейс IVehicle
 * Класс кроссовера.
 */
class Suv: public IVehicle
{
    public:
        string getType()
        {
            return SUV;
        }
        void free()
        {
            delete this;
            return;
        }
};

/**
 * @class Van реализует интерфейс IVehicle
 * Класс фургона.
 */
class Van: public IVehicle
{
    public:
        string getType()
        {
            return VAN;
        }
        void free()
        {
            delete this;
            return;
        }
};

/**
 * @class Bus реализует интерфейс IVehicle
 * Класс автобуса.
 */
class Bus: public IVehicle
{
    public:
        string getType()
        {
            return BUS;
        }
        void free()
        {
            delete this;
            return;
        }
};

/**
 * @class Truck реализует интерфейс IVehicle
 * Класс грузового автомобиля.
 */
class Truck: public IVehicle
{
    public:
        string getType()
        {
            return TRUCK;
        }
        void free()
        {
            delete this;
            return;
        }
};

/**
 * @class VehicleFactory реализует интерфейс IVehicleFactory
 * Класс фабрики классов транспортных средств.
 */
class VehicleFactory: public IVehicleFactory
{
    public:
        /**
         * Возвращает объект транспортного средства по его типа,
         * либо NULL, если класс не объявлен.
         */
        static IVehicle* create(string type)
        {
            if (type == CAR) return new Car();
            if (type == SUV) return new Suv();
            if (type == VAN) return new Van();
            if (type == BUS) return new Bus();
            if (type == TRUCK) return new Truck();
            return NULL;
        }
};

/**
 * @class Application
 */
class Application
{
    public:
        /**
         * Статический метод run() - запускает приложение.
         * @return void
         */
        static void run()
        {
            /**
             * Объявление и инициализация переменной newVehicleType
             * типа string
             * (получение значения из внешних источников: I/O, DB, file, etc.)
             */
            string newVehicleType = TRUCK;

            /**
             * Объявление переменной vehicle типа IVehicle.
             * Инициализация объекта реализуется с помощью
             * фабрики классов по названию типа транспортного средства
             */
            IVehicle *vehicle = VehicleFactory::create(newVehicleType);

            /**
             * Вывод названия объекта созданного транспортного средства
             * либо сообщения о невозможности создать транспортное
             * средства заданного типа.
             */
            if (vehicle != NULL) {
                cout << MSG_SUCCESS << vehicle->getType() << endl;
                vehicle->free();
            } else {
                cout << newVehicleType << MSG_FAIL << endl;
            }

            // Вывод на экран диалога выхода из программы
            cout << MSG_APP_EXIT;
            cin.get();
            return;
        }
};

int main()
{
    // Запуск приложения
    Application::run();
    return 0;
}
