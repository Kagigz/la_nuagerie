#include "Tir.h"

nuagerie::tir::tir()
{
	using nuagerie::tir;

	// Load texture for shots
	if (!m_tex_tir.loadFromFile("img/tir.png"))
	{
		std::cerr << "tir.png not loaded" << std::endl;
	}

	//pass the texture to the sprite
	m_spr_tir.setTexture(m_tex_tir);

	speed = 4.f;
	collide = false;
	collisionCoord = sf::Vector2i(-1, -1);

}

nuagerie::tir::tir(sf::Texture* texShotPtr)
{
	using nuagerie::tir;

	//pass the texture to the sprite
	m_spr_tir.setTexture(*texShotPtr);

	speed = 4.f;
	collide = false;
	collisionCoord = sf::Vector2i(-1,-1);

}

nuagerie::tir::~tir()
{
}

void nuagerie::tir::setPosition(float x, float y)
{
	using nuagerie::tir;
	m_spr_tir.setPosition(x, y);

}


// makes the shot move up
void nuagerie::tir::moveTir(nuagerie::cloud nuage)
{
	
	sf::Vector2f v = sf::Vector2f(0.f, -speed * 80);
	sf::Time dt = sf::seconds(1.f / 60.f);
	m_spr_tir.move(dt.asSeconds()*v);

	collide = collision(nuage);

}

// returns coord where shot touches the cloud
sf::Vector2i nuagerie::tir::touchCloud(nuagerie::cloud nuage)
{
	float s = nuage.getSideSquare();
	float posX = getPosition().x;
	float posY = getPosition().y;

	
	for (int i = 0; i < nuage.getNbSquaresX(); i++) {
		for (int j = 0; j < nuage.getNbSquaresY(); j++) {
			if (nuage.cloudValue(i, j) == 1) {
				if (std::abs(posX - (i*s + nuage.getMarginX() + s / 2)) < s/2 && std::abs(posY - (j*s + nuage.getMarginY() + s / 2)) < s/2) {
					std::cout << "Collision !" << std::endl;
					return sf::Vector2i(i, j);
				}
			}
		}

	}
	
	return sf::Vector2i(-1, -1);
}

bool nuagerie::tir::collision(nuagerie::cloud nuage)
{
	sf::Vector2i cloudCollision = touchCloud(nuage);
	if (cloudCollision != sf::Vector2i(-1, -1)) {
		collisionCoord = sf::Vector2i(cloudCollision.x, cloudCollision.y);
		std::cout << "Collision coord : " << collisionCoord.x << "," << collisionCoord.y << std::endl;
		return true;
	}
	return false;
}


void nuagerie::tir::setSpeed(float newSpeed)
{
	speed = newSpeed;
}

void nuagerie::tir::init(sf::RenderWindow & window)
{
	speed = speed;
	m_spr_tir.setPosition(0, 800);

}


void nuagerie::tir::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_spr_tir, states);

}
