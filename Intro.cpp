#include "Intro.h"
#include "Game.h"

nuagerie::intro::intro()
{

}

nuagerie::intro::~intro()
{

}

void nuagerie::intro::show(sf::RenderWindow& window)
{
	using nuagerie::intro;

	if (!m_introstate == introstate::s_uninitialized)
		return;

	m_introstate = introstate::s_playing;

	sf::Clock clock;

	//create the intro image
	sf::Texture tex;
	if (!tex.loadFromFile("img/intro.jpg"))
	{
		std::cerr << "Intro texture not loaded" << std::endl;
	}

	sf::Sprite sprite;
	sprite.setTexture(tex);
	sprite.setPosition(0, 0);
	sprite.setTextureRect(sf::IntRect(0, 0, 1200, 800));

	while (m_introstate == introstate::s_playing
		&& clock.getElapsedTime().asSeconds() < 5.f)
	{
		window.clear();

		window.draw(sprite);

		window.display();
	}
	return;
}

//instantiate static members
sf::Uint32 nuagerie::intro::m_introstate = s_uninitialized;