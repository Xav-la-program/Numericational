#include "RandomProcess.h"
#include <Eigen/Dense>
#include <vector>

class BSND : public RandomProcess
{
	public:
		BSND();
		BSND(RandomGenerator* _gen, int _dim, std::vector<double> _s, std::vector<double> _r, Eigen::MatrixXd _V);


	protected:

		std::vector<double> s;
		std::vector<double> r;
		Eigen::MatrixXd V;



};

