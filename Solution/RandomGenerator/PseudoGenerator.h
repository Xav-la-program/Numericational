#ifndef PSEUDOGENERATOR_H
#define PSEUDOGENERATOR_H

#include "UniformGenerator.h"


class PseudoGenerator : public UniformGenerator
{
    public:
        PseudoGenerator(); //ctor 1
        PseudoGenerator(myLong inputSeed); //ctor 2


        virtual ~PseudoGenerator();

    protected:

        myLong seed; //protected because we want the fille to use it
        myLong currentNumber; //we put it here because we need it for both linear congruential and l'ecuyer

    private:
};

#endif // PSEUDOGENERATOR_H
