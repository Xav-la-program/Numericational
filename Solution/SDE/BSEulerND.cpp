#include "BSEulerND.h"
#include <Eigen/Cholesky>
//#include <Eigen/Dense>

std::vector<double> operator*(std::vector<double> lhs, double rhs)
{
	size_t dim = lhs.size();
	std::vector<double> result(dim);
	for (size_t i = 0; i < dim; i++)
	{
		result[i] = lhs[i] * rhs;
	}
	return result;
}

BSEulerND::BSEulerND()
{
}

BSEulerND::BSEulerND(RandomGenerator* _gen, int _dim, std::vector<double> _s, std::vector<double> _r, Eigen::MatrixXd _V)
	: BSND(_gen, _dim, _s, _r, _V)
{
	B = V.llt().matrixL(); //to check
}

void BSEulerND::Simulate(double start_time, double end_time, size_t nb_steps)
{
	double dt = (end_time - start_time) / nb_steps;
	Eigen::VectorXd last = Eigen::Map<Eigen::VectorXd, Eigen::Unaligned>(s.data(), s.size());

	for (int i = 0; i < dim; ++i)
	{
		paths[i] = new SinglePath(start_time, end_time, nb_steps);
		paths[i]->add_value(last[i]);
	}

	for (int i = 0; i < nb_steps; ++i)
	{
		std::vector<double> dW = gen->GenerateVector(dim) * pow(dt, 0.5);
		Eigen::VectorXd dW_M = Eigen::Map<Eigen::VectorXd, Eigen::Unaligned>(dW.data(), dW.size());
		std::vector<double> M = r * dt;
		Eigen::VectorXd M_M = Eigen::Map<Eigen::VectorXd, Eigen::Unaligned>(M.data(), M.size());
		Eigen::VectorXd Z = M_M + (B * dW_M);
		Eigen::VectorXd next = last + last.cwiseProduct(Z);
		last = next;


		for (int j = 0; j < dim; j++)
		{
			paths[j]->add_value(last[j]);
		}
	}
}




