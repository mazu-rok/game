#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

# include <ncurses.h>
# include <iostream>
# include <sstream>

# define MAX_ENEMY 500
# define NUM_BULLETS 100
# define NUM_STARS 500
# define HIT_AWARD 10
# define HIT_LOSS 10

class Game {
public:
	Game();
	Game(Game const &rhs);
	~Game();

	Game	&operator=(Game const &obj);

	void	fillFrame(int health);
	int		pause(void);
	void	color(void);
	void	checkCollisions(void);

	int		getHeight(void) const;
	int		getWidth(void) const;
	int		getScore(void) const;

	void	setHeight(int h);
	void	setWidth(int w);
	void	setScore(int score);

private:
	int _height;
	int _width;
	int _score;
};

#endif