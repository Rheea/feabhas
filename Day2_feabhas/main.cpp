#include <iostream>
#include "alarm.h"
#include "pipe.h"
#include "generator.h"
#include "display.h"


using namespace std;



int main()
{
    Generator generator {};
    Display display {};
    Pipe pipe {};

    connect(generator, pipe);
    connect(display, pipe);

    generator.execute();
    display.execute();

    cout << "Done Day 2!" << endl;
    return 0;
}
