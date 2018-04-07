#include "Rules.h"

nuagerie::rules::rules()
{
	//reset the state each time the object is created
	using nuagerie::rules;
	m_rulestate = rulestate::s_uninitialized;

}

nuagerie::rules::~rules()
{

}

void nuagerie::rules::show(sf::RenderWindow& window)
{
	using nuagerie::rules;

	sf::VideoMode mode = sf::VideoMode(1200, 800);
	float scale = mode.width / 1200.f;

	window.setKeyRepeatEnabled(false);
	window.setFramerateLimit(60);

	if (!m_rulestate == rulestate::s_uninitialized)
		return;


	sf::Texture tex;
	if (!tex.loadFromFile("img/nuages.png"))
	{
		std::cerr << "Nuages.png not loaded" << std::endl;
	}

	bg.setTexture(tex);
	bg.setOrigin(0.f, 0.f);
	bg.setPosition(0.f, 0.f);

	sf::Font myfont;
	if (!myfont.loadFromFile("fonts/libels.ttf"))
	{
		std::cerr << "Font libels not loaded." << std::endl;
	}

	sf::Text title("REGLES", myfont, 150);
	title.setColor(sf::Color(95, 188, 223));
	title.setPosition(600 - title.getGlobalBounds().width / 2, 20);

	sf::Text principeLabel("Principe :", myfont, 80);
	principeLabel.setColor(sf::Color::Black);
	principeLabel.setPosition(150, 200);
	sf::Text principe1("Le but du jeu est de tailler le bloc de nuage du niveau pour qu'il atteigne le nuage objectif.", myfont, 30);
	principe1.setColor(sf::Color::Black);
	principe1.setPosition(150, 300);
	sf::Text principe2("Vous perdez une vie lorsque vous détruisez un carré de nuage qui ne devait pas être détruit.", myfont, 30);
	principe2.setColor(sf::Color::Black);
	principe2.setPosition(150, 330);
	sf::Text principe3("Vous gagnez lorsque vous réussissez les 5 niveaux.", myfont, 30);
	principe3.setColor(sf::Color::Black);
	principe3.setPosition(150, 360);
	
	sf::Text ctrlsLabel("Commandes :", myfont, 80);
	ctrlsLabel.setColor(sf::Color::Black);
	ctrlsLabel.setPosition(600 - ctrlsLabel.getGlobalBounds().width / 2, 420);
	sf::Text ctrls1("Barre d'espace : Tirer", myfont, 40);
	ctrls1.setColor(sf::Color::Black);
	ctrls1.setPosition(600 - ctrls1.getGlobalBounds().width / 2, 520);
	sf::Text ctrlsLabel2("Commandes de test :", myfont, 30);
	ctrlsLabel2.setColor(sf::Color::Black);
	ctrlsLabel2.setPosition(600 - ctrlsLabel2.getGlobalBounds().width / 2, 580);
	sf::Text ctrls2("W : Win\n L : Lose\n U : Lvl up\n T : Position tireur\n", myfont, 20);
	ctrls2.setColor(sf::Color::Black);
	ctrls2.setPosition(600 - ctrls2.getGlobalBounds().width / 2, 630);

	sf::Text retour("Appuyez sur R pour revenir au menu", myfont, 20);
	retour.setPosition(600 - retour.getGlobalBounds().width / 2, 750);
	retour.setColor(sf::Color(95, 188, 223));


	bool running = true;
	sf::Event e;
	while (running)
	{
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				m_rulestate = rulestate::s_done;
				return;
			}

			if (e.type == sf::Event::KeyPressed)
			{
				switch (e.key.code)
				{
				case sf::Keyboard::Escape:
				{
					m_rulestate = rulestate::s_done;
					return;
				}
				break;

				
				case sf::Keyboard::R:
				{
					m_rulestate = rulestate::s_done;
					return;
				}

				default:
					break;
				}
			}

		}



		window.clear();

		window.draw(bg);
		window.draw(title);
		window.draw(principeLabel);
		window.draw(principe1);
		window.draw(principe2);
		window.draw(principe3);
		window.draw(ctrlsLabel);
		window.draw(ctrls1);
		window.draw(ctrlsLabel2);
		window.draw(ctrls2);
		window.draw(retour);

		window.display();
	}

	return;
}

//instantiate static members
sf::Uint32 nuagerie::rules::m_rulestate = nuagerie::rules::rulestate::s_uninitialized;
