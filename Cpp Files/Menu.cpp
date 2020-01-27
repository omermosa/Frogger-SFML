// Frogger Game SFML
// The American University In Cairo (AUC)
// Copyrights of Omer Hassan, Yahya Saad, Muhammad Osama
//All Rights Reserved
// Fall 2018


#include "Menu.h"



Menu::Menu()
{
	float wd = 750, ht = 800;
	
	font.loadFromFile("JOKERMAN.ttf");
	for (int i = 0; i < items; i++) {
		menu[i].setFont(font);
		menu[i].setCharacterSize(46);
		menu[i].setFillColor(Color::White);
		menu[i].setPosition(wd / 2-100,120+ ht / (2*items  )*(i + 1));
		
	}
	for (int i = 0; i < optionitems; i++)
	{
		OptionMenu[i].setFont(font);
		OptionMenu[i].setCharacterSize(40);
		OptionMenu[i].setFillColor(Color::White);
		OptionMenu[i].setPosition(wd / 2-100,120 + ht / (2 * items)*(i + 1));
	}
	menu[0].setString("Play");
	menu[1].setString("High Scores");
	menu[2].setString("Options");
	menu[3].setString("Exit");

	menu[selecteditem].setFillColor(Color::Green);

	OptionMenu[0].setString("Sound On");
	OptionMenu[1].setString("Sound Off");
	OptionMenu[2].setString("Theme 1");
	OptionMenu[3].setString("Theme 2");
	OptionMenu[4].setString("Theme 3");
	OptionMenu[selectedoption].setFillColor(Color::Green);
	men.loadFromFile("Menu.png");
	mnu.setTexture(men);
	//mnu.setScale(0.92f, 1.11f);
	mnu.setPosition(0.0f, 0.0f);
	
}

void Menu::drawmenu(RenderWindow &window)
{
	window.draw(mnu);
	for (int i = 0; i < items; i++)
		window.draw(menu[i]);
	
}
void Menu::moveup()
{
	if (selecteditem - 1 >= 0)
	{
		menu[selecteditem].setFillColor(Color::White);
		selecteditem--;
		menu[selecteditem].setFillColor(Color::Green);
	}

}
void Menu::drawoption(RenderWindow& window)
{
	window.draw(mnu);
	for (int i = 0; i < optionitems; i++)
		window.draw(OptionMenu[i]);
}
void Menu::moveodown() {
	if (selectedoption + 1 < optionitems)
	{
		OptionMenu[selectedoption].setFillColor(Color::White);
		selectedoption++;
		OptionMenu[selectedoption].setFillColor(Color::Green);
	}

}
void Menu::moveoup() {
	if (selectedoption - 1 >= 0)
	{
		OptionMenu[selectedoption].setFillColor(Color::White);
		selectedoption--;
		OptionMenu[selectedoption].setFillColor(Color::Green);
	}
}
void Menu::movedown() {

	if (selecteditem +1 < items)
	{
		menu[selecteditem].setFillColor(Color::White);
		selecteditem++;
		menu[selecteditem].setFillColor(Color::Green);
	}
}
int Menu::retunSI()
{
	return selecteditem;
}
void Menu::chighestscore(std::string file)
{
	int score;
	x.open(file);
	while (!x.eof())
	{
		x >> score;
		scores.push_back(score);
	}
	std::sort(scores.begin(), scores.end(), std::greater<int>());
	for (int i = 0; i < 5; i++)
	{
		Max[i].setFont(font);
		Max[i].setCharacterSize(40);
		Max[i].setFillColor(Color::White);
		Max[i].setPosition(750 / 2-200, 120 + 800 / (2 * items)*(i + 1));
		Max[i].setString("High Score# "+std::to_string(i+1)+" is: "+std::to_string(scores[i]));
	}

}
void Menu::displayscore(RenderWindow &window)
{

	window.draw(mnu);
	for (int i = 0; i < 5; i++)
		window.draw(Max[i]);
}
Menu::~Menu()
{
}
