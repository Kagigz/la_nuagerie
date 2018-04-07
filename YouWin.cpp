#include "YouWin.h"

nuagerie::youwin::youwin()
{
	using nuagerie::youwin;
	m_winState = winState::uninitialized;

}

nuagerie::youwin::~youwin()
{

}

void nuagerie::youwin::show(sf::RenderWindow& window)
{
	using nuagerie::youwin;

	sf::VideoMode mode = sf::VideoMode(1200, 800);
	float scale = mode.width / 1200.f;

	window.setKeyRepeatEnabled(false);
	window.setFramerateLimit(60);

	if (!m_winState == winState::uninitialized)
		return;

	m_winState = winState::showing;


	// Background image
	sf::Texture tex;
	if (!tex.loadFromFile("img/you_win.png"))
	{
		std::cerr << "you_win.png not loaded" << std::endl;
	}

	bg.setTexture(tex);
	bg.setOrigin(0.f, 0.f);
	bg.setPosition(0.f, 0.f);

	// Font
	sf::Font myfont;
	if (!myfont.loadFromFile("fonts/libels.ttf"))
	{
		std::cerr << "Font libels not loaded." << std::endl;
	}

	// TEXT

	sf::Text retour("Appuyez sur R pour revenir au menu", myfont, 20);
	retour.setPosition(600 - retour.getGlobalBounds().width / 2, 750);
	retour.setColor(sf::Color(95, 188, 223));

	//time stuff...
	sf::Clock tickClock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
	sf::Time messageFrames = sf::Time::Zero;
	sf::Time aliveFrames = sf::Time::Zero;
	int colorSwitch = 1;

	bool running = true;
	sf::Event e;
	while (running)
	{
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				m_winState = winState::done;
				return;
			}

			if (e.type == sf::Event::KeyPressed)
			{
				switch (e.key.code)
				{

				case sf::Keyboard::Escape:
				{
					m_winState = winState::done;
					return;
				}
				break;
				case sf::Keyboard::R:
				{
					m_winState = winState::done;
					return;
				}
				break;

				default:
					break;
				}
			}
		}

		//handle game ticks and return a fixed dt
		//for updates
		timeSinceLastUpdate += tickClock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
		
		}

		if (aliveFrames.asSeconds() > 10.f)
		{
			m_winState = winState::done;
			return;
		}
		else
			m_winState = winState::showing;

		window.clear();

		window.draw(bg);
		window.draw(retour);

		window.display();
	}
	return;
}
