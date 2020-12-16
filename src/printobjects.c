#include "printobjects.h"
#include "gamepieces.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void printWellPromptEmpty(void); 
static void printWellPrompt(void); 
static void printCampPrompt(void); 
static void printShrinePrompt(void); 
static void printGCPrompt(void); 
static void printHousePrompt(void); 
static void printHHPrompt(void); 
static void printWell(void); 
static void printCamp(void); 
static void printShrine(void); 
static void printGC(void); 
static void printHouse(void); 
static void printHH(void); 

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void printHeroPlaces(void){
	wattron(game_win,COLOR_PAIR(3));
	mvwprintw(game_win,12,14,"|");
	mvwprintw(game_win,13,14,"|");
	wattroff(game_win,COLOR_PAIR(3));
	wattron(game_win,COLOR_PAIR(4));
	mvwprintw(game_win,11,14,"O");
	mvwprintw(game_win,12,12,"__");
	mvwprintw(game_win,12,15,"__");
	mvwprintw(game_win,14,13,"/ \\ ");
	mvwprintw(game_win,15,12,"/   \\");
	wattroff(game_win,COLOR_PAIR(4));
	wrefresh(game_win);
}

static void printHH(void) {
	mvwprintw(game_win,4,29,"  (");
	mvwprintw(game_win,5,29,"  )");
	mvwprintw(game_win,6,29," (");
	mvwprintw(game_win,7,29," )           _ ");
	mvwprintw(game_win,8,29,"           _(_)__");
	mvwprintw(game_win,9,29,"/\\        (_) (__)");
}

static void printHouse(void) {
	mvwprintw(game_win,1,33,"          _");
	mvwprintw(game_win,2,33,"   ______| |_");
	mvwprintw(game_win,3,33,"  /\\         \\");
	mvwprintw(game_win,4,33," /  \\         \\");
	mvwprintw(game_win,5,33,"/____\\_________\\");
	mvwprintw(game_win,6,33,"| _  |  []  [] |");
	mvwprintw(game_win,7,33,"||_|_|_________|");
}

static void printGC(void) {
	mvwprintw(game_win,0,27,"             --");
	mvwprintw(game_win,1,27,"                   ");
	mvwprintw(game_win,2,27,"--   - -|--        -");
	mvwprintw(game_win,3,27,"                  (_)");
	mvwprintw(game_win,4,27,"      -");
	mvwprintw(game_win,5,27,"        ---       --");
}

static void printShrine(void) {
	mvwprintw(game_win,2,20,"       __I__");
	mvwprintw(game_win,3,20,"     .' ... '.");
	mvwprintw(game_win,4,20,".__.' ........ '.__,");
	mvwprintw(game_win,5,20," ~----------------~");
	mvwprintw(game_win,6,20,"  |=||:|    |:||=|");
	mvwprintw(game_win,7,20,"  |=||:|    |:||=|");
	mvwprintw(game_win,8,20,"  |=||:|    |:||=|");
	mvwprintw(game_win,9,20,"  |=||:|    |:||=|");
	mvwprintw(game_win,10,20,"  |=||:|    |:||=|");
}

static void printCamp(void) {
	mvwprintw(game_win,7,36,"   /|\\");
	mvwprintw(game_win,8,36,"  / |\\\\");
	mvwprintw(game_win,9,36," /  |\\\\\\ ");
	mvwprintw(game_win,10,36,"   / \\\\\\");
	mvwprintw(game_win,11,36,"  /   \\\\\\");
	mvwprintw(game_win,12,36," / []  \\\\");
	mvwprintw(game_win,13,36,"/ [] [] \\");                              
}

static void printWell(void) {
	mvwprintw(game_win,14,30,"|======|");
	mvwprintw(game_win,15,30,"|======|");
}

void printPlaces(const int x) {
	switch(x){
		case 1: printHH();
			break;
		case 2:printHouse();
			break;
		case 3:printGC();
			break;
		case 4:printShrine();
			break;
		case 5:printCamp();
			break;		
		case 6: printWell();
			break;
		default: //do nothing
			break;
	}
	wrefresh(game_win);
}

static void printHHPrompt(void) {
	wprintw(prompt_win,"you find the smoking embers of a fire\nlooking around you see some items on the ground.\ndo you want to scrounge around? (y/n)");
}

static void printHousePrompt(void){
	wprintw(prompt_win,"you encounter a small cabin.\nwould you like to explore it? (y/n)");
}

static void printGCPrompt(void) {
	wprintw(prompt_win,"you find a small clearing\nlooking around it is clearly been used by a giant.\nyou see a broken sword and various bits of stuff scattered on the ground. do you wish to snoop around? (y/n) ");
}
static void printShrinePrompt(void) {
	wprintw(prompt_win,"you find a small shrine.\ndo you wish to enter and offer a blessing to the gods? (y/n) ");
}

static void printCampPrompt(void) {
	wprintw(prompt_win,"you find A small lean-to\ndo you wish to look around? (y/n)");
}
static void printWellPrompt(void) {
	wprintw(prompt_win,"you find a small well.\ndo you wish to drink from it and restore health?(y/n)");
}

static void printWellPromptEmpty(void) {
	wprintw(prompt_win,"you find a small well.\nunfortunately the well is empty.");

}

void printOptionsPlaces(const int x) {
	wclear(prompt_win);
	switch(x){
		case 1: printHHPrompt();
			break;
		case 2: printHousePrompt();
			break;
		case 3: printGCPrompt();
			break;
		case 4: printShrinePrompt();
			break;
		case 5: printCampPrompt();
			break;	
		case 6: printWellPrompt();
			break;
		case 7: printWellPromptEmpty();
			break;
		default: //do nothing
			break;
	}
	wrefresh(prompt_win);
}
