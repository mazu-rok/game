#include "Game.class.hpp"


Game::Game(void) : _score(0) {
	initscr();
	clear();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);
	nodelay(stdscr, TRUE);

	getmaxyx(stdscr, _height, _width);
}

Game::~Game(void) {
	endwin();
}

Game	&Game::operator=(Game const &obj) {
	this->setHeight(obj.getHeight());
	this->setWidth(obj.getWidth());
	this->setScore(obj.getScore());

	return *this;
}

void	Game::fillFrame(int health)
{
	int h_len;
	std::ostringstream tmp;
	std::string out;
	WINDOW *up = newwin(1, _width, 0 , 0);	
	WINDOW *down = newwin(1, _width, _height - 1 , 0);	
	color();
	for (int i = 0; i < _width; i++) {
		mvwaddch(up, 0, i, '=');
		mvwaddch(down, 0, i, '=');
	}
	wattron(down, COLOR_PAIR(1));	
	tmp << health;
	out = "|Health " + tmp.str() + "|";
	h_len = out.length();
	mvwaddstr(down, 0, 5, out.c_str());
	tmp.str("");
	tmp << _score;
	out = "|Score " + tmp.str() + "|";
	mvwaddstr(down, 0, h_len + 10, out.c_str());
	wattron(down, COLOR_PAIR(5));		
	wrefresh(down);
	wrefresh(up);
	delwin(down);
	delwin(up);
}

int	Game::pause(void) {
	WINDOW *pa = newwin (1, 13, 0, _width/2 - 6);
	color();
	wattron(pa, COLOR_PAIR(2));
	mvwprintw(pa,0,0, "|>>>Pause<<<|");
	wrefresh(pa);
	int key;
	while ((key = getch()) != 'p' && key != 'P') {
		if (key == 'q' || key == 'Q')
			return 1;
	}
	wclear(pa);
	wrefresh(pa);
	delwin(pa);
	return 0;
}

void	Game::color(void)
{
	start_color();
	init_color(COLOR_WHITE, 850, 850, 850);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
}

int Game::getHeight(void) const {
	return this->_height;
}

int Game::getWidth(void) const {
	return this->_width;
}

int Game::getScore(void) const {
	return this->_score;
}

void	Game::setHeight(int h) {
	_height = h;
}

void	Game::setWidth(int w) {
	_width = w;
}

void	Game::setScore(int score) {
	_score = score;
}
