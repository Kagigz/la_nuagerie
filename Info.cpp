#include "Info.h"

nuagerie::info::info()
{
	using nuagerie::info;
	m_infostate = infostate::uninitialized;

}

nuagerie::info::~info()
{

}

void nuagerie::info::show(sf::RenderWindow& window)
{
	using nuagerie::info;

	sf::VideoMode mode = sf::VideoMode(1200, 800);
	float scaleX = mode.width / 1200.f;
	float scaleY = mode.height / 800.f;

	window.setKeyRepeatEnabled(false);
	window.setFramerateLimit(60);

								 
	if (!m_infostate == infostate::uninitialized)
		return;

	m_infostate = infostate::showing;


	sf::Font myfont;
	if (!myfont.loadFromFile("fonts/libels.ttf"))
	{
		std::cerr << "Font libels not loaded" << std::endl;
	}

	sf::Text title("INFOS", myfont, 150);
	title.setColor(sf::Color(95,188,223));
	title.setPosition(600 - title.getGlobalBounds().width / 2, 20);


	sf::Text auteurLabel("Auteur", myfont, 70);
	auteurLabel.setPosition(600 - auteurLabel.getGlobalBounds().width/2,300);
	auteurLabel.setColor(sf::Color::Black);

	sf::Text auteur("Katia GIL GUZMAN", myfont, 50);
	auteur.setPosition(600 - auteur.getGlobalBounds().width/2, 320 + auteurLabel.getGlobalBounds().height);
	auteur.setColor(sf::Color::Black);

	sf::Text projetLabel("Projet", myfont, 70);
	projetLabel.setPosition(600 - projetLabel.getGlobalBounds().width/2, 450);
	projetLabel.setColor(sf::Color::Black);

	sf::Text projet("Projet réalisé dans le cadre de la VAP JIN à Telecom SudParis", myfont, 50);
	projet.setPosition(600 - projet.getGlobalBounds().width/2, 470 + projetLabel.getGlobalBounds().height);
	projet.setColor(sf::Color::Black);

	sf::Text projet2("Temps alloué : 1 mois", myfont, 30);
	projet2.setPosition(600 - projet2.getGlobalBounds().width / 2, 490 + projet.getGlobalBounds().height + projetLabel.getGlobalBounds().height);
	projet2.setColor(sf::Color::Black);

	sf::Text retour("Appuyez sur R pour revenir au menu", myfont, 20);
	retour.setPosition(600 - retour.getGlobalBounds().width / 2, 750);
	retour.setColor(sf::Color(95,188,223));


	sf::Texture tex;
	if (!tex.loadFromFile("img/nuages.png"))
	{
		std::cerr << "Nuages.png not loaded" << std::endl;
	}

	bg.setTexture(tex);
	bg.setOrigin(0.f, 0.f);
	bg.setPosition(0.f, 0.f);


	bool running = true;
	sf::Event e;
	while (running)
	{
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				m_infostate = infostate::done;
				return;
			}

			if (e.type == sf::Event::KeyPressed)
			{
				switch (e.key.code)
				{
				case sf::Keyboard::Escape:
				{
					m_infostate = infostate::done;
					return;
				}
				break;

				case sf::Keyboard::R:
				{
					m_infostate = infostate::done;
					return;
				}
				break;

				default:
					break;
				}
			}
		}


	
		window.clear(sf::Color(55, 55, 55, 255));
		window.draw(bg);
		window.draw(title);
		window.draw(auteurLabel);
		window.draw(auteur);
		window.draw(projetLabel);
		window.draw(projet);
		window.draw(projet2);
		window.draw(retour);
		window.display();
	}
	return;
}

//instantiate static members
sf::Uint32 nuagerie::info::m_infostate = nuagerie::info::infostate::uninitialized;
