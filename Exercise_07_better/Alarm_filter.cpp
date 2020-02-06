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

#include <algorithm>
#include <cassert>
#include "Alarm_filter.h"
#include "Pipe.h"

using namespace std;

Alarm_filter::Alarm_filter(Alarm::Type remove_this) :
    value { remove_this }
{
}


void Alarm_filter::execute()
{
    assert(input);
    assert(output);
    if (input->is_empty()) return;

    cout << "ALARM FILTER : -------------------------------" << endl;

    auto alarms = input->pull();

    auto original_size = alarms.size();

    auto it = remove_if(
        begin(alarms), 
        end(alarms), 
        [this](const Alarm& alarm) { return alarm.type() == value; }
    );
    alarms.erase(it, end(alarms));
    
    auto elements_removed = original_size - alarms.size();
    cout << "Removing " << elements_removed;
    cout << " alarm" << (elements_removed != 1 ? "s" : "");
    cout << endl;

    output->push(alarms);

    cout << endl;
}


void connect(Alarm_filter& filter, Pipe& in, Pipe& out)
{
    filter.input  = &in;
    filter.output = &out;
}