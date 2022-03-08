#include "Bernoulli.h"

Bernoulli::Bernoulli()
{
    //ctor1
}

Bernoulli::Bernoulli(UniformGenerator* _gen, double _p): p(_p), DiscreteGenerator(_gen)
{
    //ctor2
}

double Bernoulli::Generate() //we already have a uniform available!
{
    double u = generatorPtr->Generate(); //generate a uniform (bw 0 and 1)
    if (u <= p)
        return 1.;
    else
        return 0.;
}

Bernoulli::~Bernoulli()
{
    //dtor
}
