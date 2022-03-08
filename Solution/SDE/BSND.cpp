#include "BSND.h"

BSND::BSND()
{
}

BSND::BSND(RandomGenerator* _gen, int _dim, std::vector<double> _s, std::vector<double> _r, Eigen::MatrixXd _V)
	: RandomProcess(_gen, dim), s(_s), r(_r), V(_V)
{

}