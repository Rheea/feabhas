#ifndef GENERATOR_H
#define GENERATOR_H
#include"pipe.h"
#include<time.h>

class Generator
{
public:
    Generator() = default;
    friend void connect(Generator& gen, Pipe& pip);
    void execute();

private:
    Pipe* my_pipe {nullptr};

};

#endif // GENERATOR_H
