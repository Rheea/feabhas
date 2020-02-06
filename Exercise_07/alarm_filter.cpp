#include "alarm_filter.h"

void Alarm_filter::execute()
{
    // the simple way
    if (my_pipe_in->is_empty() == false) {
        cout << "Alarm_filter filtering" << endl;
        auto local_alarm_list_in = my_pipe_in->pull();
        Alarm_list local_alarm_list_out {};
        for(IteratorA i=local_alarm_list_in->begin(); i!=local_alarm_list_in->end(); i++){
            if (strcmp(i->as_string(),"warning")==0) {
                local_alarm_list_out.add(*i);
            }
        }
        my_pipe_out->push(local_alarm_list_out);

        //now as a lambda expression
        //local_alarm_list_in = alarm_opt
        //local_alarm_list_out = copy_if output
//        if (auto local_alarm_list_in = my_pipe_in->pull(); local_alarm_list_in.has_value()) {
//            auto src {local_alarm_list_in.value()};
//            decltype (src) dest {};

//        copy_if(begin(src),
//                end(src),
//                back_inserter(dest),
//                [this](const Alarm &alarm){return alarm.type() == filter_value;});

//    }
    }
    else {
        cout << "Alarm_filter::Pipe is empty!" << endl;
    }
}


void connect(Alarm_filter& alm_filt, Pipe& pipIN, Pipe& pipOUT) {
    alm_filt.my_pipe_in = &pipIN;
    alm_filt.my_pipe_out = &pipOUT;
}
