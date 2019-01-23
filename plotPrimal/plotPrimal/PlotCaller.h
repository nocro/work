#ifndef PLOTCALLER_H
#define PLOTCALLER_H


#include "Graphique.h"
#include <thread>

struct PLotSetting
{
	PLotSetting(): color(glm::vec3(1.0, 0.0, 0.0)), largeur(500), hauteur(500), add(false), titre("no title"), clearColor(glm::vec3(1.0,1.0,1.0))
	{

	}
	int largeur;
	int hauteur;
	glm::vec3 color;
	bool add;
	glm::vec3 clearColor;
	std::string titre;
	

};
class PlotCaller
{
public:
	PlotCaller();
	~PlotCaller();
	void plot(std::vector<float>x, std::vector<float>y, PLotSetting s);

private:
	std::vector<std::thread> m_listeOfGraph;
};

#endif // !PLOTCALLER_H