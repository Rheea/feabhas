#ifndef PIPELINE_H
#define PIPELINE_H
#include"filter.h"
#include<array>
using namespace std;
class Filter;

class Pipeline
{
public:
    Pipeline() = default;
    bool add(Filter& filt);
    void run();

private:
    using Container = std::array<Filter*, 4>;
    using Iterator  = Container::iterator;

    Container my_filters { };
    Iterator  it    { begin(my_filters) };

};

#endif // PIPELINE_H
