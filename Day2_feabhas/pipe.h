#ifndef PIPE_H
#define PIPE_H
#include<iostream>
#include<iomanip>
#include<tuple>
#include<optional>
#include"alarm.h"
using elem_type = Alarm;
using namespace  std;

class Pipe
{
public:
    Pipe()=default;

    void push(const elem_type& in);
    std::optional<elem_type> pull();
    bool is_empty() const;

private:
    optional<elem_type> pipe_alarm {};
    bool has_data {false};

};



#endif // PIPE_H
