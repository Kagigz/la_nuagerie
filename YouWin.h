#ifndef YOUWIN_H
#define YOUWIN_H

#include <iostream>
#include <SFML/Graphics.hpp>

namespace nuagerie
{
	class youwin
	{
	public:
		youwin();
		~youwin();

		void show(sf::RenderWindow& window);
		sf::Uint32 getState() { return m_winState; };

		enum winState
		{
			uninitialized,
			showing,
			done
		};

	private:
		sf::Uint32 m_winState;
		sf::Sprite bg;
	};
}

#endif
