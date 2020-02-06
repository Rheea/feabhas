#include "alarm.h"

inline const char* rand_description()
{
   static const char* strings[]{
       "Hopla",
       "Upsie",
       "Help",
       "I am a badger",
       "I'm a lumberjack and I'm ok",
       "Let's party",
       "I am running out of ideas",
       "Kill all humans",
       "I'll make my own C++ ...",
       "This is fun"
   };
   return strings [rand() % 10];
}

Alarm::Alarm(Type t): alarm {t}
{
    auto desc = rand_description();
    description = new char[strlen(desc)+1];
    strcpy(description, desc);
    cout << "Alarm ctor" << endl;
}

Alarm::Alarm(Type t, const char* desc): alarm {t}
{
    if (desc) {
        description = new char[strlen(desc)+1];
        strcpy(description, desc);
    }
    cout << "Alarm ctor 2" << endl;;
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

//Alarm::Alarm(const Alarm &alm){
//    this->alarm = alm.alarm; // copy the value
//    this->description=alm.description;
//    cout << "Alarm copy ctor" << endl;
//}

Alarm::Alarm(const Alarm& alm) :
    Alarm { alm.alarm, alm.description }
{
    cout << "Alarm copy ctor" << endl;
}

Alarm& Alarm::operator=(const Alarm alm){
    swap(*this,alm);
    cout << "Alarm = operator" << endl;
    return *this;
}

void Alarm::print_state()
{
    cout << "Alarm: " << this->alarm << " Description: "<< this->description << endl;

}

const char* Alarm::what() const
{
    return this->description;
}

ostream& operator<<(ostream& os, Alarm& alarm)
{
   os << alarm.as_string();
   os << "Description:" << alarm.what();
   return os;
}


void swap(Alarm &alm1, Alarm alm2){
    using std::swap;
    cout << "Swap two alarms!" << endl;
    swap(alm1.alarm, alm2.alarm);
    swap(alm1.description, alm2.description);
}
