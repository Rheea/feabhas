#ifndef ALARM_LIST_H
#define ALARM_LIST_H
#include"alarm.h"
#include"filter.h"
#include<array>
#include<vector>

//why it doesn't see IteratorA if def inside public of class Alarm_list
using ContainerA = std::vector<Alarm>;
using IteratorA  = ContainerA::iterator;
using value_typeA = ContainerA::value_type;
using size_typeA  = ContainerA::size_type;

class Alarm_list
{
public:


    Alarm_list() = default;

    void add(Alarm& in_val);
    void emplace(Alarm::Type type);
    void emplace(Alarm::Type type,const char* desc);

    std::size_t size() const;

    IteratorA begin();
    IteratorA end();
    void erase(const IteratorA& from,
               const IteratorA& to);
    void reserve(std::size_t sz);

private:
    ContainerA my_alarms {};
//    IteratorA it_a {nullptr};

};

#endif // ALARM_LIST_H
