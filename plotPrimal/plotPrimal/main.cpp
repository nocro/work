#include <iostream>
#include "PlotCaller.h"
using namespace std;




float f(float x)
{
	return x * x;
}

int main()
{
	




	std::vector<float> x, y;
	for (float i = -1.0; i < 1.0; i += 0.01)
	{
		x.push_back(i);
		float tmp = f(i);
		y.push_back(tmp);
		//std::cout << i << "  " << tmp << std::endl;
	}
	PLotSetting s;
	PlotCaller p;
	p.plot(x, y, s);
	s.color = glm::vec3(0.0, 0.0, 1.0);
	s.largeur = 400;
	s.hauteur = 400;
	p.plot(x, y, s);

	return 0;
}