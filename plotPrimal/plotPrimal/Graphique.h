#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H

#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <iostream>
#include <vector>
#include "shader.h"
#include <thread>

class Graphique
{
public:
	Graphique(std::string titre, int largeur, int hauteur);
	~Graphique();
	void charger();
	void initSFML();
	bool initOpenGL();
	void tmp();
	void run();
	void drawFunction(std::vector<float> x , std::vector<float> y);
	void drawAxes();
	void setColor(glm::vec3 newColor){
		m_color = newColor;
	}
	void setClearColor(glm::vec3 color) {

		glClearColor(color.x, color.y, color.z, 0.0f);
	}

	//juste pour les test
	


private:
	std::string m_titreFenetre;
	int m_largeurFenetre;
	int m_hauteurFenetre;
	Shader m_shader;

	glm::vec3 m_color;

	sf::Window m_window;
	sf::ContextSettings settings;
	sf::Event m_evenements;
	
};

#endif