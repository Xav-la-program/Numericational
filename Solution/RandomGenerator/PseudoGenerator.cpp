#include "PseudoGenerator.h"

PseudoGenerator::PseudoGenerator(): seed(0.)
{
    //ctor1
    currentNumber = seed; //can't put it in the initialization list because cpp does not know the order
}

PseudoGenerator::PseudoGenerator(myLong inputSeed): seed(inputSeed)
{
    //ctor2
    currentNumber = inputSeed;
}

PseudoGenerator::~PseudoGenerator()
{
    //dtor

}
