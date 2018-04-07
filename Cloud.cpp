#include "Cloud.h"

nuagerie::cloud::cloud()
{

}

nuagerie::cloud::cloud(int lvl)
{

	using nuagerie::cloud;


	for (int i = 0; i < nbSquaresX; i++) {
		for (int j = 0; j < nbSquaresY; j++) {
			cloudSquares[i][j] = 1;
		}
	}

	// loads the cloud goal depending on the level
	// tabs generated with Tiled
	switch (lvl) {

	//test
	case 0:
	{
		for (int i = 0; i < nbSquaresX; i++) {
			for (int j = 0; j < nbSquaresY; j++) {
				objectif[i][j] = 1;
			}
		}
		objectif[2][9] = 0;
		return;
	}
	break;

	case 1:
	{
		int tab[10][20] = {
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1 },
			{ 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1 },
			{ 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1 },
			{ 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1 }
		};
		for (int i = 0; i < nbSquaresX; i++) {
			for (int j = 0; j < nbSquaresY; j++) {
				objectif[i][j] = tab[j][i];
				// initializes the number of blank squares
				if (objectif[i][j] == 1) {
					blankSquares--;
				}
			}
		}
		return;
	}
	break;

	case 2:
	{
		int tab[10][20] = {
			{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
			{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
			{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
			{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
			{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
			{ 1,1,0,1,1,1,0,0,1,1,1,1,0,0,1,1,1,0,1,1 },
			{ 0,0,0,1,1,1,0,0,1,1,1,1,0,0,1,1,1,0,0,0 },
			{ 0,0,0,1,1,1,0,0,1,1,1,1,0,0,1,1,1,0,0,0 },
			{ 0,0,0,1,1,1,0,0,1,1,1,1,0,0,1,1,1,0,0,0 },
			{ 0,0,0,1,1,1,0,0,1,1,1,1,0,0,1,1,1,0,0,0 }

		};
		for (int i = 0; i < nbSquaresX; i++) {
			for (int j = 0; j < nbSquaresY; j++) {
				objectif[i][j] = tab[j][i];
				// initializes the number of blank squares
				if (objectif[i][j] == 1) {
					blankSquares--;
				}
			}
		}
		return;
	}
	break;

	case 3:
	{
		int tab[10][20] = {
			{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
			{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
			{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
			{ 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0 },
			{ 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0 },
			{ 0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0 },
			{ 0,0,0,0,0,1,1,0,1,1,1,1,0,1,1,0,0,0,0,0 },
			{ 0,0,0,0,0,1,1,0,1,1,1,1,0,1,1,0,0,0,0,0 },
			{ 0,0,0,0,0,1,1,0,0,1,1,0,0,1,1,0,0,0,0,0 },
			{ 0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0 }

		};
		for (int i = 0; i < nbSquaresX; i++) {
			for (int j = 0; j < nbSquaresY; j++) {
				objectif[i][j] = tab[j][i];
				// initializes the number of blank squares
				if (objectif[i][j] == 1) {
					blankSquares--;
				}
			}
		}
		return;
	}
	break;

	case 4:
	{
		int tab[10][20] = {
			{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
			{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
			{ 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
			{ 0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1 },
			{ 0,0,0,1,1,0,1,0,1,1,1,1,1,1,1,1,0,0,1,1 },
			{ 0,0,0,1,1,0,1,0,1,1,1,0,0,0,1,1,0,0,1,1 },
			{ 0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,0,0,1,1 },
			{ 0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,1,0,0,1,1 },
			{ 0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0 },
			{ 0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0 }

		};
		for (int i = 0; i < nbSquaresX; i++) {
			for (int j = 0; j < nbSquaresY; j++) {
				objectif[i][j] = tab[j][i];
				// initializes the number of blank squares
				if (objectif[i][j] == 1) {
					blankSquares--;
				}
			}
		}
		return;
	}
	break;

	case 5:
	{
		int tab[10][20] = {
			{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
			{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
			{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
			{ 1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1 },
			{ 1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0 },
			{ 1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,1,1,0,0 },
			{ 1,1,1,0,0,0,0,0,1,1,0,1,1,0,0,0,1,1,0,0 },
			{ 1,1,1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0 },
			{ 0,1,1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0 },
			{ 0,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0 }

		};
		for (int i = 0; i < nbSquaresX; i++) {
			for (int j = 0; j < nbSquaresY; j++) {
				objectif[i][j] = tab[j][i];
				// initializes the number of blank squares
				if (objectif[i][j] == 1) {
					blankSquares--;
				}
			}
		}
		return;
	}
	break;

	default:
		break;

	}

}

nuagerie::cloud::~cloud()
{
}

// returns true if square is supposed to be deleted
bool nuagerie::cloud::checkSquare(int i, int j)
{
	if (objectif[i][j] == 0)
		return true;
	return false;
}

// deletes square if possible
void nuagerie::cloud::deleteSquare(int i, int j)
{
	std::cout << std::endl;
	cloudSquares[i][j] = 0;
	hitSquares++;
	std::cout << "Cloud square [" << i << "," << j << "] deleted" << std::endl;
}

bool nuagerie::cloud::success()
{
	// we want the number of destroyed squares to be equal to the number of blank squares in a cloud
	if (this->blankSquares == this->hitSquares)
		return true;
	return false;
}




int nuagerie::cloud::cloudValue(int i, int j)
{
	if (cloudSquares[i][j] == 1)
		return 1;
	return 0;
}

void nuagerie::cloud::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	//draws white rectangles where squares of cloud are supposed to be
	for (int i = 0; i < nbSquaresX; i++) {
		for (int j = 0; j < nbSquaresY; j++) {
			if (cloudSquares[i][j] == 1) {
				sf::RectangleShape square(sf::Vector2f(sideSquare,sideSquare));
				square.setFillColor(sf::Color::White);
				square.setPosition(i * sideSquare + marginX, j * sideSquare + marginY);
				square.setOutlineThickness(2);
				square.setOutlineColor(sf::Color::Black);
				target.draw(square, states);
			}
		}
	}

}
