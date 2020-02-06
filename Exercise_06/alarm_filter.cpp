#include "alarm_filter.h"

Alarm_filter::Alarm_filter(Alarm::Type remove_filt_value) :
    filter_value { remove_filt_value }
{
}


void Alarm_filter::execute()
{
    // the simple way
    if (my_pipe_in->is_empty() == false) {
        cout << "Alarm_filter filtering" << endl;
        auto local_alarm_list = my_pipe_in->pull();
        auto original_size = local_alarm_list.size();

        auto it = remove_if(
             begin(local_alarm_list),
             end(local_alarm_list),
                    [this](const Alarm& alarm) {return alarm.type() == filter_value;}
        );
        local_alarm_list.erase(it, end(local_alarm_list));

        auto elements_removed = original_size - local_alarm_list.size();
        cout << "Removing " << elements_removed;
        cout << " alarm" << (elements_removed != 1 ? "s" : "");
        cout << endl;

        my_pipe_out->push(local_alarm_list);

        cout << endl;
    }


    else {
        cout << "Alarm_filter::Pipe is empty!" << endl;
    }
}


void connect(Alarm_filter& alm_filt, Pipe& pipIN, Pipe& pipOUT) {
    alm_filt.my_pipe_in = &pipIN;
    alm_filt.my_pipe_out = &pipOUT;
}
