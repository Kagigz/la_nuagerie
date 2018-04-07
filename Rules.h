#ifndef RULES_H
#define RULES_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

namespace nuagerie
{

	class rules
	{
	public:
		rules();
		~rules();
		void show(sf::RenderWindow& window);

		int ruleState()
		{
			return m_rulestate;
		};

		enum rulestate
		{
			s_uninitialized,
			s_done
		};

	private:
		static sf::Uint32 m_rulestate;
		sf::Sprite bg;
	};

}

#endif
