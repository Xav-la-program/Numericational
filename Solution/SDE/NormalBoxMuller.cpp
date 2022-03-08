#include "NormalBoxMuller.h"
#include "cmath"
#include <math.h>


NormalBoxMuller::NormalBoxMuller()
{
    //ctor
}

NormalBoxMuller::NormalBoxMuller(double _mu, double _sigma, UniformGenerator* _gen): Normal(_mu, _sigma, _gen)
{

}

static double M_PI = 3.14;

double NormalBoxMuller::Generate()
{
    if(IsNewSimRequired)
    {
        double U1 = generatorPtr->Generate();
        double U2 = generatorPtr->Generate();
        
        double R = pow(-2 * log(U1), 0.5);
        double O = 2 * M_PI * U2;

        Y = R * sin(O);
        IsNewSimRequired = false;

        double X = R * cos(O);

        return sigma * X + mu;
    }

    else
    {
        IsNewSimRequired = true;
        return sigma * Y + mu;

    }
}



NormalBoxMuller::~NormalBoxMuller()
{
    //dtor
}
