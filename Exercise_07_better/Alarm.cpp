// -----------------------------------------------------------------------------
// DISCLAIMER:
// Feabhas is furnishing this item "as is". Feabhas does not provide any
// warranty of the item whatsoever, whether express, implied, or statutory,
// including, but not limited to, any warranty of merchantability or fitness
// for a particular purpose or any warranty that the contents of the item will
// be error-free.
// In no respect shall Feabhas incur any liability for any damages, including,
// but limited to, direct, indirect, special, or consequential damages arising
// out of, resulting from, or any way connected to the use of the item, whether
// or not based upon warranty, contract, tort, or otherwise; whether or not
// injury was sustained by persons or property or otherwise; and whether or not
// loss was sustained from, or arose out of, the results of, the item, or any
// services that may be provided by Feabhas.
// -----------------------------------------------------------------------------

#include <cstring>
#include "Alarm.h"
#include "debug.h"

using namespace std;

Alarm::Alarm()
{
    TRACE("Alarm default ctor");
}


Alarm::Alarm(Type alarm_init) : 
    value { alarm_init } 
{
    TRACE("Alarm non-default ctor");
}


Alarm::Alarm(Type alarm_init, const char* str) : 
    value { alarm_init } 
{
    TRACE("Alarm non-default ctor with string");

    if (str) {
        description = new char[strlen(str) + 1];
        strcpy(description, str);
    }
}


Alarm::~Alarm()
{
    TRACE("Alarm dtor");
    delete[] description;
}


Alarm::Alarm(const Alarm& rhs) : 
    Alarm { rhs.value, rhs.description }
{
    TRACE("Alarm copy ctor");
}


Alarm& Alarm::operator=(Alarm rhs)
{
    TRACE("Alarm copy op=");

    swap(*this, rhs);
    return *this;
}


void swap(Alarm& lhs, Alarm& rhs)
{
    using std::swap;
    swap(lhs.value, rhs.value);
    swap(lhs.description, rhs.description);
}


const char* Alarm::as_string() const
{
    switch(value) {
    case advisory: return "advisory";
    case caution:  return "caution ";
    case warning:  return "warning ";
    default:       return "invalid ";
    }
}


Alarm::Type Alarm::type() const
{
    return value;
}


const char* Alarm::what() const
{
    return (description != nullptr ? description : "");
}


std::ostream& operator<<(std::ostream& os, const Alarm& alarm)
{
    os << alarm.as_string() << " - " << alarm.what();
    return os;
}