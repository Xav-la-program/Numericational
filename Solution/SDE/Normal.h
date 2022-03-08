#ifndef NORMAL_H
#define NORMAL_H

#include "ContinuousGenerator.h"
#include "UniformGenerator.h"

class Normal : public ContinuousGenerator
{
    public:
        Normal();
        Normal(double _mu, double _sigma, UniformGenerator* _gen);

        virtual ~Normal();

    protected:

        double mu;
        double sigma;

    private:


};

#endif // NORMAL_H
