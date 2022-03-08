#include "pch.h"
#include "BSEULER1D.h"
#include "SinglePath.h"
#include <iostream>


BSEULER1D::BSEULER1D()
{
}

BSEULER1D::BSEULER1D(RandomGenerator* _gen, double _s, double _r, double _vol)
	: BS1D(_gen, _s, _r, _vol)
{
}

void BSEULER1D::Simulate(double start_time, double end_time, size_t nb_steps)
{
	
	SinglePath* path = new SinglePath(start_time, end_time, nb_steps);
	path->add_value(s);
	double last = s;
	double dt = path->time_steps;
	
	for (size_t i = 0; i < nb_steps; i++)
	{
		

		double dW = pow(dt, 0.5) * gen->Generate();
		double next = last + last * (r * dt + vol * dW);
		//std::cout << "simulation " << i << ": " << last << std::endl;
		path->add_value(next);
		last = next; 
	}

	//std::cout << "Simulation ok" << std::endl;

	if (paths[0])
		delete paths[0];
	paths[0] = path;

	
}