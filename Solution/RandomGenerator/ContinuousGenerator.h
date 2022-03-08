#ifndef CONTINUOUSGENERATOR_H
#define CONTINUOUSGENERATOR_H

#include "RandomGenerator.h"
#include "UniformGenerator.h"

class ContinuousGenerator : public RandomGenerator
{
    public:
        ContinuousGenerator();
        ContinuousGenerator(UniformGenerator* generatorPtr); //ctor2: only ptr work to choose which Generate to use (one version or the other): so it's here and not in the filles!



        virtual ~ContinuousGenerator();

    protected:
            UniformGenerator* generatorPtr;


    private:
};

#endif // CONTINUOUSGENERATOR_H
