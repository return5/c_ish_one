# c_ish_one
Simple gmae with Rogue like inspired elements written in C using ASCII graphics and runs in terminal

  ============== Introduction ==============  
       - C-ish one is a very simple game with some mechanics inspired by rogue-like style games.   
       - the player starts off on a 2D map with randomly generated tiles and enemy locations. a few player stats are also randomly generated as well. 

  ============== controls ==============  
     - player moves character around using either arrow keys, or num pad (8-2,4-6)  
     - during combat, when it is player's turn, they are given a prompt with option and keys to press for each. keys are : numbers 1-5  
     - pressing 'q' while on map will allow player to exit game after a confirmation dialog.   
     - when given a prompt with a question and a '(y/n)', pressing 'y' results in yes and pressing 'n' results in no.  

  ============== objectives ==============  
    - the player's objective is to move around the map gaining points and ultimately defeat the final boss.   
    - once the player has gained enough points, a teleportation device will appear on the center of the map.  
    - if player chooses to go through the teleportation device, they will be teleported to a different randomly generated map.   
    - once at the second map, the objective is to continue gaining points. once enough points have been earned, another teleportation device will appear.  
    - when player enters the second teleportation device, they will be teleported to the final boss. defeat this boss to win the game.  

  ============== gaining points ==============  
    - player can gain points in the following ways:  
    - defeating enemies in combat  
    - making an offering to the gods at a hidden shrine that they discovered on the map  
    - finding valuable loot at locations which they discovered on the map  

  ============== Shrines ==============  
    - each map has 3 shrines which are hidden and can be discovered by the player  
    - when a player finds a shrine they are given the option to make an offering to the gods  
    - if player chooses to make an offering, they gain points and a small boost to either their health, attack, or defense. the stat which is increased is chosen randomly.  
    - player can only make one offering per shrine. a total of three offerings can be made per map, one per shrine discovered.   

  ============== Combat ==============  
    - combat is done on a turn by turn basis. player gets a turn allowing one action to be performed, then the enemy gets a turn allowing one action to be performed, then back to player and repeats.  
    - when player enters combat they are presented with a view of themselves, the enemy, and a prompt giving them options and  which key to press for that option 
      - options are :  
        - 1) attack - attempt to strike your enemy  
        - 2) raise defense - allows you to raise your defense by 2. can be done only once per fight.  
        - 3) - special attack - allows you to attempt to use your special attack. can only successfully be used once per fight.   but can attempt it as many times as you like until you are successful.  note : each special attack is ineffective against certain enemy types.  
        - 4) run away - attempt to flee the fight. may or not be successful.  
        - 5) eat food - if player has food in their inventory, they can eat some to gain 10 health points.  

  ============== Special Attacks ==============  
    - at start of game, player is randomly assigned one of three possible special attacks. they are:     
         - power attack - swing your sword and do a large amount of damage to the enemy.    
         - defense down spell - cast a spell which lowers the defense rating of the enemy by 3.    
         - throw - throws opponent to the ground. causes two points of damage and the enemy will lose their next two turns    
    -note: each special attack is completely ineffective against certain enemy types.     

  ============== Camps ==============  
    - while exploring map, player may discover locations or camps.   
    - possible camps are : small cabin, lean-to, large clearing, and halfing camp.   
    - at each camp, player may discover:    
      - an enemy to fight.    
      - food to eat/take with them.  
      - valuable loot which gains them points.    
    - each camp can have none, all three, or any combination of the three.     
    

  ============== Tiles ==============  
  the tiles: "~ : ^ / " and blank space are world map tiles.    
  -yellow '&' is the location of a well. you can drink water to restore health   
  -red 'x' is the location of a camp which you have discovered    
  -red 'e' marks location of an enemy which you have run away from      
  -magenta 's' is the location of a shrine which you have discovered   
  -cyan '@' - player character  
  
============== Requirments ==============   
  - Linux system 
  - GCC 
  - ncurses library https://invisible-island.net/ncurses/ (make sure to use the flag '-lncurses' when compiling with gcc) 

    
