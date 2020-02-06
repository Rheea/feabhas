#ifndef DISPLAY_H
#define DISPLAY_H
#include"pipe.h"
#include"filter.h"

class Pipe;

class Display : public Filter
{
public:
    Display()=default;
    friend void connect(Display& disp, Pipe& pip);

private:
    Pipe* my_pipe {nullptr};

protected:
    void execute() override;
};

#endif // DISPLAY_H
