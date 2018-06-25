#include "GameObject.class.hpp"


GameObject::GameObject(void) {}

GameObject::GameObject(int x, int y, int health, int moveDir, char ch) 
	: _xPos(x), _yPos(y), _moveDir(moveDir), _char(ch), _health(health) {
}

GameObject::GameObject(GameObject const &obj) {
	*this = obj;
}

GameObject::~GameObject(void) {}

GameObject	&GameObject::operator=(GameObject const &obj) {
	if (this != &obj) {
		this->setXPos(obj.getXPos());
		this->setYPos(obj.getYPos());
		this->setChar(obj.getChar());
		this->setMoveDir(obj.getMoveDir());
	}
	return *this;
}

bool GameObject::checkCollision(GameObject *obj) const {
	if (this->getXPos() == obj->getXPos() && this->getYPos() == obj->getYPos())
		return true;
	return false;
}

void GameObject::setXPos(int x) {
	this->_xPos = x;
}

void GameObject::setYPos(int y) {
	this->_yPos = y;
}

void GameObject::setChar(char c) {
	this->_char = c;
}

void GameObject::setMoveDir(int moveDir) {
	this->_moveDir = moveDir;
}

void GameObject::setHealth(int health) {
	this->_health = health;
}

int GameObject::getXPos(void) const {
	return this->_xPos;
}

int GameObject::getYPos(void) const {
	return this->_yPos;
}

int GameObject::getChar(void) const {
	return this->_char;
}

int GameObject::getMoveDir(void) const {
	return this->_moveDir;
}

int GameObject::getHealth(void) const {
	return this->_health;
}

