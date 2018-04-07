#include "Game.h"

nuagerie::Game::Game()
{

}

nuagerie::Game::~Game()
{

}

void nuagerie::Game::init()
{
	using nuagerie::Game;
	//if the game is not in an uninitialized state
	//when it is first run, bail
	if (!m_state == state::s_uninitialized)
		return;


	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 4;
	settings.majorVersion = 4;
	settings.minorVersion = 0;

	m_window.setFramerateLimit(60);//set the refresh limit to the current frame rate 60fps
	m_window.create(sf::VideoMode(1200, 800), "La Nuagerie", sf::Style::Default,settings);

	m_state = state::s_intro;

	while (!isQuitting())
	{
		run();
	}
	//std::cout<<"Quitting..."<<std::endl;
	m_window.close();
}

bool nuagerie::Game::isQuitting()
{
	using nuagerie::Game;
	return m_state == state::s_quit;
}

void nuagerie::Game::run()
{
	switch (m_state)
	{
	case state::s_intro:
	{
		intro();
		m_state = state::s_menu;
	}
	break;

	case state::s_menu:
	{
		menu();
	}
	break;

	case state::s_info:
	{
		info();
	}
	break;

	case state::s_rules:
	{
		rules();
	}
	break;

	case state::s_win:
	{
		win();
	}
	break;

	case state::s_lose:
	{
		lose();
	}
	break;

	case state::s_level:
	{
		level();
	}
	break;

	case state::s_level2:
	{
		level2();
	}
	break;

	case state::s_level3:
	{
		level3();
	}
	break;

	case state::s_level4:
	{
		level4();
	}
	break;

	case state::s_level5:
	{
		level5();
	}
	break;

	default:
		break;
	}
}

void nuagerie::Game::intro()
{
	using nuagerie::Game;
	m_window.setTitle("La Nuagerie");
	//std::cout<<"Intro State"<<std::endl;

	//create an intro object
	nuagerie::intro gameIntro;
	gameIntro.show(m_window);
}

void nuagerie::Game::menu()
{
	m_window.setTitle("Menu");
	//std::cout<<"Menu State"<<std::endl;

	//create a menu object
	nuagerie::menu gameMenu;
	gameMenu.show(m_window);
	if (gameMenu.menuState() == nuagerie::menu::s_play)
		m_state = state::s_level;
	else if (gameMenu.menuState() == nuagerie::menu::s_rules)
		m_state = state::s_rules;
	else if (gameMenu.menuState() == nuagerie::menu::s_info)
		m_state = state::s_info;
	else if (gameMenu.menuState() == nuagerie::menu::s_quit)
		m_state = state::s_quit;
}

void nuagerie::Game::info()
{
	m_window.setTitle("Info");
	//std::cout<<"Info State"<<std::endl;

	//create an info object
	nuagerie::info inf;
	inf.show(m_window);
	if (inf.infoState() == nuagerie::info::infostate::done)
		m_state = state::s_menu;
}

void nuagerie::Game::rules()
{
	m_window.setTitle("Règles");
	//std::cout<<"Rules State"<<std::endl;

	//create a rules object
	nuagerie::rules regles;
	regles.show(m_window);
	if (regles.ruleState() == nuagerie::rules::rulestate::s_done)
		m_state = state::s_menu;
}

void nuagerie::Game::win()
{
	m_window.setTitle("Gagné !");
	//std::cout<<"Win State"<<std::endl;

	//create a win object
	nuagerie::youwin winner;
	winner.show(m_window);
	if (winner.getState() == nuagerie::youwin::done)
		m_state = state::s_menu;
}

void nuagerie::Game::lose()
{
	m_window.setTitle("Game Over");
	//std::cout<<"Lose State"<<std::endl;

	//create a lose object
	nuagerie::gameOver loser;
	loser.show(m_window);
	if (loser.getState() == nuagerie::gameOver::done)
		m_state = state::s_menu;
}

void nuagerie::Game::level()
{
	m_window.setTitle("Niveau 1");
	//std::cout<<"Level State"<<std::endl;

	//create a level object
	nuagerie::level lvl(m_window, 1);
	lvl.show(m_window);
	if (lvl.levelState() == nuagerie::level::exit)
		m_state = state::s_menu;
	if (lvl.levelState() == nuagerie::level::nextLevel) {
		m_state = state::s_level2;
	}
	else if (lvl.levelState() == nuagerie::level::lost)
		m_state = state::s_lose;
	else if (lvl.levelState() == nuagerie::level::won)
		m_state = state::s_win;
}

void nuagerie::Game::level2()
{
	m_window.setTitle("Niveau 2");
	//std::cout<<"Level State"<<std::endl;

	//create a level object
	nuagerie::level lvl(m_window, 2);
	lvl.show(m_window);
	if (lvl.levelState() == nuagerie::level::exit)
		m_state = state::s_menu;
	if (lvl.levelState() == nuagerie::level::nextLevel) {
		m_state = state::s_level3;
	}
	else if (lvl.levelState() == nuagerie::level::lost)
		m_state = state::s_lose;
	else if (lvl.levelState() == nuagerie::level::won)
		m_state = state::s_win;
}

void nuagerie::Game::level3()
{
	m_window.setTitle("Niveau 3");
	//std::cout<<"Level State"<<std::endl;

	//create a level object
	nuagerie::level lvl(m_window, 3);
	lvl.show(m_window);
	if (lvl.levelState() == nuagerie::level::exit)
		m_state = state::s_menu;
	if (lvl.levelState() == nuagerie::level::nextLevel) {
		m_state = state::s_level4;
	}
	else if (lvl.levelState() == nuagerie::level::lost)
		m_state = state::s_lose;
	else if (lvl.levelState() == nuagerie::level::won)
		m_state = state::s_win;
}

void nuagerie::Game::level4()
{
	m_window.setTitle("Niveau 4");
	//std::cout<<"Level State"<<std::endl;

	//create a level object
	nuagerie::level lvl(m_window, 4);
	lvl.show(m_window);
	if (lvl.levelState() == nuagerie::level::exit)
		m_state = state::s_menu;
	if (lvl.levelState() == nuagerie::level::nextLevel) {
		m_state = state::s_level5;
	}
	else if (lvl.levelState() == nuagerie::level::lost)
		m_state = state::s_lose;
	else if (lvl.levelState() == nuagerie::level::won)
		m_state = state::s_win;
}

void nuagerie::Game::level5()
{
	m_window.setTitle("Niveau 5");
	//std::cout<<"Level State"<<std::endl;

	//create a level object
	nuagerie::level lvl(m_window, 5);
	lvl.show(m_window);
	if (lvl.levelState() == nuagerie::level::exit)
		m_state = state::s_menu;
	if (lvl.levelState() == nuagerie::level::nextLevel) {
		m_state = state::s_win;
	}
	else if (lvl.levelState() == nuagerie::level::lost)
		m_state = state::s_lose;
	else if (lvl.levelState() == nuagerie::level::won)
		m_state = state::s_win;
}

//initialize static member variables
sf::Uint32 nuagerie::Game::m_state = s_uninitialized;
sf::RenderWindow nuagerie::Game::m_window;
