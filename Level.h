#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <random>
#include <Windows.h>
#include <SFML/Graphics.hpp>
#include "Tireur.h"
#include "Cloud.h"
#include "Tir.h"

namespace nuagerie
{
	
	class level
	{
	public:
		level(sf::RenderWindow& window,int niv);
		~level();

		void show(sf::RenderWindow& window);
		
		const sf::Uint32 levelState() { return m_levelstate; };

		enum levelstate
		{
			uninitialized,
			playing,
			nextLevel,
			lost,
			won,
			exit
		};

	private:

		void showIntro(sf::RenderWindow& window, sf::Time dt);
		bool introIsDone() { return m_introStatus; };
		void setIntroStatus(bool b) { m_introStatus = b; };

	private:

		nuagerie::tireur player;
		nuagerie::cloud nuage;

		sf::Uint32 m_numLives;
		static sf::Uint32 m_levelstate;
		bool m_introStatus;

		int lvl;
		bool success;

		float m_winsizeX;
		float m_winsizeY;
		float m_scaleX;
		float m_scaleY;

		sf::Font m_myfont;
		sf::Font titleFont;
		sf::Text titleIntro;
		sf::Text msgIntro;

		sf::Sprite bg;
		sf::Sprite objectif_img;
		sf::Texture texShots;
		sf::Texture* texShotPtr;
	};
}

#endif