#ifndef ALARM_FILTER_H
#define ALARM_FILTER_H
#include"pipe.h"
#include"filter.h"
#include <string.h>
#include <algorithm>

class Pipe;

class Alarm_filter : public Filter
{
public:
//    using Predicate = std::function<bool(const Alarm&)>;
    Alarm_filter() = default;
    Alarm_filter(Alarm::Type remove_filt_value);

private:
    Pipe* my_pipe_in {nullptr};
    Pipe* my_pipe_out {nullptr};
    Alarm::Type filter_value {};
    friend void connect(Alarm_filter& alm_filt, Pipe& pipIN, Pipe& pipOUT);

protected:
    void execute() override;
};

#endif // ALARM_FILTER_H
