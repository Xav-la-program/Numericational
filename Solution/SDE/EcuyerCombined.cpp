#include "EcuyerCombined.h"
#include <iostream>

EcuyerCombined::EcuyerCombined()
    : Generator1(2147483562., 40014., 0., 2147483563.),
      Generator2(2147483398., 40692., 0., 2147483399.)
{
    //ctor
}

double EcuyerCombined::Generate()
{

    myLong currentG1 = Generator1.Generate() * 2147483563; //step 2
    myLong currentG2 = Generator2.Generate() * 2147483399; //step 2

    myLong current = (currentG1 - currentG2) % 2147483562; //step 3

    double result;

    if (current > 0) //step 4
        result = (double)current / 2147483563.;

    else
        result = 2147483562. / 2147483563.;

    /*currentNumber = result;
    Generator1.Generate() * 2147483563;
    Generator2.Generate() * 2147483399;
    currentG1 = Generator1.GetcurrentNumber();
    currentG2 = Generator2.GetcurrentNumber();*/

    return result;

}

EcuyerCombined::~EcuyerCombined()
{
    //dtor
}
