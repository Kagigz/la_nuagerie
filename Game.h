#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Intro.h"
#include "Menu.h"
#include "Rules.h"
#include "Info.h"
#include "Level.h"
#include "YouWin.h"
#include "GameOver.h"

namespace nuagerie
{
	class Game
	{
	public:
		Game();
		~Game();

		static void init();

	private:
		static void run();

		static void intro();
		static void menu();
		static void rules();
		static void info();
		static void win();
		static void lose();
		static void level();
		static void level2();
		static void level3();
		static void level4();
		static void level5();

		static bool isQuitting();

		enum state
		{
			s_uninitialized,
			s_intro,
			s_menu,
			s_info,
			s_rules,
			s_win,
			s_lose,
			s_quit,
			s_level,
			s_level2,
			s_level3,
			s_level4,
			s_level5,

		};

	private:
		static sf::Uint32 m_state;
		static sf::RenderWindow m_window;
	};
}

#endif
