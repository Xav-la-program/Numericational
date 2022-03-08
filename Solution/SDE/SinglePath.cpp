#include "pch.h"
#include "SinglePath.h"
#include <vector>
#include <iostream>
#include <algorithm>


SinglePath::SinglePath()
{
}

SinglePath::SinglePath(double _start_time, double _end_time, size_t _nb_steps)
	: start_time(_start_time), end_time(_end_time), nb_steps(_nb_steps)
{
	time_steps = (end_time - start_time) / nb_steps;
	times.push_back(_start_time);


}


void SinglePath::add_value(double val)
{
	values.push_back(val);
	if (values.size() > 1)
	{
		times.push_back(times[times.size() - 1] + time_steps);
	}

}

double SinglePath::get_value(double time)
{
	size_t i = 1;
	if (time + 1 < times.size())
	{
		while (times[i] <= time)
		{
			i++;
		}
	}
	
	else
	{
		i = times.size();
	}

	if (times[i - 1] == time)
	{
		return values[i - 1];
	}
	else
	{
		return ((time - times[i - 1]) * values[i] + (times[i] - time) * values[i - 1]) / (time_steps);
	}

}



void SinglePath::print_vector()
{
	for (size_t i = 0; i < times.size(); ++i)
	{
		std::cout << "t = " << times[i] << " ; value = " << get_value(times[i]) << std::endl;
	}
}

