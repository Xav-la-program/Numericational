#ifndef DISCRETEGENERATOR_H
#define DISCRETEGENERATOR_H

#include "RandomGenerator.h"
#include "UniformGenerator.h"


class DiscreteGenerator : public RandomGenerator
{
    public:
        DiscreteGenerator(); //ctor1
        DiscreteGenerator(UniformGenerator* generatorPtr); //ctor2: only ptr work to choose which Generate to use (one version or the other): so it's here and not in the filles!


        virtual ~DiscreteGenerator();

    protected:
        UniformGenerator* generatorPtr;

    private:
};

#endif // DISCRETEGENERATOR_H
