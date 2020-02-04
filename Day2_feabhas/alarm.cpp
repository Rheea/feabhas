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

void Alarm::print_state()
{
    cout << this->alarm << endl;
}

ostream& operator<<(ostream& os, Alarm& alarm)
{
   os << alarm.as_string();
   return os;
}
