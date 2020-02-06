#include "alarm_list.h"

void Alarm_list::add(Alarm &in_val){
    my_alarms.push_back(in_val);
}

void Alarm_list::emplace(Alarm::Type type){
    my_alarms.emplace_back(type);
}

void Alarm_list::emplace(Alarm::Type type, const  char* desc){
    my_alarms.emplace_back(type, desc);
}

std::size_t Alarm_list::size() const{
    return my_alarms.size();

}

IteratorA Alarm_list::begin(){
    return my_alarms.begin();
}
IteratorA Alarm_list::end(){
    return my_alarms.end();

}
void Alarm_list::erase(const IteratorA& from,
                       const IteratorA& to){
    for(IteratorA i=from; i!=to; i++){
        my_alarms.erase((i));
    }
}
void Alarm_list::reserve(std::size_t sz){
    my_alarms.reserve(sz);
}
