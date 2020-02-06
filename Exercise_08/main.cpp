// -----------------------------------------------------------------------------
// DISCLAIMER:
// Feabhas is furnishing this item "as is". Feabhas does not provide any
// warranty of the item whatsoever, whether express, implied, or statutory,
// including, but not limited to, any warranty of merchantability or fitness
// for a particular purpose or any warranty that the contents of the item will
// be error-free.
// In no respect shall Feabhas incur any liability for any damages, including,
// but limited to, direct, indirect, special, or consequential damages arising
// out of, resulting from, or any way connected to the use of the item, whether
// or not based upon warranty, contract, tort, or otherwise; whether or not
// injury was sustained by persons or property or otherwise; and whether or not
// loss was sustained from, or arose out of, the results of, the item, or any
// services that may be provided by Feabhas.
// -----------------------------------------------------------------------------

#include "generator.h"
#include "display.h"
#include "alarm_filter.h"
#include "pipe.h"
#include "pipeline.h"
//#include "debug.h"

//#define TRACE_ENABLED 1
//#include <iostream>
//#define TRACE(msg) std::cout << "DEBUG : " << msg << std::endl

int main()
{
    Generator    generator { };
    Display      display   { };
    Alarm_filter filter    { Alarm::advisory};
    Pipe         pipe1     { };
    Pipe         pipe2     { };   

    connect(generator, pipe1);
    connect(filter, pipe1, pipe2);
    connect(display, pipe2);

    Pipeline pipeline { };
    pipeline.add(generator);
    pipeline.add(filter);
    pipeline.add(display);
    pipeline.run();
}
