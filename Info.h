#ifndef INFO_H
#define INFO_H

#include <iostream>
#include <SFML/Graphics.hpp>

namespace nuagerie
{
	class info
	{
	public:
		info();
		~info();
		void show(sf::RenderWindow& window);

		const sf::Uint32 infoState() { return m_infostate; };

		enum infostate
		{
			uninitialized,
			showing,
			done,
		};

	private:
		static sf::Uint32 m_infostate;
		sf::Sprite bg;
	};
}

#endif
