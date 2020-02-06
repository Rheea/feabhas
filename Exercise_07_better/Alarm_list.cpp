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

#include "Alarm_list.h"

void Alarm_list::add(Alarm& in_val)
{
    alarms.push_back(in_val);
}


void Alarm_list::emplace(Alarm::Type type)
{
    alarms.emplace_back(type);
}


void Alarm_list::emplace(Alarm::Type type, const char* str)
{
    alarms.emplace_back(type, str);
}


Alarm_list::size_type Alarm_list::size() const
{
    return alarms.size();
}
    

Alarm_list::Iterator Alarm_list::begin()
{
    return alarms.begin();
}


Alarm_list::Iterator Alarm_list::end()
{
    return alarms.end();
}


void Alarm_list::erase(const Alarm_list::Iterator& from, const Alarm_list::Iterator& to)
{
    alarms.erase(from, to);
}


void Alarm_list::reserve(Alarm_list::size_type num_elements)
{
    alarms.reserve(num_elements);
}
