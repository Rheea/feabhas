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

#include "Pipeline.h"
#include "Filter.h"

using namespace std;


bool Pipeline::add(Filter& filter)
{
    if (next == end(filters)) return false;

    *next = &filter;
    ++next;
    return true;
}


void Pipeline::run()
{
    for (int i { 0 }; i < 10; ++i ) {
        for (auto& filter_ptr : filters) {
            if (filter_ptr) {
                filter_ptr->execute();
            }
        }
    }
}
