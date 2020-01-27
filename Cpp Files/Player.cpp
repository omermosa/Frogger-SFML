// Frogger Game SFML
// The American University In Cairo (AUC)
// Copyrights of Omer Hassan, Yahya Saad, Muhammad Osama
//All Rights Reserved
// Fall 2018

#include "Player.h"

Player::Player()
{
	frogtexture.loadFromFile("NF.png");
	frog.setTexture(frogtexture);
	frog.setScale(1, 1);
	frog.setPosition(350, 750);
	lives = 3;
	score = 0;
	//direction = up;
}


Player::~Player()
{
}

void Player::initializefrog(RenderWindow &window)
{
	if (!frogtexture.loadFromFile("NF.png"))
		cout << "Failed to load frog texture." << endl;
	frog.setTexture(frogtexture);
	frog.setPosition(350, 750);
}
int Player::getLives()
{
	return lives;
}
void Player::Draw(RenderWindow & window)
{
	window.draw(frog);
}

void Player::setPosition(float x, float y)
{
	frog.setPosition(x, y);
}

void Player::Move(float x, float y)
{
	frog.move(x, y);
}

void Player::move(Keyboard::Key &keypressed)
{
	if (keypressed == Keyboard::Up&&FloatRect(Vector2f(0.0, 0.0), Vector2f(750, 800)).contains(getXPosition(), getYPosition() - 50.0))
	{
		frogtexture.loadFromFile("JF.png");
		frog.setTexture(frogtexture);
		frog.move(0.0, -54.034);
		frogtexture.loadFromFile("NF.png");
		frog.setTexture(frogtexture);
		score += 10;
	}
	else if (keypressed == Keyboard::Down&&FloatRect(Vector2f(0.0, 0.0), Vector2f(750, 800)).contains(getXPosition(), getYPosition() + 50.0))
	{
		frogtexture.loadFromFile("JB.png");
		frog.setTexture(frogtexture);
		frog.move(0.0, 54.034);
		frogtexture.loadFromFile("NB.png");
		frog.setTexture(frogtexture);
	}
	else if (keypressed == Keyboard::Right&&getXPosition() < 700 && FloatRect(Vector2f(0.0, 0.0), Vector2f(750, 800)).contains(getXPosition() + 50.0, getYPosition()))
	{
		frogtexture.loadFromFile("JR.png");
		frog.setTexture(frogtexture);
		frog.move(54.034, 0.0);
		frogtexture.loadFromFile("R.png");
		frog.setTexture(frogtexture);
	}
	else if (keypressed == Keyboard::Left&&FloatRect(Vector2f(0.0, 0.0), Vector2f(750, 800)).contains(getXPosition() - 50.0, getYPosition()))
	{

		frogtexture.loadFromFile("JL.png");
		frog.setTexture(frogtexture);
		frog.move(-54.034, 0.0);
		frogtexture.loadFromFile("L.png");
		frog.setTexture(frogtexture);
	}
}

float Player::getXPosition()
{
	return frog.getPosition().x;
}

float Player::getYPosition()
{
	return frog.getPosition().y;
}

void Player::DecreaseLives()
{
	if (lives > 0)
		lives--;
}

void Player::setWinTexture(const int &x)
{
	if (x == 3)
	{
		if (!frogtexture.loadFromFile("cuteFrog.png"))
			cout << "Failed to load Cute Frog.";
		frog.setTexture(frogtexture);
	}
}

void Player::updateScore(const int &x)
{
	score += x;
}

Vector2f Player::getOrigin()
{
	float x = (getXPosition() + frogtexture.getSize().x) / 2;
	float y = (getYPosition() + frogtexture.getSize().y) / 2;
	cout << getXPosition() << endl;
	cout << getYPosition() << endl;
	cout << frogtexture.getSize().x << endl;
	cout << frogtexture.getSize().y << endl;
	cout << x << endl;
	cout << y << endl;
	Vector2f origin(x, y);
	return origin;
}

int Player::getscore()
{
	return score;
}

int Player::remaininglives()
{
	return lives;
}

Sprite Player::returnbody()
{
	return frog;
}

FloatRect Player::getboundingrectangle()
{
	return frog.getGlobalBounds();
}

void Player::setlives(int x)
{
	lives = x;
}

void Player::setScore(int x)
{
	score = x;
}