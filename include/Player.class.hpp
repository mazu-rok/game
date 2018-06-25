#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP

# include "GameObject.class.hpp"
# include "Bullet.class.hpp"
# include "Game.class.hpp"


class Player : public GameObject {
public:
	Player(void);
	Player(Player const &obj);
	virtual ~Player(void);

	Player &operator=(Player const &obj);

	void move(int key, Game &game);
	Bullet &getBullet(int i) const;

private:
	Bullet *_bullets;

};

#endif