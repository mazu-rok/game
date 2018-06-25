#include <ncurses.h>
#include <unistd.h>

#include "Player.class.hpp"
#include "Asteroid.class.hpp"
#include "Game.class.hpp"
#include "Star.class.hpp"



void game_loop(Game &game, int key) {
	if(key == 'q' || key =='Q') return;

	std::srand(clock());	

	Star	stars[NUM_STARS];

	Asteroid *en[MAX_ENEMY];
	for (int i = 0; i < MAX_ENEMY; i++) {
		en[i] = new Asteroid(game);
	}

	int k = 0;
	int p = 0;
	int h;
	int w;

	Player player;

	WINDOW *ship = newwin(200, 370, 1 , 0);
	
	while((player.getHealth() > 0)) {
		WINDOW *space = newwin(game.getHeight() - 2, game.getWidth(), 1 , 0);

		getmaxyx(stdscr, h, w);
		game.setHeight(h);
		game.setWidth(w);
		key = getch();
		if (k++ % (20)  == 0)
		{
			game.color();
			wattron(space, COLOR_PAIR(3));
			for (int i = 0; i < NUM_STARS; i++) {
				stars[i].move(space, p++);
			}
			wattron(space, COLOR_PAIR(1));			
			for (int i = 0; i < MAX_ENEMY; i++) {
				en[i]->move(space, game);
			}
			wattron(space, COLOR_PAIR(5));
			wrefresh(space);
		}
		mvwaddch(ship, player.getYPos(), player.getXPos(), ' ');

		if (key == 'q' || key == 'Q') {
			break;
		}
		else if(key == 'p') {
			if (game.pause() == 1) {
				break;
			}
		}
		else if (key == ' ') {
			for (int i = 0; i < NUM_BULLETS; i++)
			{
				if (player.getBullet(i).isAlive() == 0) {
					player.getBullet(i).setAlive(1);
					player.getBullet(i).setXPos(player.getXPos());
					player.getBullet(i).setYPos(player.getYPos());
					break;
				}
			}
		}
		
		wattron(ship, COLOR_PAIR(2));
		for (int i = 0; i < NUM_BULLETS; i++)
		{
			if (player.getBullet(i).isAlive() == 1) {
				player.getBullet(i).move(game, ship);
			}
		}
		wattron(ship, COLOR_PAIR(5));
		// collisions with Bullets
		for (int i = 0; i < NUM_BULLETS; i++) {
			for (int j = 0; j < MAX_ENEMY; j++) {
				if (player.getBullet(i).checkCollision(en[j])) {
					player.getBullet(i).setAlive(0);
					game.setScore(game.getScore() + HIT_AWARD);
					en[j]->setYPos(std::rand() % game.getHeight());
					en[j]->setXPos(game.getWidth() + std::rand() % game.getHeight());
				}
			}
		}

		player.move(key, game);

		// collisions with Asteroids
		for (int i = 0; i < MAX_ENEMY; i++) {
			if (player.checkCollision(en[i])) {
				player.setHealth(player.getHealth() - HIT_LOSS);
				en[i]->setYPos(std::rand() % game.getHeight());
				en[i]->setXPos(game.getWidth() + std::rand() % game.getHeight());
			}
		}

		mvwaddch(ship, player.getYPos(), player.getXPos(), player.getChar());

		game.fillFrame(player.getHealth());

		wrefresh(ship);
		usleep(1900);
		delwin(space);
	}

	for (int i = 0; i < 40; i++) {
		delete en[i];
	}
}

int main(void) {
	Game game;

	int key = getch();
	clear();
	game_loop(game, key);
	endwin();

	return 0;
}