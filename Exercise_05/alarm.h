#ifndef ALARM_H
#define ALARM_H
#include<iostream>
#include<iomanip>

using namespace std;

class Alarm
{
public:
    enum Type {invalid, warning, caution, advisory};

    Alarm()=default;
    Alarm(Type t);

    Alarm(const Alarm &alm); //copy cnostructor
    Alarm& operator=(const Alarm& alm); //assignment operator

    ~Alarm();

    Type type() const;
    const char* as_string() const;

    void print_state();
private:
    Type alarm {invalid};
};

#endif // ALARM_H
