#include "Menu.h"

nuagerie::menu::menu()
{
	using nuagerie::menu;

	m_choice = choice::s_uninitialized;
		
}

nuagerie::menu::~menu()
{

}

void nuagerie::menu::show(sf::RenderWindow& window)
{
	using nuagerie::menu;

	sf::VideoMode mode = sf::VideoMode(1200, 800);
	float scale = mode.width;
	m_winsizeX = mode.width;
	m_winsizeY = mode.height;

	window.setKeyRepeatEnabled(false);
	window.setFramerateLimit(60);

	if (!m_choice == choice::s_uninitialized)
		return;

	m_choice = choice::s_undecided;

	//font
	sf::Font standardfont;
	if (!standardfont.loadFromFile("fonts/adamg.otf"))
	{
		std::cerr << "Font adamg not loaded" << std::endl;
	}

	//title
	sf::Texture bgtex;
	if (!bgtex.loadFromFile("img/title.png"))
	{
		std::cerr << "Title not loaded" << std::endl;
	}

	sf::Sprite title;
	title.setTexture(bgtex);
	title.setOrigin(title.getGlobalBounds().width / 2.f, title.getGlobalBounds().height / 2.f);
	title.setPosition(1200 / 2.f, 800 / 6.f);
	title.setColor(sf::Color(255, 255, 255, 255));


	sf::Text play("Jouer", standardfont, 90);
	play.setOrigin(play.getGlobalBounds().width / 2.f, play.getGlobalBounds().height / 2.f);
	play.setPosition(600, 400);

	sf::Text info("Infos", standardfont, 80);
	info.setOrigin(info.getGlobalBounds().width / 2.f, info.getGlobalBounds().height / 2.f);
	info.setPosition(600, 500);

	sf::Text rules("Règles", standardfont, 80);
	rules.setOrigin(rules.getGlobalBounds().width / 2.f, rules.getGlobalBounds().height / 2.f);
	rules.setPosition(600,600);


	//background image
	sf::Texture tex;
	if (!tex.loadFromFile("img/nuages2.png"))
	{
		std::cerr << "Nuages2.png not loaded" << std::endl;
	}

	bg.setTexture(tex);
	bg.setOrigin(0.f, 0.f);
	bg.setPosition(0.f, 0.f);

	//housekeeping variables for keeping track of the selection
	std::size_t selection = 0;
	std::size_t boundcount = 0;
	std::size_t hovercount = 0;

	bool running = true;
	sf::Event e;

	//time stuff...
	sf::Clock tickClock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
	sf::Time fadeInFrames = sf::Time::Zero;
	sf::Time fadeOutFrames = sf::Time::Zero;
	sf::Time moveText = sf::Time::Zero;
	sf::Time colorChanger = sf::Time::Zero;
	int colorSwitch = 1;

	while (running)
	{
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				m_choice = choice::s_quit;
				return;
			}

			if (e.type == sf::Event::KeyPressed)
			{
				switch (e.key.code)
				{
				case sf::Keyboard::Escape:
				{
					m_choice = choice::s_quit;
					return;
				}
				break;

				case sf::Keyboard::Return:
				{
					return;
				}
				break;

				case sf::Keyboard::Up:
				{
					if (selection <= 0)
					{
						boundcount++;
						selection = 0;
						std::cout << "bound count : " << boundcount << std::endl;
					}
					else
					{
						selection--;
						boundcount = 0;
						std::cout << "bound count : " << boundcount << std::endl;
					}
				}
				break;

				case sf::Keyboard::Down:
				{
					if (selection >= 2)
					{
						boundcount++;
						selection = 2;
						std::cout << "bound count : " << boundcount << std::endl;
					}
					else
					{
						boundcount = 0;
						selection++;
						std::cout << "bound count : " << boundcount << std::endl;
					}
				}
				break;

				default:
					break;
				}
			}

			sf::Vector2i mousepos = sf::Mouse::getPosition(window);
			if (mousepos.x >= play.getPosition().x
				&& mousepos.y >= play.getPosition().y
				&& mousepos.x <= play.getPosition().x + play.getGlobalBounds().width
				&& mousepos.y <= play.getPosition().y + play.getGlobalBounds().height)
			{

				//set selection to play
				//and keep track of mouse over text
				selection = 0;
				hovercount++;

				if (e.type == sf::Event::MouseButtonPressed)
				{
					return;
				}

			}

			else if (mousepos.x >= info.getPosition().x
				&& mousepos.y >= info.getPosition().y
				&& mousepos.x <= info.getPosition().x + info.getGlobalBounds().width
				&& mousepos.y <= info.getPosition().y + info.getGlobalBounds().height)
			{

				//set selection to info
				//and keep track of mouse over text
				selection = 1;
				hovercount++;

				if (e.type == sf::Event::MouseButtonPressed)
				{
					return;
				}
			}

			else if (mousepos.x >= rules.getPosition().x
				&& mousepos.y >= rules.getPosition().y
				&& mousepos.x <= rules.getPosition().x + rules.getGlobalBounds().width
				&& mousepos.y <= rules.getPosition().y + rules.getGlobalBounds().height)
			{

				//set selection to rules
				//and keep track of mouse over text
				selection = 2;
				hovercount++;

				if (e.type == sf::Event::MouseButtonPressed)
				{
					return;
				}
			}
			else
				hovercount = 0;
		}


		timeSinceLastUpdate += tickClock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
				
			switch (selection)
			{
			case 0:
			{
				m_choice = choice::s_play;

				play.setColor(sf::Color(95,188,223));
				info.setColor(sf::Color::White);
				rules.setColor(sf::Color::White);
			}
			break;

			case 1:
			{
				m_choice = choice::s_info;

				play.setColor(sf::Color::White);
				info.setColor(sf::Color(95,188,223));
				rules.setColor(sf::Color::White);
			}
			break;

			case 2:
			{
				m_choice = choice::s_rules;

				play.setColor(sf::Color::White);
				info.setColor(sf::Color::White);
				rules.setColor(sf::Color(95,188,223));
			}
			break;

			default:
				break;
			}
			
	}

	window.clear();

	window.draw(bg);
	window.draw(title);
	window.draw(play);
	window.draw(info);
	window.draw(rules);
	window.display();
	}
	return;
}

//instantiate static members
nuagerie::menu::choice nuagerie::menu::m_choice = nuagerie::menu::choice::s_uninitialized;
