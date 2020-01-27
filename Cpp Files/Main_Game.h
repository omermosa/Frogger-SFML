// Frogger Game SFML
// The American University In Cairo (AUC)
// Copyrights of Omer Hassan, Yahya Saad, Muhammad Osama
//All Rights Reserved
// Fall 2018
#pragma once
#include"obstacles.h"
#include<SFML/Graphics.hpp>
#include "Menu.h"
#include "Player.h"
#include <iostream>
#include<SFML/Audio.hpp>
#include <string>
#include<fstream>
#include"PickUps.h"
using namespace sf;

#ifndef Main_Game_h
#define Main_Game_h
class Main_Game
{
	RenderWindow mywindow;
	Sprite background;
	Text scoretext, timetext, livestext, text;
	obstacles objects;
	Texture bg1, bg2, bg3, winFrogT;
	Font ft;
	int score = 0,lives = 3, n = -1, wins = 0, x = 2;
	//enum frgdestiny { alive, hit, drown, escaped };
	//frgdestiny frogdestiny;

	enum menu { none, play, HighScores, options, Exit };
	menu menuitems = none;
	float deltatime = 0.0f;
	Clock clock;
	Player frog;
	Keyboard::Key keypressed;
	Menu menu;
	Event evnt;
	Event event;
	Music audio;
	float time = 100;
	Texture dd;

	std::string fileName = "High Scores.txt";
	std::fstream output;
	Sprite winFrog[4];
	bool dead = true, flag = true;
	bool gameover = false;
	PickUps pickups;
	int xposition = rand() % 600 + 50;
	int yposition = rand() % 600 + 50;
	
public:
	Main_Game();
	void renderwindow();
	void Run_Game();
	void player();
	void displayScore();
	void dispdead();
	~Main_Game();
};
#endif