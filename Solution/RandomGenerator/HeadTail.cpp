#include "HeadTail.h"

HeadTail::HeadTail()
{
    //ctor1
}

HeadTail::HeadTail(UniformGenerator* _gen): DiscreteGenerator(_gen) //we call the parent
{
    //ctor2
}

double HeadTail::Generate() //we already have a uniform available!
{
    double u = generatorPtr->Generate(); //generate a uniform (bw 0 and 1)
    if (u <= 0.5)
        return 1.;
    else
        return 0.;
}

HeadTail::~HeadTail()
{
    //dtor
}
