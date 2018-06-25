#include <ncurses.h>
#include <iostream>
#include "Player.class.hpp"


Player::Player(void)
	: GameObject(10, 10, 100, 1, '>') {
	this->_bullets = new Bullet[NUM_BULLETS];

	for (int i = 0; i < NUM_BULLETS; i++) {
		this->_bullets[i].setAlive(0);
	}
}

Player::Player(Player const &obj) {
	*this = obj;
}

Player::~Player(void) {
	delete[] this->_bullets;
}

Player	&Player::operator=(Player const &obj) {
	GameObject::operator=(obj);

	return *this;
}

Bullet &Player::getBullet(int i) const {
	return this->_bullets[i];
}

void Player::move(int key, Game &game) {
	if(key == KEY_LEFT)
		this->setXPos(this->getXPos() - 1);

	else if(key == KEY_RIGHT)
		this->setXPos(this->getXPos() + 1);

	else if(key == KEY_UP)
		this->setYPos(this->getYPos() - 1);

	else if(key == KEY_DOWN)
		this->setYPos(this->getYPos() + 1);

	if (this->getXPos() < 0)
		this->setXPos(0);
	if (this->getXPos() > game.getWidth() - 1)
		this->setXPos(game.getWidth() - 1);
	if (this->getYPos() < 0)
		this->setYPos(game.getHeight() - 3);
	if (this->getYPos() > game.getHeight() - 3)
		this->setYPos(0);
}
