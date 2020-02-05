#include "generator.h"

void Generator::execute()
{
    srand(time(NULL));
    int randNumOfAlarms = (rand() % 10);
    Alarm_list new_alarm_list {};
    cout << "Generating " << randNumOfAlarms << " alarms" << endl;
    for(int i=0; i<randNumOfAlarms; i++){
        srand(time(NULL));
        int randNum = (rand() % 4);
        Alarm new_alarm {static_cast<Alarm::Type>(randNum)};
        new_alarm.print_state();
        new_alarm_list.add(new_alarm);
    }
    my_pipe->push(new_alarm_list);
    cout << "Generation finished " << endl;

}

void connect(Generator& gen, Pipe& pip) {
    gen.my_pipe = &pip;
}


