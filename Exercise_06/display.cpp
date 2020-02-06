#include "display.h"

void Display::execute(){
    if (my_pipe->is_empty() == false)
    {
        //go through alarm_list and print them out
//        auto my_text = my_pipe->pull();
//        my_text->print_state();
        cout << "Display::Alarm" << endl;
        auto local_alarm_list = my_pipe->pull();
        for(IteratorA i=local_alarm_list.begin(); i!=local_alarm_list.end(); i++){
            i->print_state();
        }
        cout <<endl;
    }
    else {
        cout << "Display::Pipe is empty!" << endl;
    }
}

void connect(Display& disp, Pipe& pip) {
    disp.my_pipe = &pip;
}
