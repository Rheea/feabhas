#include "generator.h"
//#include "alarm.h"
void Generator::execute()
{
    int randNum = (rand() % 4);
    Alarm new_alarm {static_cast<Alarm::Type>(randNum)};
    my_pipe->push(new_alarm);
}

void connect(Generator& gen, Pipe& pip) {
    gen.my_pipe = &pip;
}


