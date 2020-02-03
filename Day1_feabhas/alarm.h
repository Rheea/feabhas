#ifndef ALARM_H
#define ALARM_H
#include<iostream>
#include<iomanip>
//#include<iostream>

using namespace std;

class Alarm
{
public:
    enum Type {invalid, warning, caution, advisory};

    Alarm()=default;
    Alarm(Type t);

    Type type() const;
    const char* as_string();

    void print_state();
private:
    Type alarm {invalid};
};

#endif // ALARM_H
