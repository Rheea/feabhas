#ifndef GENERATOR_H
#define GENERATOR_H
#include"pipe.h"
#include<time.h>
#include"filter.h"

class Generator : public Filter
{
public:
    Generator() = default;
    friend void connect(Generator& gen, Pipe& pip);
//    void execute();

private:
    Pipe* my_pipe {nullptr};

protected:
    void execute() override;

};

#endif // GENERATOR_H
