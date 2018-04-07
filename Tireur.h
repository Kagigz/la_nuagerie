#ifndef TIREUR_H
#define TIREUR_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tir.h"

namespace nuagerie
{

	class tireur : public sf::Drawable, public sf::Transformable
	{
	public:
		tireur();
		~tireur();

		void setPosition(float x, float y);
		sf::Vector2f getPosition() { return m_spr.getPosition(); };
		sf::FloatRect getBounds() { return m_spr.getGlobalBounds(); };
		void moveTireur(bool right);
		void moveShots(nuagerie::cloud nuage);
		bool shotCollision() { return shotCollide; };
		void shoot(sf::Texture* texShotPtr);

		void setSpeed(float newSpeed);
		int getSpeed() { return speed; };

		std::vector<nuagerie::tir> getShots() { return shots; };
		std::vector<sf::Vector2i> getCollisionCoords() { return coordCollision; };
		void deleteCollision(int i);

		void init(sf::RenderWindow& window);

		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:

		float speed;
		sf::Sprite m_spr;
		sf::Texture m_tex;
		std::vector<nuagerie::tir> shots;
		bool shotCollide;
		std::vector<sf::Vector2i> coordCollision;
	};
}

#endif
