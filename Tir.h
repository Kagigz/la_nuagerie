#ifndef TIR_H
#define TIR_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Cloud.h"

namespace nuagerie
{
	class tir : public sf::Drawable, public sf::Transformable
	{
	public:
		tir();
		tir(sf::Texture* texShotPtr);
		~tir();

		void setPosition(float x, float y);
		sf::Vector2f getPosition() { return m_spr_tir.getPosition(); };
		void moveTir(nuagerie::cloud nuage);
		sf::Vector2i touchCloud(nuagerie::cloud nuage);
		sf::Vector2i getCollisioncoord() { return collisionCoord; };
		bool collision(nuagerie::cloud nuage);
		bool getCollide() { return collide; };
		void setSpeed(float newSpeed);
		int getSpeed() { return speed; };

		void init(sf::RenderWindow& window);

		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:

		float speed;
		sf::Sprite m_spr_tir;
		sf::Texture m_tex_tir;
		sf::Vector2i collisionCoord;
		bool collide;

	};
}

#endif
