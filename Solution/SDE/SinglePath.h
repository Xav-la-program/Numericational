#pragma once
#include <vector>
#include <iostream>

class SinglePath
{
	public: 
		SinglePath();
		SinglePath(double _start_time, double _end_time, size_t _nb_steps);
		void add_value(double val);
		double get_value(double time);
		/*double get_all_values();*/
		void print_vector();

		double time_steps{};
	
	protected:
		double start_time{};
		double end_time{};
		size_t nb_steps{};
		
		std::vector<double> values {}; //valeur du stock
		std::vector<double> times {}; //temps auquel on est
			
};

