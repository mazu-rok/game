#ifndef GAMEOBJECT_CLASS_HPP
# define GAMEOBJECT_CLASS_HPP

# include "Game.class.hpp"


class GameObject {
public:
	GameObject(void);
	GameObject(int x, int y, int health, int moveDir, char ch);
	GameObject(GameObject const &obj);
	virtual ~GameObject(void);

	GameObject &operator=(GameObject const &obj);

	bool checkCollision(GameObject *obj) const;

	int getXPos(void) const;
	int getYPos(void) const;
	int getChar(void) const;
	int getMoveDir(void) const;
	int getHealth(void) const;
	void setXPos(int x);
	void setYPos(int y);
	void setChar(char c);
	void setMoveDir(int moveDir);
	void setHealth(int health);

private:
	int _xPos;
	int _yPos;
	int _moveDir;
	char _char;
	int _health;
};

#endif