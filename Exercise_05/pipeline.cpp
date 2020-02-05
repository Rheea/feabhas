#include "pipeline.h"


bool Pipeline::add(Filter& filt)
{
    if (it == end(my_filters)) return false;

    *it = &filt;
    ++it;
    return true;
}

void Pipeline::run()
{
    for (int i { 0 }; i < 10; ++i ) {
        for (auto& filter_ptr : my_filters) {
            if (filter_ptr) {
                filter_ptr->execute();
            }
        }
    }
}
