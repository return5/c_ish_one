//------------------------------- include guard -----------------------------
#ifndef GAMEPIECES_M
#define GAMEPIECES_M

//------------------------------- headers -----------------------------------
#include <ncurses.h> //needs -lncurses gcc flag

//------------------------------- macros -----------------------------------
#define HEIGHT 20
#define WIDTH 50
#define fruit for
#define BLACK COLOR_PAIR(1)
#define WHITE COLOR_PAIR(2)
#define GREEN COLOR_PAIR(3)
#define YELLOW COLOR_PAIR(4)
#define CYAN COLOR_PAIR(5)
#define RED COLOR_PAIR(6)
#define MAGENTA COLOR_PAIR(7)
#define BLUE COLOR_PAIR(8)
#define PLAYER player->character

//------------------------------- typedefs structs -----------------------------------
typedef struct Character {
	int health,turn,special_count,health_max,attack,defense,crit_chance,type,chance_to_dodge,defense_up,defense_value,food,special;
	char *name,*special_name,*regular_attack,*regular_miss,*regular_attack_second,*regular_miss_second,*counter_miss,*raise_defense,*critical_hit,*critical_hit_second,*special_attack,*special_attack_miss,*special_fail,*prompt;
}Character;

typedef struct Object {
	int type,food,loot,enemy; //type of object. food,loot,enemy flags. 1 == true, 0 == false
}Object;

typedef struct tile {
	int x,y,well_full,type,visited,shrine_blessing,thing_near,discovered; //visited,discovered only used for camps. shrine_blessing holds which belssing that shrine does
	char tile_set,tile_temp; //tile temp holds tile_set so it can be set back to it if it is changed to 'e'
	Character *character; //Character struct
	Object *obj; //Object struct
}tile;

//------------------------------- global vars -----------------------------------
extern int half_x,half_y;
extern tile *player;
extern tile *previous;
extern tile *map[HEIGHT][WIDTH];
extern WINDOW *game_border; 		  	   //window for game border	
extern WINDOW *game_win;			  	  //window for game map
extern WINDOW *prompt_win;	   	     	 //window for text prompts

#endif

