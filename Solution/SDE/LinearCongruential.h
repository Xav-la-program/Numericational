#ifndef LINEARCONGRUENTIAL_H
#define LINEARCONGRUENTIAL_H

#include "PseudoGenerator.h"


class LinearCongruential : public PseudoGenerator
{
    public:
        LinearCongruential(); //ctor1: only used for pointers
        LinearCongruential(myLong _seed, myLong _multiplier, myLong _increment, myLong _modulus); //ctor2: the one we will use

        virtual double Generate();
        virtual double GetcurrentNumber();

        virtual ~LinearCongruential();

    protected:

    private:
        myLong Multiplier; //private because it is the last class in the chain: won't use it elsewhere
        myLong Increment;
        myLong Modulus;
};

#endif // LINEARCONGRUENTIAL_H
