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

#include <iostream>
#include <cassert>
#include "display.h"
#include "pipe.h"

using namespace std;


void Display::execute()
{
    assert(input);
    if (input->is_empty()) return;
    
    cout << "DISPLAY   : ----------------------------------" << endl;

    auto alarms = input->pull();

    for (auto& alarm : alarms) {
        cout << alarm << endl;
    }
    
    cout << endl;
}


void connect(Display& display, Pipe& pipe)
{
    display.input = &pipe;
}
