#ifndef ECUYERCOMBINED_H
#define ECUYERCOMBINED_H

#include "PseudoGenerator.h"
#include "LinearCongruential.h"


class EcuyerCombined : public PseudoGenerator
{
    public:
        EcuyerCombined();

        virtual double Generate();

        virtual ~EcuyerCombined();

    protected:

    private:
        LinearCongruential Generator1;
        LinearCongruential Generator2;

};

#endif // ECUYERCOMBINED_H
