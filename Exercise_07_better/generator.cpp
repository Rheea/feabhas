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
#include "generator.h"
#include "pipe.h"

using namespace std;

namespace {

    Alarm::Type random_alarm()
    {
        return (static_cast<Alarm::Type>((rand() % 3) + 1));
    }


    const char* alarm_strings[] {
        "Panic!",
        "Run away!",
        "Ignore this alarm.",
        "Oooops!",
        "Things are going horribly wrong.",
        "Please fix immediately."
    };

    const char* random_string()
    {
        return (alarm_strings[rand() % 6]);
    }
}


void Generator::execute()
{
    assert(output);
    
    cout << "GENERATOR : ----------------------------------" << endl;

    Alarm_list alarms { };

    auto num_alarms = rand() % 10;
    cout << "Generating " << num_alarms << " alarm" << (num_alarms != 1 ? "s" : "") << endl;

    alarms.reserve(num_alarms);
    
    for (int i { 0 }; i < num_alarms; ++i) {
        alarms.emplace(random_alarm(), random_string());
    }

    output->push(alarms);

    cout << endl;
}


void connect(Generator& gen, Pipe& pipe)
{
    gen.output = &pipe;
}
