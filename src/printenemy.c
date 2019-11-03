#include "printenemy.h"
#include "gamepieces.h"

/*============================================================ prototypes ============================================================*/
void printSwordsman(void);
void printSkeleton(void);
void printSlinger(void);
void printTheif(void);
void printArcher(void);
void printSpearman(void);
void printDog(void);
void printMage(void);
void printScrugg(void);
void printHalflings(void);
void printHalflingL(void);
void printHalflingR(void);
void printMonsterHead(const int x);
void printMonsterBody(void);
void printMonsterSeveredHead(const int y, const int x);
void printMonster(void);
void printMonsterL(void);
void printMonsterR(void);
void printDelmerBody(const int y, const int x);
void printDelmerR(void);
void printDelmerL(void);
void printDelmer(void);
void printBoss(void);
void printCleanEnemies(void);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void printHero(void) {
	wattron(game_win,WHITE);
	mvwprintw(game_win,11,10,"\\"); //sword
	mvwprintw(game_win,12,11,"\\"); //sword
	wattroff(game_win,WHITE);
	wattron(game_win,GREEN);
	mvwprintw(game_win,12,14,"|"); //upper torso
	mvwprintw(game_win,13,14,"|"); //lower torso
	wattroff(game_win,GREEN);
	wattron(game_win,YELLOW);
	mvwprintw(game_win,11,14,"O"); //head
	mvwprintw(game_win,12,12,"__"); //arms
	mvwprintw(game_win,12,15,"__"); //arms
	mvwprintw(game_win,14,13,"/ \\"); //legs
	mvwprintw(game_win,15,12,"/   \\"); //lowr legs
	wattroff(game_win,YELLOW);
	wattron(game_win,RED);
	mvwprintw(game_win,12,17,"|"); //sheild
	mvwprintw(game_win,13,17,"|"); //sheild
	wattroff(game_win,RED);
}

void printSwordsman(void) {
	wattron(game_win,GREEN);
	mvwprintw(game_win,11,27,"O"); //head
	mvwprintw(game_win,12,25,"__"); //left arm
	mvwprintw(game_win,12,28,"__"); //right arm
	mvwprintw(game_win,14,26,"/ \\ "); //legs
	mvwprintw(game_win,15,25,"/   \\"); //lower legs
	wattroff(game_win,GREEN);
	wattron(game_win,BLUE);
	mvwprintw(game_win,12,24,"|"); //top of shield
	mvwprintw(game_win,13,24,"|"); //bottom of shield
	wattroff(game_win,BLUE);
	wattron(game_win,RED);
	mvwprintw(game_win,12,27,"|"); //top of torso
	mvwprintw(game_win,13,27,"|"); ///bottom of torso
	wattroff(game_win,RED);
	wattron(game_win,WHITE);
	mvwprintw(game_win,11,31,"/"); //top of sword
	mvwprintw(game_win,12,30,"/"); //bottom of sword
	wattroff(game_win,WHITE);
}

void printSkeleton(void) {
	wattron(game_win,CYAN);
	mvwprintw(game_win,10,26,"|"); //sword handle
	mvwprintw(game_win,11,26,"|"); //sword handle
	wattroff(game_win,CYAN);
	wattron(game_win,BLUE);
	mvwprintw(game_win,10,25,"-"); //handgaurd
	mvwprintw(game_win,10,27,"-"); //handgaurd
	wattroff(game_win,BLUE);
	wattron(game_win,WHITE);
	mvwprintw(game_win,7,26,"|"); //sword blade
	mvwprintw(game_win,8,26,"|"); //sword blade
	mvwprintw(game_win,9,26,"|"); //sword blade
	mvwprintw(game_win,10,29,"0"); //head
	mvwprintw(game_win,11,27,"--|"); //upper torso and arms
	mvwprintw(game_win,12,29,"|"); //lower torso
	mvwprintw(game_win,13,28,"/ \\"); //leg
	mvwprintw(game_win,14,27,"/   \\"); //lower leg
	wattroff(game_win,WHITE);
}

void printSlinger(void) {
	wattron(game_win,CYAN);
	mvwprintw(game_win,11,27,"O"); //head
	mvwprintw(game_win,12,27,"|"); //upper torso
	mvwprintw(game_win,13,27,"|"); //lower torso
	mvwprintw(game_win,12,25,"__"); //let arm
	mvwprintw(game_win,12,28,"__"); //right arm
	wattroff(game_win,CYAN);
	wattron(game_win,BLUE);
	mvwprintw(game_win,14,26,"/ \\"); //legs
	mvwprintw(game_win,15,25,"/   \\"); //lower legs
	wattroff(game_win,BLUE);
	wattron(game_win,GREEN);
	mvwprintw(game_win,13,30,"\\"); //sling
	wattroff(game_win,GREEN);
	wattron(game_win,YELLOW);
	mvwprintw(game_win,14,31,"O"); //rock
	wattroff(game_win,YELLOW);
}

void printTheif(void) {
	wattron(game_win,YELLOW);
	mvwprintw(game_win,11,27,"O"); //head
	wattroff(game_win,YELLOW);
	wattron(game_win,WHITE);
	mvwprintw(game_win,12,24,"\\"); //daggers
	mvwprintw(game_win,13,30,"\\"); //daggers
	wattroff(game_win,WHITE);
	wattron(game_win,GREEN);
	mvwprintw(game_win,12,25,"__|__"); //upperbody
	mvwprintw(game_win,13,27,"|"); //lowerbody
	mvwprintw(game_win,14,25," / \\"); //legs
	mvwprintw(game_win,15,25,"/   \\"); //lower legs
	wattroff(game_win,GREEN);
}

void printArcher(void) {
	wattron(game_win,BLUE);
	mvwprintw(game_win,11,29,")"); //bow
	mvwprintw(game_win,12,28,"/"); //bow
	mvwprintw(game_win,13,27,"/"); //bow
	mvwprintw(game_win,14,27,"\\"); //bow
	mvwprintw(game_win,15,28,"\\"); //bow
	mvwprintw(game_win,16,29,")"); //bow
	wattroff(game_win,BLUE);
	wattron(game_win,WHITE);
	mvwprintw(game_win,12,29,"|"); //bowstring
	mvwprintw(game_win,13,29,"|"); //bowstring
	mvwprintw(game_win,14,29,"|"); //bowstring
	mvwprintw(game_win,15,29,"|"); //bowstring
	mvwprintw(game_win,13,24,"_"); //arrowhead
	wattroff(game_win,WHITE);
	wattron(game_win,YELLOW);
	mvwprintw(game_win,13,28,"_"); //arow shaft
	mvwprintw(game_win,13,25,"__"); //arow shaft
	wattroff(game_win,YELLOW);
	wattron(game_win,YELLOW);
	mvwprintw(game_win,12,32,"O"); //head
	wattroff(game_win,YELLOW);
	wattron(game_win,CYAN);
	mvwprintw(game_win,13,30,"__"); //arms
	wattroff(game_win,CYAN);
	wattron(game_win,MAGENTA);
	mvwprintw(game_win,13,32,"|"); //torso
	mvwprintw(game_win,14,32,"|"); //torso
	wattroff(game_win,MAGENTA);
	wattron(game_win,GREEN);
	mvwprintw(game_win,15,31,"/ \\"); //legs
	mvwprintw(game_win,16,30,"/   \\"); //lower legs
	wattroff(game_win,GREEN);
}
	
void printSpearman(void) {
	wattron(game_win,YELLOW);
	mvwprintw(game_win,13,26,"____ _ _ __"); //spear
	wattroff(game_win,YELLOW);	
	wattron(game_win,WHITE);
	mvwprintw(game_win,11,32,"O"); //head
	mvwprintw(game_win,12,30,"__|__"); //upper torso and arms
	mvwprintw(game_win,13,25,"_"); //spearpoint
	mvwprintw(game_win,13,32,"|"); //lower torso
	mvwprintw(game_win,13,30,"\\"); //hands
	mvwprintw(game_win,13,34,"/"); //other hands
	mvwprintw(game_win,14,31,"/ \\"); //legs
	mvwprintw(game_win,15,30,"/   \\"); //lower legs
	wattroff(game_win,WHITE);
}

 void printDog(void) {
	wattron(game_win,WHITE);
	mvwprintw(game_win,12,26,"_"); //top of head
	mvwprintw(game_win,13,25,"<"); //snout
	wattroff(game_win,WHITE);
	wattron(game_win,RED);
	mvwprintw(game_win,13,26,"="); //eyes?
	wattroff(game_win,RED);	
	wattron(game_win,YELLOW);
	mvwprintw(game_win,12,27,"/"); //ears
	mvwprintw(game_win,13,27,"\\_______/"); //upperbody
	mvwprintw(game_win,14,28,"/\\    /\\"); //upper legs
	mvwprintw(game_win,15,27,"/  \\  /  \\"); //lower legs
	wattroff(game_win,YELLOW);	
}

void printMage(void) { 
	wattron(game_win,BLUE);
	mvwprintw(game_win,11,27,"O"); //head
	mvwprintw(game_win,12,25,"__|__"); //upper torso and arms
	mvwprintw(game_win,13,27,"|"); //lower torso
	mvwprintw(game_win,14,26,"/ \\"); //upper legs
	mvwprintw(game_win,15,25,"/   \\"); //lower legs
	wattroff(game_win,BLUE);
	wattron(game_win,YELLOW);
	wattroff(game_win,YELLOW);
	wattron(game_win,WHITE);
	mvwprintw(game_win,12,30,"|"); //staff handle
	mvwprintw(game_win,13,30,"|"); //staff handle
	mvwprintw(game_win,14,30,"|"); //staff handle
	mvwprintw(game_win,15,30,"|"); //staff handle
	wattroff(game_win,WHITE);
	wattron(game_win,CYAN);
	mvwprintw(game_win,11,30,"+"); //staff head
	wattroff(game_win,CYAN);
}

void printScrugg(void) {
	wattron(game_win,WHITE);
	mvwprintw(game_win,10,27,"O O"); //eyes
	wattroff(game_win,WHITE);
	wattron(game_win,MAGENTA);
	mvwprintw(game_win,8,27,"___"); //top
	mvwprintw(game_win,9,26,"/"); //left top side
	mvwprintw(game_win,9,30,"\\"); //right top side
	mvwprintw(game_win,11,26,"\\"); //right bottom side
	mvwprintw(game_win,11,30,"/"); //left bottom side
	mvwprintw(game_win,11,27,"_"); //left btoom
	mvwprintw(game_win,11,29,"_"); //right bottom
	wattroff(game_win,MAGENTA);
	wattron(game_win,RED);
	mvwprintw(game_win,10,25,"<"); //ear?
	mvwprintw(game_win,10,31,">"); //ear?
	wattroff(game_win,RED);
	wattron(game_win,YELLOW);
	mvwprintw(game_win,9,28,"|"); //top middle
	mvwprintw(game_win,11,28,"|"); //bottom middle
	wattroff(game_win,YELLOW);
}

void printHalflings(void) {
	printHalflingL();
	printHalflingR();
}

 void printHalflingL(void) {
	wattron(game_win,YELLOW);
	mvwprintw(game_win,13,30,"0"); //head
	mvwprintw(game_win,14,28,"-- --"); //arms
	wattroff(game_win,YELLOW);	
	wattron(game_win,GREEN);
	mvwprintw(game_win,14,30,"|"); //torso
	wattroff(game_win,GREEN);
	wattron(game_win,BLUE);
	mvwprintw(game_win,15,29,"/ \\"); //legs
	wattroff(game_win,BLUE);
}

void printHalflingR(void) {
	wattron(game_win,YELLOW);
	mvwprintw(game_win,13,40,"0"); //head
	mvwprintw(game_win,14,38,"-- --"); //arms
	wattroff(game_win,YELLOW);	
	wattron(game_win,MAGENTA);
	mvwprintw(game_win,14,40,"|"); //torso
	wattroff(game_win,MAGENTA);
	wattron(game_win,CYAN);
	mvwprintw(game_win,15,39,"/ \\"); //legs
	wattroff(game_win,CYAN);
}

void printMonsterHead(const int x) {
	wattron(game_win,YELLOW);
	mvwprintw(game_win,9,26+x,"(   )"); //facce
	wattroff(game_win,YELLOW);
	wattron(game_win,WHITE);
	mvwprintw(game_win,9,27+x,". ."); //eyes
	wattroff(game_win,WHITE);
	wattron(game_win,RED);
	mvwprintw(game_win,9,28+x,"_"); //mouth
	wattroff(game_win,RED);
}

void printMonsterBody(void) {
	wattron(game_win,YELLOW);
	mvwprintw(game_win,10,25,"____\\----/____");
	mvwprintw(game_win,11,29,"|____|");
	mvwprintw(game_win,12,28,"/      \\");
	mvwprintw(game_win,13,27,"/        \\");
	mvwprintw(game_win,14,26,"/          \\");
}

void printMonsterSeveredHead(const int y, const int x) {
	wattron(game_win,YELLOW);
	mvwprintw(game_win,16+y,20+x,"(   )"); //severed head face
	wattroff(game_win,YELLOW);
	wattron(game_win,WHITE);
	mvwprintw(game_win,16+y,21+x,". ."); //severed head eyes
	wattroff(game_win,WHITE);
	wattron(game_win,RED);
	mvwprintw(game_win,16+y,22+x,"-"); //severed head mouth
	wattroff(game_win,RED);
}

//two headed monster
void printMonster(void) {
	printMonsterHead(0);
	printMonsterHead(7);
	printMonsterBody();
}

void printMonsterL(void) {
	printMonsterHead(7);
	printMonsterBody();
	printMonsterSeveredHead(0,0);
}

void printMonsterR(void) {
	printMonsterHead(0);
	printMonsterBody();
	printMonsterSeveredHead(-1,20);
}

//delmer body
 void printDelmerBody(const int y, const int x) {
	wattron(game_win,YELLOW);
	mvwprintw(game_win,11+y,29+x,"^"); //top of body
	mvwprintw(game_win,12+y,27+x,"<( )>"); //side of body
	mvwprintw(game_win,13+y,29+x,"v"); // bottom of body
	wattroff(game_win,YELLOW);
	wattron(game_win,RED);
	mvwprintw(game_win,12+y,29+x,"0"); //eye
	wattroff(game_win,RED);
} 

void printDelmerR(void) {
	printDelmerBody(0,8);
}

 void printDelmerL(void) {
	printDelmerBody(0,0);
}

void printDelmer(void) {
	printDelmerR();
	printDelmerL();
}

void printBoss(void) {
	wattron(game_win,GREEN);
	mvwprintw(game_win,4,29,"^^^^^^^^^^^"); //top of head
	wattroff(game_win,GREEN);
	wattron(game_win,BLUE);	
	mvwprintw(game_win,5,28,"/           \\");  //start of body
	mvwprintw(game_win,6,27,"/             \\");
	mvwprintw(game_win,7,26,"/               \\");
	mvwprintw(game_win,8,25,"/                 \\");
	mvwprintw(game_win,9,25,"\\                 /");
	mvwprintw(game_win,10,26,"\\               /");
	mvwprintw(game_win,11,27,"\\             /");
	mvwprintw(game_win,12,28,"\\___________/");  //end of body
	wattroff(game_win,BLUE);
	wattron(game_win,MAGENTA);		
	mvwprintw(game_win,9,31,"/v-v-v\\");  //top of mouth
	mvwprintw(game_win,10,30,"<       >"); //sides and middle of mouth
	mvwprintw(game_win,11,31,"\\_^_^_/"); //bottom of mouth
	wattroff(game_win,MAGENTA);
	printDelmerBody(-5,1); //delmer eyes for eyes
	printDelmerBody(-5,9); //delmer eyes for eyes
}

void printEnemies(const int x) {
	switch(x) {
		case 1:printSwordsman();
			break;
		case 2:printSkeleton();
			break;
		case 3:printSlinger();
			break;	
		case 4:printTheif();
			break;	
		case 5:printArcher();
			break;
		case 6:printSpearman();
			break;
		case 7:printDog();
			break;
		case 8:printMage();
			break;
		case 9:printScrugg();
			break;
		case 10:printHalflings();
			break;
		case 11:printMonster();
			break;
		case 12:printDelmer();
			break;
		case 13:printHalflingL();
			break;
		case 14:printHalflingR();
			break;
		case 15:printMonsterL();
			break;
		case 16:printMonsterR();
			break;
		case 17:printDelmerL();
			break;			
		case 18:printDelmerR();
			break;	
		case 19: printBoss();
			break;
		default : //do nothing
			break;
	}
	wrefresh(game_win);
}