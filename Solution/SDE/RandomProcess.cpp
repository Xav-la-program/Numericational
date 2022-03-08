#include "pch.h"
#include "RandomProcess.h"
#include <vector>
#include "SinglePath.h"


RandomProcess::RandomProcess()
{
}

RandomProcess::RandomProcess(RandomGenerator* _gen, int _dim)
	:gen(_gen), dim(_dim), paths(_dim, new SinglePath())
{
	
}

void RandomProcess::add_path(SinglePath* Path)
{
	paths.push_back(Path);
}

double RandomProcess::GetValue(double time, int dim)
{
	return paths[dim]->get_value(time);
}

