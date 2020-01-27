// Frogger Game SFML
// The American University In Cairo (AUC)
// Copyrights of Omer Hassan, Yahya Saad, Muhammad Osama
//All Rights Reserved
// Fall 2018

#include "PickUps.h"



PickUps::PickUps()
{
	T1.loadFromFile("PickupScore.png");
	//PickupScore.setTexture(T1);
	T2.loadFromFile("PickupLives.png");
	//PickupLives.setTexture(T2);
	T3.loadFromFile("PickupTime.png");
	//PickupScore.setTexture(T3);
	srand(time(NULL));
	s = rand() % 3;
	
	
}

void PickUps::setPickupposition(RenderWindow & window)
{
	
	switch (s) {
	case 0:
		Pickup.setTexture(T1);
		Pickup.setScale(0.07,0.07);
		break;
	case 1:
		Pickup.setTexture(T2);
		Pickup.setScale(0.07, 0.07);
		
		break;
	case 2:
		Pickup.setTexture(T3);
		Pickup.setScale(0.07, 0.07);
		break;
	}
	Pickup.setPosition(xposition, yposition);
}


void PickUps::draw(RenderWindow & window)
{
	window.draw(Pickup);
}

Sprite PickUps::getBoundingRectangle()
{
	return Pickup;
}

bool PickUps::PickupIntersect(Player & player, RenderWindow & window)
{
	if (player.returnbody().getGlobalBounds().intersects(getBoundingRectangle().getGlobalBounds()))
		return true;
	else
		return false;
}
PickUps::~PickUps()
{
}
