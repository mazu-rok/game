#ifndef BULLET_CLASS_HPP
# define BULLET_CLASS_HPP

# include "GameObject.class.hpp"


class Bullet : public GameObject {
public:
	Bullet(void);
	Bullet(Bullet const &obj);
	virtual ~Bullet(void);

	Bullet &operator=(Bullet const &obj);

	// void move(WINDOW *space);
	void move(Game &game, WINDOW *space);
	void setAlive(int status);
	int isAlive(void) const;

private:
	int _alive;

};

#endif