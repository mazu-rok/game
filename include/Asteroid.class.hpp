#ifndef ASTEROID_CLASS_HPP
# define ASTEROID_CLASS_HPP

# include "GameObject.class.hpp"


class Asteroid : public GameObject {
public:
	Asteroid(void);
	Asteroid(Game &game);
	Asteroid(Asteroid const &obj);
	virtual ~Asteroid(void);

	Asteroid &operator=(Asteroid const &obj);

	void move(WINDOW *space, Game &game);

private:

};

#endif