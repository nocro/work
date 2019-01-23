#include "Graphique.h"



Graphique::Graphique(std::string titre, int largeur, int hauteur):m_titreFenetre(titre), m_largeurFenetre(largeur), m_hauteurFenetre(hauteur), m_shader("shaders/basic.vert","shaders/basic.frag"),
																m_color(1.0,0.0,0.0)
{
	
	
}


Graphique::~Graphique()
{
}


void Graphique::charger()
{
	m_shader.charger();
}

void Graphique::initSFML()
{
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 4;
	settings.majorVersion = 3;//version opengl (ici3.3)
	settings.minorVersion = 3;//version opengl
	m_window.create(sf::VideoMode(m_largeurFenetre, m_hauteurFenetre), m_titreFenetre, sf::Style::Default, settings);
}

bool Graphique::initOpenGL()
{
	GLenum initialisationGLEW(glewInit());

	if (initialisationGLEW != GLEW_OK)
	{
		std::cout << "Erreur d'initialisation de GLEW : " << glewGetErrorString(initialisationGLEW) << std::endl;
		return false;
	}

	m_window.setVerticalSyncEnabled(true);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	//glEnable(GL_DEPTH_TEST);//test profondeur
	//glDisable(GL_DEPTH_TEST);
	//glEnable(GL_BLEND);
	//glEnable(GL_POLYGON_SMOOTH);
	glEnable(GL_MULTISAMPLE);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	return true;

}


void Graphique::tmp()
{
	bool running = true;
	//drawFunction(x, y);
	while (running)
	{

		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed or sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				// on stoppe le programme
				running = false;
			}

		}

		//actualisation de la fenetre
		//m_window.display();

	}
}
void Graphique::run() 
{
	//glEnable(GL_MULTISAMPLE);
	//glViewport(0, 0, m_largeurFenetre, m_hauteurFenetre);
	

	bool running = true;
	//drawFunction(x, y);
	while (running)
	{

		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed or sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				// on stoppe le programme
				running = false;
			}

		}

		//actualisation de la fenetre
		//m_window.display();

	}
	//std::thread p(tmp);
	
}

void Graphique::drawFunction(std::vector<float> x, std::vector<float> y)
{
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawAxes();
	int n = std::min(x.size(), y.size());
	std::vector<float> zizi;
	zizi.push_back(x[0]);
	zizi.push_back(y[0]);
	for (int i = 1; i < n-1; i++)
	{
		zizi.push_back(x[i]);
		zizi.push_back(y[i]);
		zizi.push_back(x[i]);
		zizi.push_back(y[i]);
	}
	zizi.push_back(x[n-1]);
	zizi.push_back(y[n-1]);


	glUseProgram(m_shader.getProgramID());



	// On remplie puis on active le tableau Vertex Attrib 0
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, &zizi[0]);
	glEnableVertexAttribArray(0);

	glUniform3fv(glGetUniformLocation(m_shader.getProgramID(), "Ucolor"), 1, value_ptr(m_color));



	glDrawArrays(GL_LINES, 0,zizi.size()/2);


	// On désactive le tableau Vertex Attrib puisque l'on n'en a plus besoin
	glDisableVertexAttribArray(0);

	glUseProgram(0);

	m_window.display();


}

void Graphique::drawAxes()
{
	float axes[] = { -1.0, 0.0,   1.0, 0.0,  0.0, -1.0,  0.0, 1.0 };
	//on charge le shader
	glUseProgram(m_shader.getProgramID());



	// On remplie puis on active le tableau Vertex Attrib 0
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, axes);
	glEnableVertexAttribArray(0);

	glUniform3fv(glGetUniformLocation(m_shader.getProgramID(), "Ucolor"), 1, value_ptr(m_color));



	glDrawArrays(GL_LINES, 0, 4);


	// On désactive le tableau Vertex Attrib puisque l'on n'en a plus besoin
	glDisableVertexAttribArray(0);


	//on decharge le shader
	glUseProgram(0);
}

