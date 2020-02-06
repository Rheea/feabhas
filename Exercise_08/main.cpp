#include <iostream>
#include "pipe.h"
#include "generator.h"
#include "display.h"
#include "pipeline.h"
#include "alarm_filter.h"

using namespace std;

int main()
{
    cout << "Start Main" << endl;
    Generator generator {};
    Display display {};
    Pipe pipe1 {};
    Pipe pipe2 {};

    Pipeline pipeline {};
    Alarm_filter alarm_filter {};

    connect(generator, pipe1);
    connect(alarm_filter, pipe1, pipe2);
    connect(display, pipe2);

    pipeline.add(generator);
    pipeline.add(alarm_filter);
    pipeline.add(display);
    pipeline.run();

    cout << "Done !" << endl;
    return 0;
}
