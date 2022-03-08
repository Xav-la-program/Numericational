#ifndef NORMALBOXMULLER_H
#define NORMALBOXMULLER_H

#include "Normal.h"

class NormalBoxMuller : public Normal
{
    public:
        NormalBoxMuller();
        NormalBoxMuller(double _mu, double _sigma, UniformGenerator* _gen);

        virtual double Generate();


        virtual ~NormalBoxMuller();

    protected:


    private:

        double Y;
        bool IsNewSimRequired = true;
};

#endif // NORMALBOXMULLER_H
