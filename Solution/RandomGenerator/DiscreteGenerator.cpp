#include "DiscreteGenerator.h"

DiscreteGenerator::DiscreteGenerator()
{
    //ctor1
}

DiscreteGenerator::DiscreteGenerator(UniformGenerator* _gen)
{
    //ctor2
    generatorPtr = _gen; //equivalent to initialisation list
}

DiscreteGenerator::~DiscreteGenerator()
{
    //dtor
}
