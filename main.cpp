#include <iostream>
#include <exception>
#include "Game.h"

int main()
{
	try
	{
		nuagerie::Game::init();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}