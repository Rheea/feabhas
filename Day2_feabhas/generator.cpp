#include "generator.h"

void Generator::execute()
{
    srand(time(NULL));
    int randNum = (rand() % 4);
    Alarm new_alarm {static_cast<Alarm::Type>(randNum)};
    my_pipe->push(new_alarm);
    cout << "Pipe is empty: " << my_pipe->is_empty() << endl;
    new_alarm.print_state();

}

void connect(Generator& gen, Pipe& pip) {
    gen.my_pipe = &pip;
}


