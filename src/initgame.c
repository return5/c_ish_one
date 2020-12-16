#include <stdlib.h>
#include "makemap.h"
#include "initgame.h"
#include "gamepieces.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void initColors(void);
static void makePlayer(void);
static void makePromptWin(void);
static void makeGameWin(void);
static int getRandInt(const int limit);
static void initWindow(void);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
WINDOW *game_border; 		  	   //window for game border	
WINDOW *game_win;			  	  //window for game map
WINDOW *prompt_win;	   	     	 //window for text prompts
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initGame(void) {
	initWindow();
	initColors();
	makeGameWin();
	makePromptWin();
	initMap();      //makemap.c
	makePlayer();
	setUpStart();	
}

static int getRandInt(const int limit) {
	const int divisor = RAND_MAX/(limit + 1);
	int value;
	do {
		value = rand() / divisor;
	} while(value > limit);

	return value;
}
static void makeGameWin(void){
	game_win = newwin(HEIGHT,WIDTH,3,3);
	game_border = newwin(HEIGHT+2,WIDTH+2,2,2);
	wborder(game_border,'|','|','-', '-', '+', '+', '+', '+');	
	refresh();
	wrefresh(game_win);
	wrefresh(game_border);

}

static void makePromptWin(void) {
	prompt_win = newwin(7,WIDTH+12,HEIGHT+4,2);
	wrefresh(prompt_win);
}

static void initWindow(void) {
	initscr();
	noecho();	      //dont display key strokes
	cbreak();	     //disable line buffering
	curs_set(0);	//dont display cursor
	keypad(stdscr, TRUE); //enable keypad
	half_y = COLS / 2;
	half_x = LINES / 2;
}

static void initColors(void) {
	start_color();
	init_color(COLOR_YELLOW,700,700,98);
	init_pair(1,COLOR_BLACK,COLOR_BLACK);   
	init_pair(2,COLOR_WHITE,COLOR_BLACK);  
	init_pair(3,COLOR_GREEN,COLOR_BLACK);  
	init_pair(4,COLOR_YELLOW,COLOR_BLACK);  
	init_pair(5,COLOR_CYAN,COLOR_BLACK);  
	init_pair(6,COLOR_RED,COLOR_BLACK);	
	init_pair(7,COLOR_MAGENTA,COLOR_BLACK);
	init_pair(8,COLOR_BLUE,COLOR_BLACK);
}

static void makePlayer(void) {
	player = malloc(sizeof(tile));
	Character *character = malloc(sizeof(Character));
	player->character = character;
	PLAYER->health = getRandInt(15) + 20;
	PLAYER->health_max = PLAYER->health;
	PLAYER->defense = getRandInt(2) + 2;
	PLAYER->attack = getRandInt(2) + 6;
	PLAYER->crit_chance = 7;
	player->tile_set = '@';
	PLAYER->chance_to_dodge = 6;
	PLAYER->defense_value = PLAYER->defense;
	PLAYER->defense_up = 0;
	PLAYER->type = 0;
	PLAYER->name = "you";
	PLAYER->food = getRandInt(2) + 1;
	PLAYER->special = getRandInt(2);
	PLAYER->special_count = 0;
	PLAYER->turn = 0;
	PLAYER->regular_attack = malloc(150);
	PLAYER->regular_miss = malloc(150);
	PLAYER->counter_miss = malloc(150);
	PLAYER->critical_hit = malloc(150);
	PLAYER->special_attack = malloc(150);
	PLAYER->special_attack_miss = malloc(150);
	PLAYER->raise_defense = "you raise your defense by 2.";

	switch (PLAYER->special) {
		case 0:PLAYER->special_name = "throw opponent";
			break;
		case 1:PLAYER->special_name = "cast defense down spell";
			break;
		case 2:PLAYER->special_name = "do a power attack";
			break;
		default: //do nothing
			break;
	}
}

void setUpStart(void) {
	player->x = 0;
	player->y = 0;
	map[0][0]->type = 0;
 	previous = map[0][0];
	map[0][0] = player;
}
