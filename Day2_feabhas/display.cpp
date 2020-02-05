#include "display.h"

void Display::execute(){
    if (my_pipe->is_empty() == false)
    {
        auto my_text = my_pipe->pull();
        my_text->print_state();
        cout << "Pipe not empty!" << endl;

    }
    else {
        cout << "Pipe is empty!" << endl;
    }
}

void connect(Display& disp, Pipe& pip) {
    disp.my_pipe = &pip;
}
