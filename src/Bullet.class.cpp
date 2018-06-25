#include <ncurses.h>
#include <iostream>
#include "Bullet.class.hpp"


Bullet::Bullet(void)
	: GameObject(0, 0, 0, 1, '-'), _alive(1) {
}

Bullet::Bullet(Bullet const &obj) {
	*this = obj;
}

Bullet::~Bullet(void) {
	std::cout << "[.] Bullet destructor called" << std::endl;
}

Bullet	&Bullet::operator=(Bullet const &obj) {
	GameObject::operator=(obj);

	return *this;
}

void Bullet::move(Game &game, WINDOW *space) {
	mvwaddch(space, this->getYPos(), this->getXPos(), ' ');
	this->setXPos(this->getXPos() + this->getMoveDir());
	mvwaddch(space, this->getYPos(), this->getXPos(), this->getChar());

	if (this->getXPos() > game.getWidth())
		this->setAlive(0);
}

void Bullet::setAlive(int status) {
	this->_alive = status;
}

int Bullet::isAlive(void) const {
	return this->_alive;
}
