#include "alarm.h"

Alarm::Alarm(Type t): alarm {t}
{
    cout << "Alarm ctor" << endl;;
}

const char* Alarm::as_string() const
{
    switch (this->alarm)
    {
        case invalid: return "invalid";
        case warning: return "warning";
        case caution: return "caution";
        case advisory: return "advisory";
        default: return "unknown";
    }
}

Alarm::~Alarm(){
    cout << "Alarm dector" << endl;
}

Alarm::Alarm(const Alarm &alm){
    this->alarm = alm.alarm; // copy the value
    cout << "Alarm copy ctor" << endl;
}

Alarm& Alarm::operator=(const Alarm &alm){
    if (this != &alm) {
        Alarm();
        this->alarm = alm.alarm;
    }
    cout << "Alarm = operator" << endl;
    return *this;
}

void Alarm::print_state()
{
    cout << this->alarm << endl;
}

Alarm::Type Alarm::type() const
{
    return alarm;
}

ostream& operator<<(ostream& os, Alarm& alarm)
{
   os << alarm.as_string();
   return os;
}
