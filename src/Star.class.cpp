#include "Star.class.hpp"
#include "Game.class.hpp"


Star::Star(void)
	: GameObject((std::rand() % 380), (std::rand() % 156), 0, -1, '.'), _height(155), _width(380) {
}

Star::Star(Star const &obj) {
	*this = obj;
}

Star::~Star(void) {};

Star	&Star::operator=(Star const &obj) {
	GameObject::operator=(obj);

	return *this;
}

void 	Star::move(WINDOW *space, int pause) {
	mvwaddch(space, this->getYPos(), this->getXPos(), ' ');

	if (pause % 3 == 0)
		this->setXPos(this->getXPos() + this->getMoveDir());

	wattron(space, COLOR_PAIR(3));

	if (this->getXPos() < 0)
		this->setXPos(this->getWidth());

	mvwaddch(space, this->getYPos(), this->getXPos(), this->getChar());
}

void Star::setHeight(int height) {
	this->_height = height;
}

void Star::setWidth(int width) {
	this->_width = width;
}

int Star::getHeight(void) const {
	return this->_height;
}

int Star::getWidth(void) const {
	return this->_width;
}
