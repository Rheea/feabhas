#ifndef ALARM_FILTER_H
#define ALARM_FILTER_H
#include"pipe.h"
#include"filter.h"
#include <string.h>
#include <algorithm>

class Alarm_filter : public Filter
{
public:
//    using Predicate = std::function<bool(const Alarm&)>;
    Alarm_filter() = default;
    friend void connect(Alarm_filter& alm_filt, Pipe& pipIN, Pipe& pipOUT);

private:
    Pipe* my_pipe_in {nullptr};
    Pipe* my_pipe_out {nullptr};
    Alarm::Type filter_value {};

//    Predicate predicate {};

protected:
    void execute() override;
};

#endif // ALARM_FILTER_H
