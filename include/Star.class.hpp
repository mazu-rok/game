#ifndef STAR_CLASS_HPP
# define STAR_CLASS_HPP

# include "GameObject.class.hpp"
// # include <unistd.h>
// # include <ncurses.h>
// # include <iostream>

class Star : public GameObject {
public:
	Star(void);
	Star(Star const &obj);
	virtual ~Star(void);

	Star &operator=(Star const &obj);

	void move(WINDOW *space, int p);

	void setWidth(int width);
	void setHeight(int height);
	int getWidth(void) const;
	int getHeight(void) const;

private:
	int		_height;
	int		_width;
	// int		_x;
	// int		_y;
	// char	_c;
};

#endif