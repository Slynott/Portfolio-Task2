//Sensor.h
#ifndef SENSOR_H
#define SENSOR_H


class Sensor
{
    public:
        Sensor();
        virtual ~Sensor();

        void getReading();
        void getName();

    protected:

    private:

        string Reading();

        string Sensor();
};

#endif // SENSOR_H
