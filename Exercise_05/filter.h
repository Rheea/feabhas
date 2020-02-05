#ifndef FILTER_H
#define FILTER_H


class Filter
{
public:
//    Filter();
    virtual void execute() =0;

    virtual ~Filter() = default;
};

#endif // FILTER_H
