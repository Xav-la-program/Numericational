#include "ContinuousGenerator.h"

ContinuousGenerator::ContinuousGenerator()
{
    //ctor
}

ContinuousGenerator::ContinuousGenerator(UniformGenerator* _gen)
{
    //ctor2
    generatorPtr = _gen; //equivalent to initialisation list
}

ContinuousGenerator::~ContinuousGenerator()
{
    //dtor
}
