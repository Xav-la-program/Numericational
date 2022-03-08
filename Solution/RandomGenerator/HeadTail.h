#ifndef HEADTAIL_H
#define HEADTAIL_H

#include "DiscreteGenerator.h"


class HeadTail : public DiscreteGenerator
{
    public:
        HeadTail(); //ctor1
        HeadTail(UniformGenerator* _gen); //ctor2

        virtual double Generate();

        virtual ~HeadTail();

    protected:

    private:
};

#endif // HEADTAIL_H
