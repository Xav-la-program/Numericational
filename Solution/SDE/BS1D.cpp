#include "BS1D.h"


BS1D::BS1D()
{
}

BS1D::BS1D(RandomGenerator* _gen, double _s, double _r, double _vol)
	: RandomProcess(_gen, 1), s(_s), r(_r), vol(_vol)
{
}