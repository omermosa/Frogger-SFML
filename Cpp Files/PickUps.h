// Frogger Game SFML
// The American University In Cairo (AUC)
// Copyrights of Omer Hassan, Yahya Saad, Muhammad Osama
//All Rights Reserved
// Fall 2018

#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
using namespace sf;
class PickUps
{
private:
	Sprite Pickup;
	Texture T1;
	Texture T2;
	Texture T3;
	float xposition;
	float yposition;
	int s;
public:
	PickUps();
	void setPickupposition(RenderWindow &window);
	
	void draw(RenderWindow &window);
	Sprite getBoundingRectangle(); 
	void disapper() { Pickup.setPosition(-1000, -1000); }
	int returns() { return s; }
	void setpos(int x, int y) { xposition = x; yposition = y; }
	bool PickupIntersect(Player &player, RenderWindow &window);
	~PickUps();
};

