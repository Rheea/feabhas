#ifndef ALARM_H
#define ALARM_H
#include<iostream>
#include<iomanip>
#include<iomanip>
#include<cstring>
#include<utility>
#include<algorithm>

using namespace std;

class Alarm
{
public:
    enum Type {invalid, warning, caution, advisory};

    Alarm()=default;
    Alarm(Type t);
    Alarm(Type t,const char* desc);
    Alarm(const Alarm &alm); //copy cnostructor

    Alarm& operator=(const Alarm alm); //assignment operator

    ~Alarm();

    Type type() const;
    const char* as_string() const;
    const char* what() const;

    void print_state();
private:
    Type alarm {invalid};
    char* description {nullptr};

    friend void swap(Alarm &alm1, Alarm alm2);

};

#endif // ALARM_H
