#include "pipe.h"


void Pipe::push(const elem_type& in){
    this->pipe_alarm = in;
    this->has_data = true;
}

std::optional<elem_type> Pipe::pull(){
    if (has_data) {
        has_data = false;
        return pipe_alarm;
    } else {
        elem_type null_elem {};
        return  null_elem;

    }

};

bool Pipe::is_empty() const {
    if (has_data == true) {
        return false;
    } else {
        return true;
    };
}
