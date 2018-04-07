#ifndef INTRO_H
#define INTRO_H

#include <SFML/Graphics.hpp>
#include <iostream>

namespace nuagerie
{
	class intro
	{
	public:
		intro();
		~intro();
		void show(sf::RenderWindow& window);
		const sf::Uint32 introState() const { return m_introstate; };

		enum introstate
		{
			s_uninitialized,
			s_playing
		};

	private:
		static sf::Uint32 m_introstate;
	};
}

#endif