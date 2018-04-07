#ifndef CLOUD_H
#define CLOUD_H

#include <iostream>
#include <SFML/Graphics.hpp>

namespace nuagerie
{

	class cloud : public sf::Drawable, public sf::Transformable
	{
	public:
		cloud();
		cloud(int lvl);
		~cloud();

		bool checkSquare(int i, int j);
		void deleteSquare(int i,int j);
		bool success();
		int getNbSquaresX() { return nbSquaresX; };
		int getNbSquaresY() { return nbSquaresY; };
		float getMarginX() { return marginX; };
		float getMarginY() { return marginY; };
		float getSideSquare() { return sideSquare; };
		int cloudValue(int i, int j);

		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		
		int nbSquaresX = 20;
		int nbSquaresY = 10;
		int cloudSquares[20][10] = { 0 };
		int objectif[20][10] = { 0 };
		int lvl;
		float sideSquare = 40.f;
		float marginX = 50.f;
		float marginY = 20.f;
		int blankSquares = 200;
		int hitSquares = 0;
		

	};
}

#endif
