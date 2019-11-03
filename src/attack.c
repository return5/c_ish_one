#include "gamepieces.h"
#include "attack.h"
#include <stdlib.h> //sprintf
#include <string.h> //strcat, strcpy
#include "printenemy.h"
#include "printobjects.h"

/*=========================================== const ==========================================================================*/
#define ENEMY previous->character


/*=========================================== prototypes ==========================================================================*/


static int getRandInt(const int limit);
void printAttackPrompt(void);
void getInput(int *const run_away,int *const play);
void criticalHit(Character *const attacker,Character *const enemy,const char *const str);
void regularHit(Character *const attacker,Character *const defender,const char *const str);
void counterStrike(Character *const attacker,Character *const defender);
void missed(Character *const attacker,Character *const defender,const char *const str);
void attackEnemySelection(Character *const attacker,Character *const defender);
void raiseDefense(Character *const attacker);
void useSpecial(Character *const attacker,Character *const defender);
void computerSelection(int *const play);
void eatFood(void);
void playerAliveReset(int *const run_away,int *const ran_away);
void throwOpponent(Character *const attacker,Character *const defender);
void defenseDown(Character *const attacker,Character *const defender);
void powerAttack(Character *const attacker,Character *const defender);
void playerTurn(int *const play, int *const run_away);
void computerTurn(int *const play);
int critHitRLEnemy(Character *const defender);
void printHalflingCut(const int selection);
void printGiantCut(const int selection);
void printDelmerCut(const int selection);
int checkIfHealthIsHalf(Character *const defender);
int runAway(void);
void theifSpecial(void);
void archerSpecial(void);
void resetTile(void);
void setPlayerStrings(void);
void makeHalflingEnragedStrings(void);
void makeMonsterEnragedStrings(void);
void makeDelmerEnragedStrings(void);
int checkEnragedEnemy(void);
void printNewEnemy(void); 
void makeBossStrings(void);
void setUpBoss(void);
void bossSpecial(void);
char *throwBoss(void);
void playerRetry(const char *const str);
void refreshPrompt(void);
char *defensedownBoss(void);
char *powerAttackBoss(void);
void playerSpecial(void);

/*=========================================== code ==========================================================================*/

static int getRandInt(const int limit) {
	const int divisor = RAND_MAX/(limit + 1);
	int value;
	do{
		value = rand() / divisor;
	} while(value > limit);

	return value;
}

void bossSpecial(void) {		
	char *const str = malloc(160);
	if(getRandInt(10) > PLAYER->chance_to_dodge && getRandInt(10) >= ENEMY->crit_chance) {		
		sprintf(str,ENEMY->special_attack,ENEMY->attack);
		PLAYER->defense -= 2;
		PLAYER->health -= ENEMY->attack;
		PLAYER->turn = 2;
		ENEMY->special_count = 1;
	}
	else {
		sprintf(str,ENEMY->special_attack_miss);
	}
	wprintw(prompt_win,"%s",str);
}

void makeBossStrings(void) {
	ENEMY->regular_attack = "boss monster attacks you for %d damage.";
	ENEMY->regular_miss = "you dodged the monster's attack."; 
	ENEMY->counter_miss = "big boss counters dealing 4 damage."; 
	ENEMY->raise_defense = "big boss hardens its skin, increasing its defense rating."; 
	ENEMY->critical_hit = "the big bad monster scored a crit hit on you.\nyou suffer %d damage.";
	ENEMY->special_attack = "boss monster's eyes glow red. you feel weakened.\nthen it lets out a horrid screech.\nyour defense had been lowered\nyou suffer %d damage\nyou lose 2 turns.";
	ENEMY->special_attack_miss = "big boss starts its special attack\nyou mange to interrupt it in time and stop it.";
	ENEMY->prompt = "you encounter a large, grotesque monster.\nthis is the final boss.kill it and you are home free";
}

void setUpBoss(void) {
	Character *b = malloc(sizeof(Character));
	b->name = "Big Boss Monster";
	b->special_count = 0;
	b->turn = 0;
	b->health = 25;
	b->health_max = 25;
	b->attack = 8;
	b->defense = 3;
	b->crit_chance = 6;
	b->chance_to_dodge = 6;
	b->defense_up = 0;
	b->type = 19;
	ENEMY = b;
	previous->type = 1;
	makeBossStrings();
}

void makeHalflingEnragedStrings(void) {
	ENEMY->regular_attack = "enraged halfling attacks you for %d damage.";
	ENEMY->regular_miss = "halfing strikes at you but misses.";
	ENEMY->counter_miss = "enraged halfling counters and hits you for 2 damage.";
	ENEMY->raise_defense = "enraged halfling gets even angrier, his defense is raised by 2.";
	ENEMY->critical_hit = "in a rage the halfling hits you pretty hard.\nhe inflicts %d damage to you.";
	ENEMY->special_attack = "halfling summouns all his anger and channels it\nhe hits you inflicting %d damage.";
	ENEMY->special_attack_miss = "in his rage the halfling misses his attack.";
	ENEMY->special_fail = "halfling is just too angry, your attack fails.\nhe retaliates against you doing four damage.";
	ENEMY->prompt = "you killed his friend\nthe surviving halfling is now thrown into an enraged state.";
}

void makeMonsterEnragedStrings(void) {
	ENEMY->regular_attack = "enraged beast attacks you dealing %d damage.";
	ENEMY->regular_miss = "angry monster missed you with his attack.";
	ENEMY->counter_miss = "enraged beast counters your attack inflicting four damage.";
	ENEMY->raise_defense = "in his enraged state the monster now has increased defense.";
	ENEMY->critical_hit = "in his fury the monster hits you very hard.\nyou suffer %d damage.";
	ENEMY->special_attack = "the very angry monster swings with all his might\nyou suffer %d damage.";
	ENEMY->special_attack_miss = "the beast is just too angry to hit you.";
	ENEMY->special_fail = "nothing but good old fashion stabbing is going to take down this infuriated beast.\nhe counters doing four damage.";
	ENEMY->prompt = "cutting off his other head aggravates the monster. he is now enraged.";
}
void makeDelmerEnragedStrings(void) {
	ENEMY->regular_attack = "angered delmer eye hits you for %d damage.";
	ENEMY->regular_miss = "enraged delmer eye missed.";
	ENEMY->counter_miss = "the angry delmer eye counters your attack dealing four damage to you.";
	ENEMY->raise_defense = "the enraged delmer eye increases its defense.";
	ENEMY->critical_hit = "the infuriated delmer eye hit you forcibly.\nyou suffer %d damage";
	ENEMY->special_attack = "the angry delmer eye savagely strikes at you inflicting %d damage.";
	ENEMY->special_attack_miss = "you manage to block the delmer eye's ferocious attack";
	ENEMY->special_fail = "the enraged delmer is immune to any special attack from you.\nyou take 4 damage in your attempt.";
	ENEMY->prompt = "\nkilling the delmer eye causes the other to enter into a rage.";
}

void printNewEnemy(void) {
	wclear(game_win);
	switch(ENEMY->type) { //reprint background for halfing camp and monster
		case 13://enraged halflings
		case 14://enraged halflings		
			printPlaces(1); //printobjects.c
			break;
		case 15://enraged monster
		case 16://enraged monster
			printPlaces(3); //printobjects.c
			break;
		default: //do nothing
			break;
	}
	printHero();  //printenemy.c
	printEnemies(ENEMY->type); //printenemy.c
	wrefresh(game_win);
}

void printHalflingCut(const int selection) {
	wclear(prompt_win);
	wprintw(prompt_win,"%s\n",(selection == 0) ? "you struck the right hand halfling killing it." : "you struck the left hand halfling killing it.");
	wprintw(prompt_win,"%s",ENEMY->prompt);
}

void printGiantCut(const int selection) {
	wclear(prompt_win);
	wprintw(prompt_win,"%s",(selection == 0) ? "you swing with all your might and cut off the head on the right hand side." : "you swing with all your might and cut off the head on the left hand side.");
	wprintw(prompt_win,"%s",ENEMY->prompt);
}

void printDelmerCut(const int selection) {
	wclear(prompt_win);
	wprintw(prompt_win,"%s",(selection == 0) ? "you strike a blow to the delmer eye on the right." : "you strike a blow to the delmer eye on the left.");
	wprintw(prompt_win,"%s",ENEMY->prompt);
}

int critHitRLEnemy(Character *const defender) {
	const int selection = getRandInt(1);
	switch (defender->type) {
		case 10: 
			makeHalflingEnragedStrings();
		    printHalflingCut(selection);
			ENEMY->type += (selection + 3);
			break;
		case 11: 
			makeMonsterEnragedStrings();
			printGiantCut(selection);
			ENEMY->type += (selection + 4);
			break;
		case 12: 
			makeDelmerEnragedStrings();
			printDelmerCut(selection);
			ENEMY->type += (selection + 5);
			break;
		default: return 0; //if not one of the select three, just return 0;
			break;
	}
	//add enraged stat modifier to halfling,delmer,and monster
	ENEMY->attack += 2;
	ENEMY->defense += 1;
	ENEMY->defense_value += 1;
	ENEMY->health += 10;
	ENEMY->health_max = defender->health;
	ENEMY->special_count = -1;
	ENEMY->crit_chance -= 1; //increases chance to do crit attack. counterintuitive with the minus
	printNewEnemy();
	return 1;
}
int checkIfHealthIsHalf(Character *const defender) {
	return ((defender->health ) <= ((defender->health_max) / 2)) ? critHitRLEnemy(defender) : 0;
}

void criticalHit(Character *const attacker,Character *const enemy, const char *const str) {
	const int damage = (attacker->attack - enemy->defense > 0) ? (attacker->attack - enemy->defense) + 2 : 3;
	enemy->health -= damage;
	if(checkIfHealthIsHalf(enemy) == 0) {
		char str1[150];
		sprintf(str1,str,damage);
		wprintw(prompt_win,"%s\n",str1);
	}
}

void regularHit(Character *const attacker,Character *const defender, const char *const str) {
	const int damage = (attacker->attack - defender->defense > 0) ? attacker->attack - defender->defense : 1;
	defender->health -= damage;
	if(defender->type == 11 || checkIfHealthIsHalf(defender) == 0) {
		char str1[150];
		sprintf(str1,str,damage);
		wprintw(prompt_win,"%s\n",str1);
	}
}

void counterStrike(Character *const attacker,Character *const defender) {
	attacker->health -= 2;
	if(checkIfHealthIsHalf(defender) == 0) {
		wprintw(prompt_win,"%s\n",defender->counter_miss);
	}
}

void missed(Character *const attacker,Character *const defender,const char *const str) {
	wprintw(prompt_win,"%s\n",str);
	if (getRandInt(10) > defender->crit_chance && defender->turn == 0) {
		counterStrike(attacker,defender);
	}
}

void attackEnemySelection(Character *const attacker,Character *const defender) {
	if(getRandInt(10) > defender->chance_to_dodge || defender->turn != 0) {
		(getRandInt(10) > attacker->crit_chance) ? criticalHit(attacker,defender,attacker->critical_hit) : regularHit(attacker,defender,attacker->regular_attack);
	}
	else {
		missed(attacker,defender,attacker->regular_miss);
	}

	switch(attacker->type) {
		case 4:
		case 10:
		case 12: //allows these enemies a second attack
			if(getRandInt(10) > defender->chance_to_dodge) {
				(getRandInt(10) > attacker->crit_chance) ? criticalHit(attacker,defender,attacker->critical_hit_second) : regularHit(attacker,defender,attacker->regular_attack_second);
			}
			else {
				missed(attacker,defender,attacker->regular_miss_second);
			}
			break;
		default: //do nothing
			break;
	}
	refreshPrompt();
}

void raiseDefense(Character *const attacker) {
	char str1[150];
	sprintf(str1,attacker->raise_defense);
	wprintw(prompt_win,"%s\n",str1);
	attacker->defense += 2;
	attacker->defense_up = 1;
	refreshPrompt();
}

char *throwBoss(void) {
	if(getRandInt(10) > ENEMY->chance_to_dodge) {
		ENEMY->health -= 2;
		ENEMY->turn = 2;	
		PLAYER->special_count = 1;
		return "boss is too big and floats too much for you to throw.\ninstead you poke its eyes out.\nboss cant see for 2 turns.";
	}
	else {
		return "you try to poke the monster's eyes out but couldn't get close enough.";
	}
}

char *defensedownBoss(void) {
	if(getRandInt(10) > ENEMY->chance_to_dodge) {
		PLAYER->attack += 2;
		PLAYER->special_count = 1;
		return "your spell failed against boss\nyou try a different spell, this one increases your attack by 2.\nit works just fine";
	}
	else {
		return "you tried to cast a spell against boss monster, but failed.";
	}
}

char *powerAttackBoss(void) {
	if(getRandInt(10) > ENEMY->chance_to_dodge) {
		const int damage = (PLAYER->attack + 4) - ENEMY->defense;
		ENEMY->health -= damage;
		PLAYER->special_count = 1;
		char *const str1 = malloc(160);
		sprintf(str1,"you find a big ass sword laying at your feet.\nyou pick it up and swing with all your might.\nyou hit the boss for %d damage, unfortunately the sword breaks.",damage);
		return str1;
	}
	else {
		return "you swing very very hard but miss the big monster.";
	}
}

void throwOpponent(Character *const attacker,Character *const defender) {
	char str1[210];
	switch(defender->type) {
		case 4://thief
		case 5://archer
		case 11://monster
		case 12://delmer
			//throws dont work on these guys
			sprintf(str1,defender->special_fail);
			attacker->health -= 2;
			break;
		case 13://enraged halflings
		case 14://enraged halflings
		case 15://enraged monster
		case 16://enraged monster
		case 17://enraged delmer
		case 18://enraged delmer
				// throws dont work on enraged enemies
				sprintf(str1,defender->special_fail);
				attacker->health -= 4;
			break;
		case 19: sprintf(str1,throwBoss()); //special throw against boss
			break;
		default: //against any other enemy
			if(getRandInt(10) > defender->chance_to_dodge) {
				sprintf(str1,attacker->special_attack);
				defender->turn += 2;
				defender->health -= 2;
				attacker->special_count += 1;
			}
			else {
				sprintf(str1,attacker->special_attack_miss);
			}
			break;
	}
	wprintw(prompt_win,"%s\n",str1);
}

void defenseDown(Character *const attacker,Character *const defender) {
	char str1[160];
	switch(defender->type) {
		case 2://skeleton
		case 6://spearman
		case 8://mage
		case 9://scrugg
			//spell doesnt work against these enemy types
			sprintf(str1,defender->special_fail);
			attacker->health -= 2;
			break;
		case 13://enraged halfling
		case 14://enraged halfling
		case 15://enraged monster
		case 16://enraged monster
		case 17://enraged delmer
		case 18://enraged delmer
			//spells dont work on enraged monsters
			sprintf(str1,defender->special_fail);
			attacker->health -= 4;
			break;
		case 19: sprintf(str1,defensedownBoss()); //defense down against boss
			break;
		default: // against any other type of enemy.
			if(getRandInt(10) > defender->chance_to_dodge) {
				sprintf(str1,attacker->special_attack);
				defender->defense -= 3;
				if(defender->defense < 0) {
					defender->defense = 0;
				}
				attacker->special_count += 1;
			}
			else {
				sprintf(str1,attacker->special_attack_miss);
			}
			break;
	}
	wprintw(prompt_win,"%s\n",str1);
}

void powerAttack(Character *const attacker,Character *const defender) {
	char str1[160];
	switch(defender->type) {
		case 1://swordsman
		case 3://slinger
		case 7://four legged beast
		case 10://halfling
			//power attacks dont work against these types
			sprintf(str1,defender->special_fail);
			attacker->health -= 2;
			break;
		case 13://enraged halfling
		case 14://enraged halfling
		case 15://enraged monster
		case 16://enraged monster
		case 17://enraged delmer
		case 18://enraged delmer
			//cant use special attack against enraged enemy
			sprintf(str1,defender->special_fail);
			attacker->health -= 4;
			break;
		case 19: sprintf(str1,powerAttackBoss()); //power attack against boss
			break;
		default: //against any other enemy
			if(getRandInt(10) > defender->chance_to_dodge) {
				const int damage = (attacker->attack + 4) - defender->defense;
				sprintf(str1,attacker->special_attack,damage);
				defender->health -= damage;
				attacker->special_count += 1;
			}
			else{
				sprintf(str1,attacker->special_attack_miss);
			}
			break;
	}
	wprintw(prompt_win,"%s\n",str1);
}

void playerSpecial(void) {
	switch(PLAYER->special) {
		case 0:throwOpponent(PLAYER,ENEMY);
			break;
		case 1:defenseDown(PLAYER,ENEMY);
			break;
		case 2:powerAttack(PLAYER,ENEMY);
			break;
		default: //do nothing
			break;
	}
}

void theifSpecial(void) {
	int check = 0;
	if(PLAYER->food != 0) {
		if(getRandInt(10) > PLAYER->chance_to_dodge) {
			wprintw(prompt_win,"thief stole some food from you.");
			PLAYER->food -= 1;
			ENEMY->special_count = 1;
			check += 1;
		}
	}

	if(getRandInt(10) > PLAYER->chance_to_dodge) {
		wprintw(prompt_win,"%s\n",ENEMY->special_attack);
		score -= 10;
		ENEMY->special_count = 1;
		check += 1;
	}

	if (!check) {
		wprintw(prompt_win,"%s\n",ENEMY->special_attack_miss);
	}
}

void useSpecial(Character *const attacker,Character *const defender) {
	switch(attacker->type) {
		case 0:playerSpecial();
			break;
		case 1://sowrdsman
		case 2://skeleton
		case 5://archer
		case 11://monster
		case 13://enraged halfling
		case 14://enraged halfling
		case 15://enraged monster
		case 16://enraged monster
		case 17://enraged delmer
		case 18://enraged delmer
		case 12://delmer
			powerAttack(attacker,defender);
			break;
		case 3://slinger
		case 6://spearman
		case 10://halflings
		case 7://four legged beast
			throwOpponent(attacker,defender);
			break;
		case 8://mage
		case 9://scrugg
			defenseDown(attacker,defender);
			break;		
		case 4: theifSpecial();
			break;	
		case 19: bossSpecial();
			break;
		 default: //do nothing
			 break;
	 }
	 refreshPrompt();
}

void eatFood(void) {
	wprintw(prompt_win,"you eat some food, restoring 10 health.\n");
	refreshPrompt();
	PLAYER->health += 10;
	PLAYER->food -= 1;
	if(PLAYER->health > PLAYER->health_max) {
		PLAYER->health = PLAYER->health_max;
	}
}

void computerSelection(int *const play) {
	wclear(prompt_win);
	switch(getRandInt(9)+1) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:attackEnemySelection(ENEMY,PLAYER);
			break;
		case 6:
		case 7:
		case 8:(ENEMY->defense_up == 0) ? raiseDefense(ENEMY) : computerSelection(play);
			break;		
		case 9:
		case 10:(ENEMY->special_count < 1) ? useSpecial(ENEMY,PLAYER) : computerSelection(play);
			break;
		default:attackEnemySelection(ENEMY,PLAYER);
			break;
	}	
	if (PLAYER->health < 1 || ENEMY->health < 1) {
		*play = 0;
	}
}

int checkEnragedEnemy(void){
	switch(ENEMY->type) {
		case 13://enraged halflings
		case 14://enraged halflings
		case 15://enraged monster
		case 16://enraged monster
		case 17://enraged delmer
		case 18://enraged delmer
			return 1;
			break;
		default: return 0;
			break;
	}
}

int runAway(void) {
	const int check = checkEnragedEnemy();
	if (PLAYER->turn == 0 && check == 0) {
		switch (getRandInt(2)) {
			case 0:
			case 1: 
				wprintw(prompt_win,"you manage to run away from the enemy.\n");
				return 1;
				break;
			case 2: 
				wprintw(prompt_win,"you did not manage to run away from the enemy.\n");
				return 0;
				break;
			default: return 1;
				break;
		}
	}
	else if (check == 1) {
		 wprintw(prompt_win,"you cant run away from an enraged enemy.\n");
		 return 0;
	}
	else {
		 wprintw(prompt_win,"you cant run away while knocked down.\n");
		 return 0;
	}
}

void refreshPrompt(void) {
	wrefresh(prompt_win);	
	getch();
}

void playerRetry(const char *const str) {
	wprintw(prompt_win,"%s",str);
	refreshPrompt();
	printAttackPrompt();
}

void getInput(int *const run_away, int *const play) {
	wclear(prompt_win);
	switch(getch()) {
		case '1': attackEnemySelection(PLAYER,ENEMY);
			break;
		case '2': (PLAYER->defense_up == 0) ? raiseDefense(PLAYER) : (playerRetry("sorry,you cant raise your defenses any higher."), getInput(run_away,play));
			break;
		case '3': (PLAYER->special_count == 0) ? useSpecial(PLAYER,ENEMY) : (playerRetry("you cant use your special more than once per fight."), getInput(run_away,play));
			break;
		case '4': 
			*run_away = runAway();
			refreshPrompt();
			break;	
		case '5': (PLAYER->food > 0) ? eatFood() : playerRetry("sorry, you dont have any food to eat.");
			break;
		default: 
			playerRetry("sorry, wrong key pressed. try again."); 
			getInput(run_away,play);
			break;	
	}
	if (PLAYER->health < 1 || ENEMY->health < 1 || *run_away == 1) {
		*play = 0;
	}
}

void printAttackPrompt() {
	wclear(prompt_win);
	wprintw(prompt_win,"player health is %d, attack is %d, defense is %d, food is %d\n",PLAYER->health,PLAYER->attack,PLAYER->defense,PLAYER->food);
	wprintw(prompt_win,"\tdo you wish to\n\t\t1)attack\n\t\t2)raise defenses\n\t\t3)%s\n\t\t4)run away\n\t\t5)eat some food to recover health\n",PLAYER->special_name);
	wrefresh(prompt_win);
}

//if player runs away, tile is set to e, but if player returns and kills the enemy, tile is reset to original char.
void resetTile(void) {
	if(previous->tile_set == 'e') {
		switch(previous->type) {
			case 1:
			case 2:
			case 3:
			case 5: previous->tile_set = 'x';
				break;
			default: previous->tile_set = previous->tile_temp;
				break;
		}
	}
}

//if player is alive after battle, reset stats and remove computer player from piece
void playerAliveReset(int *const run_away, int *const ran_away){
	PLAYER->defense = PLAYER->defense_value;
	PLAYER->defense_up = 0;
	PLAYER->special_count = 0;
	PLAYER->turn = 0;
	*ran_away = *run_away;
	if (*run_away == 0) {
		(previous->type != 1) ? (previous->obj->enemy = 0) : (previous->type = 0);
		score += 10;
		resetTile();
	}
	else {
		previous->tile_temp = previous->tile_set;
		previous->tile_set = 'e';
		*run_away = 0;
	}
}

void playerTurn(int *const play, int *const run_away) {
	if(PLAYER->turn == 0) {
		printAttackPrompt();
		getInput(run_away,play);
	}
	else {
		wclear(prompt_win);
		wprintw(prompt_win,"you lost this turn");
		PLAYER->turn -= 1;
		refreshPrompt();
	}
}

void computerTurn(int *const play) {
	if(ENEMY->turn == 0) {
		computerSelection(play);
	}
	else {
		wclear(prompt_win);
		wprintw(prompt_win,"%s lost this turn.\n",ENEMY->name);
		ENEMY->turn -= 1;
		refreshPrompt();
	}
}

//at the start of combat, set up messages which will be displayed to player
void setPlayerStrings(void) {
	char str1[150],str2[150],str3[150],str4[150],str5[150],str6[150];
	sprintf(str1,"you swing you sword and hit %s",ENEMY->name);
	strcat(str1," doing %d damage.");
	sprintf(str2,"you swung your sword but missed %s.",ENEMY->name);
	sprintf(str3,"you counter, inflicting 2 damage.");
	sprintf(str4,"you swing and make a critical hit on %s.\nyou",ENEMY->name);
	strcat(str4," do %d damage.");

	switch(PLAYER->special) { //string based on which special player got.
		case 0:
			sprintf(str5,"you throw %s to the ground.\nthey lose 2 turns and suffer 2 damage.",ENEMY->name);
			sprintf(str6,"you tried to throw %s to the ground but failed",ENEMY->name);			
			break;
		case 1:
			sprintf(str5,"you cast a spell against %s lowering their defense by 3.",ENEMY->name);
			sprintf(str6,"you tried, but failed to cast a spell against %s.",ENEMY->name);
			break;
		case 2:
			sprintf(str5,"you perform a power attack against %s",ENEMY->name);
			strcat(str5," causing %d damage.");
			sprintf(str6,"you tried to do a power attack against %s but you failed.",ENEMY->name);			
			break;
		default://do nothing
			break;
	}
	
	strcpy(PLAYER->regular_attack,str1);
	strcpy(PLAYER->regular_miss,str2);
	strcpy(PLAYER->counter_miss,str3);
	strcpy(PLAYER->critical_hit,str4);
	strcpy(PLAYER->special_attack,str5);
	strcpy(PLAYER->special_attack_miss,str6);
}

int attackEnemy(int *const continue_game) {
	int run_away = 0;
	int ran_away = 0; //returned value of run_away before it is reset. needed for running away from a building.
	int play = 1;
	setPlayerStrings();
	wclear(prompt_win);
	wprintw(prompt_win,"%s",ENEMY->prompt);
	refreshPrompt();
	while (play == 1) {
		playerTurn(&play,&run_away);
		if (play == 1) {
			computerTurn(&play);
		}
	}
	(PLAYER->health > 0) ? (playerAliveReset(&run_away,&ran_away)) : (*continue_game = 0);
	return ran_away;
}