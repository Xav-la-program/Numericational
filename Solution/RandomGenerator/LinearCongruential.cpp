#include "LinearCongruential.h"

LinearCongruential::LinearCongruential(): PseudoGenerator() //only goal is to set the seed to 0: we will never call it. We use the PseudoGenerator constructor with no seed
{
    //ctor1
}

LinearCongruential::LinearCongruential(myLong _seed, myLong _multiplier, myLong _increment, myLong _modulus):
    PseudoGenerator(_seed), Multiplier(_multiplier), Increment(_increment), Modulus(_modulus) //We use the PseudoGenerator constructor with seed. For the rest, can also put Multiplier = _multiplier in the {}
{
    //ctor2
}

double LinearCongruential::Generate()
{
    currentNumber = (Multiplier * currentNumber + Increment) % Modulus; //currentNumber is declared in the parent
    return (double)currentNumber / Modulus; //because Long/Long = 0 so we need to convert one of them
}

double LinearCongruential::GetcurrentNumber()
{
    return currentNumber;
}

LinearCongruential::~LinearCongruential()
{
    //dtor
}
