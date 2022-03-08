#pragma once
#include "RandomProcess.h"

class BS1D : public RandomProcess
{
	public:
		BS1D();
		BS1D(RandomGenerator* _gen, double _s, double _r, double _vol);


	protected:
		
		double s;
		double r;
		double vol;
		


};

