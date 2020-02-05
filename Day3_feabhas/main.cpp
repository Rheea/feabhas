#include <iostream>
#include "pipe.h"
#include "generator.h"
#include "display.h"
#include "pipeline.h"

using namespace std;


int main()
{
    Generator generator {};
    Display display {};
    Pipe pipe {};

    Pipeline pipeline {};

    connect(generator, pipe);
    connect(display, pipe);

    pipeline.add(generator);
    pipeline.add(display);
    pipeline.run();

    cout << "Done !" << endl;
    return 0;
}
