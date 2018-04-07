#include "Tireur.h"

nuagerie::tireur::tireur()
{
	using nuagerie::tireur;


	// Load texture
	if (!m_tex.loadFromFile("img/tireur.png"))
	{
		std::cerr << "tireur.png not loaded" << std::endl;
	}

	//pass the texture to the sprite
	m_spr.setTexture(m_tex);

	speed = 1.f;
	shotCollide = false;

}

nuagerie::tireur::~tireur()
{
}

void nuagerie::tireur::setPosition(float x, float y)
{
	using nuagerie::tireur;
	m_spr.setPosition(x, y);

}


// if right, tireur goes right, if not right, tireur goes left
void nuagerie::tireur::moveTireur(bool right)
{

	sf::Time dt = sf::seconds(1.f / 60.f);
	if (right) {
		sf::Vector2f vR = sf::Vector2f(speed * 50, 0.f);
		m_spr.move(dt.asSeconds()*vR);
	}
	else {
		sf::Vector2f vL = sf::Vector2f(-speed * 50, 0.f);
		m_spr.move(dt.asSeconds()*vL);
	}
	
}

// Moves shots and deletes them when collision or when they reach the top
void nuagerie::tireur::moveShots(nuagerie::cloud nuage)
{
	
	for (int i = 0; i < shots.size(); i++) {
		shots[i].moveTir(nuage);
		if (shots[i].getCollide() || shots[i].getPosition().y <= 0) {
			shots.erase(shots.begin() + i);
			if (shots[i].getCollide()) {
				shotCollide = true;
				coordCollision.push_back(shots[i].getCollisioncoord());
			}
		}
	}

}


void nuagerie::tireur::shoot(sf::Texture* texShotPtr)
{

	int index = shots.size();
	//max 5 shots at the same time
	if (shots.size() < 5) {
		nuagerie::tir shot = nuagerie::tir(texShotPtr);
		shot.setPosition(getPosition().x + getBounds().width / 2, getPosition().y);
		shots.push_back(shot);
	}

}


void nuagerie::tireur::setSpeed(float newSpeed)
{
	speed = newSpeed;
}

void nuagerie::tireur::deleteCollision(int i)
{
	coordCollision.erase(coordCollision.begin() + i);
}

void nuagerie::tireur::init(sf::RenderWindow & window)
{
	speed = speed;
	m_spr.setPosition(20, 700);

}


void nuagerie::tireur::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_spr, states);

}
