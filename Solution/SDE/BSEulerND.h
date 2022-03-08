#include "BSND.h"
#include <Eigen/Dense>

class BSEulerND : public BSND
{
	public:

		BSEulerND();
		BSEulerND(RandomGenerator* _gen, int _dim, std::vector<double> _s, std::vector<double> _r, Eigen::MatrixXd _V);

		void Simulate(double start_time, double end_time, size_t nb_steps);

	private:

		Eigen::MatrixXd B;

};

std::vector<double> operator*(std::vector<double> lhs, double rhs);


