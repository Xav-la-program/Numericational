#pragma once
#include "BS1D.h"

class BSEULER1D : public BS1D
{
	public:
		BSEULER1D();
		BSEULER1D(RandomGenerator* _gen, double _s, double _r, double _vol);
		void Simulate(double start_time, double end_time, size_t nb_steps);

		//double GetValue(double time);


};

