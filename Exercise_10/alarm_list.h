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

#ifndef ALARM_LIST_H_
#define ALARM_LIST_H_

#include <vector>
#include "alarm.h"


class Alarm_list {
public:
    using Container  = std::vector<Alarm>;
    using Iterator   = Container::iterator;
    using value_type = Container::value_type;
    using size_type  = Container::size_type;

    void      reserve(size_type num_elements);
    void      add(Alarm& in_val);
    void      emplace(Alarm::Type type);
    void      emplace(Alarm::Type type, const char* str);
    void      erase(const Iterator& from, const Iterator& to);
    size_type size() const;
    Iterator  begin();
    Iterator  end();

private:
    Container alarms { };
};

#endif
