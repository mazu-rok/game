#include "Asteroid.class.hpp"


Asteroid::Asteroid(void) {}

Asteroid::Asteroid(Game &game)
	: GameObject((game.getWidth() + std::rand() % game.getWidth()),
				(std::rand() % game.getHeight()), 0, -1, 'O') {
}

Asteroid::Asteroid(Asteroid const &obj) {
	*this = obj;
}

Asteroid::~Asteroid(void) {}

Asteroid	&Asteroid::operator=(Asteroid const &obj) {
	GameObject::operator=(obj);

	return *this;
}

void Asteroid::move(WINDOW *space, Game &game) {
	mvwaddch(space, this->getYPos(), this->getXPos(), ' ');

	this->setXPos(this->getXPos() + this->getMoveDir());
	if (this->getXPos() < 0)
		this->setXPos(game.getWidth() + std::rand() % game.getWidth());
		
	mvwaddch(space, this->getYPos(), this->getXPos(), this->getChar());
}
