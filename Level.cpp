#include "Level.h"

nuagerie::level::level(sf::RenderWindow& window, int niv)
{
	using nuagerie::level;
	m_levelstate = levelstate::uninitialized;


	// Initialization
	m_numLives = 5;
	lvl = niv;


	// Load fonts
	if (!m_myfont.loadFromFile("fonts/libels.ttf"))
	{
		std::cerr << "Font libels not loaded." << std::endl;
	}

	// Load fonts
	if (!titleFont.loadFromFile("fonts/adamg.otf"))
	{
		std::cerr << "Font adamg not loaded." << std::endl;
	}

	// Load texture for shots
	if (!texShots.loadFromFile("img/tir.png"))
	{
		std::cerr << "tir.png not loaded" << std::endl;
	}

	texShotPtr = &texShots;

	// Text for intro
	titleIntro = sf::Text("Niveau 1", titleFont, 200);
	titleIntro.setPosition(450-titleIntro.getGlobalBounds().width/2, 200);
	titleIntro.setColor(sf::Color::Black);
	msgIntro = sf::Text("", m_myfont, 150);
	msgIntro.setPosition(450, 200);
	msgIntro.setColor(sf::Color::Black);

}

nuagerie::level::~level()
{

}

void nuagerie::level::show(sf::RenderWindow& window)
{
	using nuagerie::level;

	sf::VideoMode mode = sf::VideoMode(1200, 800);
	m_scaleX = mode.width / 1200.f;
	m_scaleY = mode.height / 800.f;

	m_winsizeX = mode.width;
	m_winsizeY = mode.height;

	sf::ContextSettings settings;

	settings = window.getSettings();

	window.setKeyRepeatEnabled(false);
	window.setFramerateLimit(60);


	if (!m_levelstate == levelstate::uninitialized)
		return;

	m_levelstate = levelstate::playing;

	//if success, lvl is completed
	success = false;

	//set up cloud
	//nuagerie::cloud nuage(0); => to test lvl changes (destroy square[2,9])
	nuagerie::cloud nuage(lvl);
	nuage.setPosition(0, 0);
	sf::Vector2i collisionSquare(-1, -1);
	bool shotCollision = false;

	//set up player stuff
	player.setPosition(20, 650);
	sf::Uint32 initialLives = m_numLives;
	bool moveToRight = true;

	bool shooting = false;

	std::string pathObjectif = "img/cloud1.png";

	// Level setup
	switch (lvl)
	{

	case 1:
	{
		pathObjectif = "img/cloud1.png";
		player.setSpeed(1);
	}
	break;
	case 2:
	{
		pathObjectif = "img/cloud2.png";
		player.setSpeed(2);
	}
	break;
	case 3:
	{
		pathObjectif = "img/cloud3.png";
		player.setSpeed(3);
	}
	break;
	case 4:
	{
		pathObjectif = "img/cloud4.png";
		player.setSpeed(4);
	}
	break;
	case 5:
	{
		pathObjectif = "img/cloud5.png";
		player.setSpeed(5);
	}
	break;
	default:

		break;
	}

	//objectif image
	sf::Texture tex_objectif;
	if (!tex_objectif.loadFromFile(pathObjectif))
	{
		std::cerr << "objectif image not loaded" << std::endl;
	}

	objectif_img.setTexture(tex_objectif);
	objectif_img.setOrigin(0.f, 0.f);
	objectif_img.setPosition(910.f, 120.f);
	objectif_img.setTextureRect(sf::IntRect(0, 0, 280, 140));

	//background image
	sf::Texture tex;
	if (!tex.loadFromFile("img/lvl_bg.png"))
	{
		std::cerr << "lvl_bg.png not loaded" << std::endl;
	}

	bg.setTexture(tex);
	bg.setOrigin(0.f, 0.f);
	bg.setPosition(0.f, 0.f);


	// TEXT

	sf::Text objectifLabel("Objectif :", m_myfont, 30);
	objectifLabel.setPosition(950, 30);
	objectifLabel.setColor(sf::Color::White);


	sf::Text retour("RETOUR", m_myfont, 50);
	retour.setPosition(1050 - retour.getGlobalBounds().width/2, 700);
	retour.setColor(sf::Color::White);
	sf::Text retour2("(Appuyez sur R)", m_myfont, 20);
	retour2.setPosition(1050 - retour2.getGlobalBounds().width/2, 760);
	retour2.setColor(sf::Color::White);

	sf::Text lvlLabel("Nuage n°", m_myfont, 40);
	lvlLabel.setColor(sf::Color::White);
	sf::Text lvlLabel2("4", m_myfont, 70);
	lvlLabel2.setColor(sf::Color(95,188,223));
	lvlLabel.setPosition(950, 400 - lvlLabel.getGlobalBounds().height/2);
	lvlLabel2.setPosition(1100, 380 - lvlLabel2.getGlobalBounds().height / 2);

	sf::Text livesLabel("vies", m_myfont, 40);
	livesLabel.setColor(sf::Color::White);
	sf::Text livesLabel2("4", m_myfont, 40);
	livesLabel2.setColor(sf::Color(95,188,223));
	livesLabel.setPosition(1050 - (livesLabel.getGlobalBounds().width + livesLabel2.getGlobalBounds().width + 20) / 2 + livesLabel.getGlobalBounds().width, 550);
	livesLabel2.setPosition(1050 - (livesLabel.getGlobalBounds().width + livesLabel2.getGlobalBounds().width + 20) / 2, 550);

	//time
	sf::Clock tickClock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
	sf::Time introFrames = sf::Time::Zero;

	int tempcounter = 0;
	sf::Time timeClock;

	bool running = true;
	sf::Event e;
	while (running)
	{
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				m_levelstate = levelstate::exit;
				return;
			}

			if (e.type == sf::Event::KeyPressed && introFrames.asSeconds() > 6.f)
			{
				switch (e.key.code) {

				case sf::Keyboard::Escape:
				{
					m_levelstate = levelstate::exit;
					return;
				}
				break;

				case sf::Keyboard::R:
				{
					m_levelstate = levelstate::exit;
					return;
				}
				break;


				// Lose life Test
				case sf::Keyboard::K:
				{
					if (m_numLives > 0)
					{
						m_numLives -= 1;
						std::cout << "Number of lives: " << m_numLives << std::endl;
					}
					else
					{
						std::cout << "Number of lives: " << m_numLives << std::endl;
						m_levelstate = levelstate::lost;
						return;
					}
				}
				break;

				// Win Test
				case sf::Keyboard::W:
				{
					m_levelstate = levelstate::won;
					return;
				}
				break;

				// Lose Test
				case sf::Keyboard::L:
				{
					m_levelstate = levelstate::lost;
					return;
				}
				break;

				// Lvl up Test
				case sf::Keyboard::U:
				{
					lvl += 1;
					std::cout << "Lvl: " << lvl << std::endl;
					m_levelstate = levelstate::nextLevel;
					return;
				}
				break;

				// Shows tireur coord
				case sf::Keyboard::T:
				{
					std::cout << "Tireur : " << std::to_string(player.getPosition().x) << std::endl;
					return;
				}
				break;


				case sf::Keyboard::Space:
				{
					shooting = true;
				}
				break;

				// Test delete square 
				case sf::Keyboard::E:
				{
					nuage.deleteSquare(2, 9);
					std::cout << "Deleted Square" << std::endl;
				}
				break;

				// Returns shots position
				case sf::Keyboard::S:
				{
					for (int i = 0; i < player.getShots().size(); i++) {
						std::cout << "Shot " << i << " : " << player.getShots()[i].getPosition().y << std::endl;
					}
				}
				break;

				// Test to leave all but one square to destroy in lvl 1
				case sf::Keyboard::Y:
				{
					for (int i = 0; i < 20; i++) {
						for (int j = 0; j < 10; j++) {
							if (i <= 3 && j >= 5) 
								nuage.deleteSquare(i, j);
							if(i>=10 && i <= 17&& i!=14 && i!=15 && j >= 6)
								nuage.deleteSquare(i, j);
							if (i >= 6 && i <= 7 && j >= 7)
								nuage.deleteSquare(i, j);
						}

					}
				}
				break;

				default:
					break;
				}
			}

			sf::Vector2i mousepos = sf::Mouse::getPosition(window);
			if (mousepos.x >= retour.getPosition().x
				&& mousepos.y >= retour.getPosition().y
				&& mousepos.x <= retour.getPosition().x + retour.getGlobalBounds().width
				&& mousepos.y <= retour.getPosition().y + retour.getGlobalBounds().height
				&& introFrames.asSeconds() > 6.f)
			{

				if (e.type == sf::Event::MouseButtonPressed)
				{
					m_levelstate = levelstate::exit;
					return;
				}

			}



		}

		timeSinceLastUpdate += tickClock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{

			if (introFrames.asSeconds() < 6.f)
				timeClock = sf::Time::Zero;

			timeSinceLastUpdate -= TimePerFrame;
			introFrames += TimePerFrame;

			showIntro(window, introFrames);

			if (introFrames.asSeconds() > 6.f)
			{
				// Right edge (900-150)
				if (player.getPosition().x > 750) {
					moveToRight = false;
				}

				// Left edge
				if (player.getPosition().x < 0) {
					moveToRight = true;
				}
6
				// Makes the tireur move
				player.moveTireur(moveToRight);

				// Enables shooting
				if (shooting) {
					player.shoot(texShotPtr);
					shooting = false;
				}

				// Makes the shots move
				player.moveShots(nuage);

				// Update cloud

				shotCollision = player.shotCollision();

				if(shotCollision){
					for (int i = 0; i < player.getCollisionCoords().size(); i++) {
						if (nuage.checkSquare(player.getCollisionCoords()[i].x, player.getCollisionCoords()[i].y)) {
							std::cout << "Square [" << player.getCollisionCoords()[i].x << "," << player.getCollisionCoords()[i].y << "] deleted." << std::endl;
							nuage.deleteSquare(player.getCollisionCoords()[i].x, player.getCollisionCoords()[i].y);
						}
						else {
							if (m_numLives > 1) {
								m_numLives -= 1;
							}
							// if the player hasn't any lives left, it's game over
							else {
								m_numLives -= 1;
								m_levelstate = levelstate::lost;
								return;
							}
						}
						player.deleteCollision(i);
					}
					
				}



				// Update to see if the lvl is completed
				success = nuage.success();
			}
			srand(time(NULL));//seed a random number every frame


		}


		lvlLabel2.setString(std::to_string(lvl));
		livesLabel2.setString(std::to_string(m_numLives));

		// Level completed !
		if (success) {
			std::cout << "Success" << std::endl;
			Sleep(1000);
			if (lvl < 5) {
				m_levelstate = levelstate::nextLevel;
				return;
			}
			else {
				m_levelstate = levelstate::won;
				return;
			}
		}


		window.clear();

		window.draw(bg);

		window.draw(objectif_img);

		window.draw(nuage);

		// Intro

		if (introFrames.asSeconds() < 6.f) {
			window.draw(titleIntro);
			window.draw(msgIntro);
		}

		// TEXT


		window.draw(objectifLabel);

		window.draw(lvlLabel);
		window.draw(lvlLabel2);

		window.draw(livesLabel);
		window.draw(livesLabel2);

		window.draw(retour);
		window.draw(retour2);

		window.draw(player);

		for (int i = 0; i<player.getShots().size();i++) {
			window.draw(player.getShots()[i]);
		}

		window.display();
	}
	return;
}

void nuagerie::level::showIntro(sf::RenderWindow& window, sf::Time dt)
{
	if (lvl == 1)
	{
		
		if (dt.asSeconds() < 4.f)
		{
			titleIntro.setString("Niveau 1");
		}

		else if (dt.asSeconds() > 4.f && dt.asSeconds() < 6.f)
		{
			titleIntro.setString("");
			msgIntro.setString("Go!");
			msgIntro.setCharacterSize(150);
			msgIntro.setPosition(450 - msgIntro.getGlobalBounds().width / 2, 200);
		}
	}
	
	if (lvl == 2)
	{
		if (dt.asSeconds() < 2.f)
		{
			titleIntro.setString("Gagné !");
		}

		else if (dt.asSeconds() >= 2.f && dt.asSeconds() <= 4.f)
		{
			titleIntro.setString("Niveau 2");
		}

		else if (dt.asSeconds() > 4.f && dt.asSeconds() < 6.f)
		{
			titleIntro.setString("");
			msgIntro.setString("Go!");
			msgIntro.setCharacterSize(150);
			msgIntro.setPosition(450 - msgIntro.getGlobalBounds().width / 2, 200);
		}
	}
	
	if (lvl == 3)
	{
		if (dt.asSeconds() < 2.f)
		{
			titleIntro.setString("Gagné !");
		}

		else if (dt.asSeconds() >= 2.f && dt.asSeconds() <= 4.f)
		{
			titleIntro.setString("Niveau 3");
		}
		else if (dt.asSeconds() > 4.f && dt.asSeconds() < 6.f)
		{
			titleIntro.setString("");
			msgIntro.setString("Go!");
			msgIntro.setCharacterSize(150);
			msgIntro.setPosition(450 - msgIntro.getGlobalBounds().width / 2, 200);
		}
	}

	if (lvl == 4)
	{
		if (dt.asSeconds() < 2.f)
		{
			titleIntro.setString("Gagné !");
		}

		else if (dt.asSeconds() >= 2.f && dt.asSeconds() <= 4.f)
		{
			titleIntro.setString("Niveau 4");
		}

		else if (dt.asSeconds() > 4.f && dt.asSeconds() < 6.f)
		{
			titleIntro.setString("");
			msgIntro.setString("Go!");
			msgIntro.setCharacterSize(150);
			msgIntro.setPosition(450 - msgIntro.getGlobalBounds().width / 2, 200);
		}
	}

	if (lvl == 5)
	{
		if (dt.asSeconds() < 2.f)
		{
			titleIntro.setString("Gagné !");
		}

		else if (dt.asSeconds() >= 2.f && dt.asSeconds() <= 4.f)
		{
			titleIntro.setString("Niveau 5");
		}

		else if (dt.asSeconds() > 4.f && dt.asSeconds() < 6.f)
		{
			titleIntro.setString("");
			msgIntro.setString("Go!");
			msgIntro.setCharacterSize(150);
			msgIntro.setPosition(450 - msgIntro.getGlobalBounds().width / 2, 200);
		}
	}

	
}


//instantiate static members
sf::Uint32 nuagerie::level::m_levelstate = nuagerie::level::levelstate::uninitialized;
