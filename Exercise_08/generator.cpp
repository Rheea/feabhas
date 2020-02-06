#include "generator.h"

   static const char* my_strings[]{
       "Hopla",
       "Upsie",
       "Help",
       "I am a badger",
       "I'm a lumberjack and I'm ok",
       "Let's party",
       "I am running out of ideas",
       "Kill all humans",
       "I'll make my own C++ ...",
       "This is fun"
   };

Alarm::Type random_alarm()
{
    return (static_cast<Alarm::Type>((rand() % 3) + 1));
}

const char* random_description()
{
    return (my_strings[rand() % 6]);
}

void Generator::execute()
{
    srand(time(NULL));
    int randNumOfAlarms = (rand() % 10);
    Alarm_list new_alarm_list {};
    cout << "Generating " << randNumOfAlarms << " alarms" << endl;
    new_alarm_list.reserve(randNumOfAlarms);

    for(int i=0; i<randNumOfAlarms; i++){
        new_alarm_list.emplace(random_alarm(), random_description());
    }

    my_pipe->push(new_alarm_list);
    cout << "Generation finished " << endl;

}

void connect(Generator& gen, Pipe& pip) {
    gen.my_pipe = &pip;
}


