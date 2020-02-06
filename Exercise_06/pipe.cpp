#include "pipe.h"


void Pipe::push(const elem_type& in){
    //how to exactly push in here
    pipe_alarm_list=in;
    has_data = true;
    cout << "Pipe::push" << endl;
}

elem_type Pipe::pull(){
    if (has_data) {
        has_data = false;
        return pipe_alarm_list;
    } else {
        elem_type null_elem {};
        return  null_elem;
    }
    cout << "Pipe::pull" << endl;

};

bool Pipe::is_empty() const {
    if (has_data == true) {
        return false;
    } else {
        return true;
    };
}
