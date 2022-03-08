#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <vector>

typedef unsigned long long myLong;



class RandomGenerator
{
    public:
        RandomGenerator(); //ctor

        virtual double Generate() = 0;
        std::vector <double> GenerateVector(int n);
        //abstract class (at least 1 method not implemented): we can't instanciate it as such but Mean and Variance can be used by inherited class
        double Mean(myLong nbSim);
        double Variance(myLong nbSim);

        std::vector<double> lastGeneratedNumbers; //can be used by the methods

        virtual ~RandomGenerator(); //dtor

    protected:

    private:
};

#endif // RANDOMGENERATOR_H
