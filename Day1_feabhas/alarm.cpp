#include "alarm.h"

Alarm::Alarm(Type t): alarm {t}
{
    cout << "Alarm ctor" << endl;;
}

const char* Alarm::as_string()
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

void Alarm::print_state()
{
    cout << this->alarm << endl;
}
