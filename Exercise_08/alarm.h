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

#ifndef ALARM_H_
#define ALARM_H_

#include <iostream>


class Alarm {
public:
    enum Type { invalid, advisory, caution, warning };

    Alarm();
    ~Alarm();
    Alarm(Type alarm_init);
    Alarm(Type alarm_init, const char* str);

    Alarm(const Alarm& rhs);
    Alarm(Alarm&& rhs) noexcept;

    Alarm& operator=(Alarm rhs);
    friend void swap(Alarm& lhs, Alarm& rhs);

    const char* as_string() const;
    const char* what() const;
    Type type() const;

private:
    Type  value { Type::invalid };
    char* description { nullptr };

};


std::ostream& operator<<(std::ostream& os, const Alarm& alarm);


#endif
