#include "PlotCaller.h"



PlotCaller::PlotCaller()
{
}


PlotCaller::~PlotCaller()
{
	for (int i = 0; i < m_listeOfGraph.size(); i++)
		m_listeOfGraph[i].join();
}

void caca(std::vector<float> x, std::vector<float> y, PLotSetting s) {
	
	Graphique g(s.titre, s.largeur, s.hauteur);
	g.setColor(s.color);
	g.setClearColor(s.clearColor);

	g.initSFML();
	if (!g.initOpenGL())
		std::cout << "erreur l'or de l'initialisation " << std::endl;

	g.charger();
	g.drawFunction(x, y);
	
	if (!s.add)
		g.run();
}
void PlotCaller::plot(std::vector<float> x, std::vector<float> y, PLotSetting s)//attention je ne considere que une courbes par graphs pour le moment, j'aimis une notes quand on voudras supperposé
{
	m_listeOfGraph.push_back(std::thread(caca,x,y,s));
}
