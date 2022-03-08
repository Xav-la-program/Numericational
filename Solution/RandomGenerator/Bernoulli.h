#ifndef BERNOULLI_H
#define BERNOULLI_H

#include "DiscreteGenerator.h"


class Bernoulli: public DiscreteGenerator
{
    public:
        Bernoulli(); //ctor1
        Bernoulli(UniformGenerator* _gen, double _p); //ctor2

        virtual double Generate();

        virtual ~Bernoulli();

    protected:

    private:
        double p;
};

#endif // BERNOULLI_H
