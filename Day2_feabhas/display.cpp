#include "display.h"

void Display::execute(){
    auto my_text = my_pipe->pull();
    cout << "Display test!" << endl;
//    cout << static_cast<Alarm>(my_text) << endl;
}

void connect(Display& disp, Pipe& pip) {
    disp.my_pipe = &pip;
}
