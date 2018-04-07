#ifndef GAMEOVER_H
#define GAMEOVER_HP

#include <iostream>
#include <SFML/Graphics.hpp>

namespace nuagerie
{
	class gameOver
	{
	public:
		gameOver();
		~gameOver();

		void show(sf::RenderWindow& window);

		sf::Uint32 getState() { return m_gameOverState; };

		enum gameOverState
		{
			uninitialized,
			playing,
			done,
		};

	private:
		sf::Uint32 m_gameOverState;
		sf::Sprite bg;
	};
}

#endif
