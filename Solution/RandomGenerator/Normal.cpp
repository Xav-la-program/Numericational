#include "Normal.h"
#include "UniformGenerator.h"

Normal::Normal()
{
    //ctor
}

Normal::Normal(double _mu, double _sigma, UniformGenerator* _gen): mu(_mu), sigma(_sigma), ContinuousGenerator(_gen)
{

}

Normal::~Normal()
{
    //dtor
}
