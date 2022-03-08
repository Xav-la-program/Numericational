#include "RandomGenerator.h"
#include <math.h>
#include <vector>

RandomGenerator::RandomGenerator()
{
    //ctor
}

std::vector<double> RandomGenerator::GenerateVector(int n)
{
    std::vector<double> res(n);

    for (int i = 0; i < n; ++i)
     {
        res[i] = Generate();
     }

    return res;
}

double RandomGenerator::Mean(myLong nbSim)
{

    lastGeneratedNumbers = std::vector<double>(nbSim);
    double result = 0.;

    for (myLong i = 0; i<nbSim; ++i)
    {
        double currentNumber = Generate();
        result += currentNumber / nbSim; //we divide here to decrease the risk of memory crash
        lastGeneratedNumbers[i] = currentNumber;
    }

    return result;
}

double RandomGenerator::Variance(myLong nbSim)
{
    double result = 0.;

    double mean = Mean(nbSim);

    for (myLong i = 0; i<nbSim; ++i)
    {
        double currentNumber = lastGeneratedNumbers[i]; //so that Generate() is not called to many times
        result += pow((currentNumber - mean),2) / nbSim;
    }

    return result;
}

RandomGenerator::~RandomGenerator()
{
    //dtor
}
