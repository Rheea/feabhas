#include "pipe.h"


void Pipe::push(const elem_type& in){
    this->pipe_alarm = in;
    this->has_data = true;
//    cout << "has data in push: " << has_data<< endl;
//    cout << "Is empty in push: " << this->is_empty()<< endl;


}

std::optional<elem_type> Pipe::pull(){
    if (has_data) {
        has_data = false;
//        cout << "has data in pull: " << has_data<< endl;
        return pipe_alarm;
    } else {
        elem_type null_elem {};
        return  null_elem;
//        cout << "has data in pull already false: " << has_data<< endl;

    }

};

bool Pipe::is_empty() const {
    if (has_data == true) {
        return false;
    } else {
        return true;
    };
}
