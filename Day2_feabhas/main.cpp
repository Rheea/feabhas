#include <iostream>
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
    generator.execute();
    connect(display, pipe);
    display.execute();

    cout << "Done !" << endl;
    return 0;
}
