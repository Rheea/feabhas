#ifndef DISPLAY_H
#define DISPLAY_H
#include"pipe.h"
//#include"alarm.h"

class Display
{
public:
    Display()=default;
    friend void connect(Display& disp, Pipe& pip);
    void execute();

private:
    Pipe* my_pipe {nullptr};
};

#endif // DISPLAY_H
