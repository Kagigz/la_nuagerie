#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <SFML/Graphics.hpp>

namespace nuagerie
{
	class menu
	{
	public:
		menu();
		~menu();
		void show(sf::RenderWindow& window);
		const sf::Uint32 menuState() const { return m_choice; };

		enum choice
		{
			s_uninitialized,
			s_undecided,
			s_play,
			s_info,
			s_rules,
			s_quit
		};

	private:
		static choice m_choice;
		sf::Sprite bg;

		float m_winsizeX;
		float m_winsizeY;
	};
}

#endif