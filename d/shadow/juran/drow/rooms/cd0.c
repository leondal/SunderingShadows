//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit VAULT;

void set_rope(int rope);

int rope_present;

void create(){
   ::create();
	set_name("hallway");
	set_short("Hallway");
   set_long(
    	"%^BOLD%^%^BLUE%^"+
    	"After climing down the long tunnel you find yourself in a room with a "+
    	"door to the east.  The stonework has the definite look of dwarven "+
    	"workmanship, but where you would see sconces and other places to "+
    	"hold light sources they are curiously absent.  The walls are smooth "+
    	"and the floor is free from dust and debris.  This area has signs of "+
    	"recent habitation. The floor is covered completely with a gray "+
    	"moss-like substance that is both soft and springy.  The east wall "+
    	"seems to have been worked more than the other walls in the area.  "+
    	"The moss comforts your feet while walking and absorbs much of the "+
    	"sound in the room.  To the north you see a hole in the ceiling.\n"+
    	"%^RESET%^"
   );
 	set_terrain(BUILT_CAVE);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
   set_property("light",-3);
   set_smell("default","The room smells clean and dry.");
   set_listen("default","You hear very little save the noises you make yourself.");
   set_items(([
   	"moss" : "Gray and benign it looks as if its only purpose is to cover the floor.\n",
      ({"walls","wall"}) : "The walls are smooth and gray and the stonework looks to "+
      	"be of dwarven quality.\n",
      "floor" : "Covered with a gray moss the floor is smooth, level, and free of "+
        	"dirt and debris.\n",
      "ceiling" : "About 10 feet overhead the ceiling looks to be smooth and even.\n",
      "hole" : "There is a hole in the celing to the north where you could climb "+
      	"out if you had the skill or the tools.\n",
      "east wall" : "The east wall seems a bit more worked than the other "+
      	"walls, maybe a closer examination will reveal more?\n"
   ]));

   set_search("east wall","The east wall seems to be a bit more "+
   	"smooth than the rest of the walls in the area, except for a "+
   	"small protrusion in the upper right.  The protrusion has the look of a button.\n");

   set_exits(([
		"south" : DROOMS+"cd9"
   ]));

   set_climb_exits((["climb":({DROOMS+"c15",20,6,100})]));
   set_fall_desc("%^BOLD%^%^RED%^You fall a long way tumbling into the "+
		"darkness bouncing off the sides of the tunnel until you come to a sudden "+
		"and painful stop at the bottom!%^RESET%^\n");

   set_door("door",(DROOMS+"cd1"),"east","obsidian key");
   set_locked("door",1,"lock");
   	(DROOMS+"cd1")->set_locked("door",1,"lock");
    	lock_difficulty("door",-25,"lock");
   set_door_description("door","Sturdy and heavy this door is made of oak and "+
    	"ironbound.  It looks like it could take quite a beating and yet still "+
    	"remain standing. The door is locked and you can make out a keyhole under "+
    	"the handle.");
   set_string("door","open","You open the door into a dark hallway.\n");

   set_trap_functions(({"door"}),({"gas_em"}),({"pick"}));

}
void init() {
  	::init();
  	add_action("press_em","press");
}
int press_em(string str) {
 	if(!str) {
   	tell_object(TP,"Press what?");
      return 1;
   }
  	if(str == "button"){
   	if(member_array("east",TO->query_exits()) != -1) {
      	tell_object(TP,"The door has already been uncovered!");
         return 1;
      }
     	tell_object(TP,"You press the button and a door appears in the "+
     		"recently blank wall. \n");
     	tell_room(ETP,""+TPQCN+" presses a part of the east wall and a door appears.\n",TP);

     	add_exit((DROOMS+"cd1"),"east");
		(DROOMS+"cd1")->add_exit(DROOMS+"cd0","west");

   	set_door("door",DROOMS+"cd1","east","obsidian key");
   	set_locked("door",1,"lock");
   		(DROOMS+"cd1")->set_locked("door",1,"lock");
    		lock_difficulty("door",-25,"lock");
   	set_door_description("door","Sturdy and heavy this door is made of oak and "+
    		"ironbound.  It looks like it could take quite a beating and yet still "+
    		"remain standing. The door is locked and you can make out a keyhole under "+
    		"the handle.");
  	 	set_string("door","open","You open the door into a dark hallway.\n");

   	set_trap_functions(({"door"}),({"gas_em"}),({"pick"}));
    	
   	return 1;
   }
}
int gas_em(string str){
	tell_object(TP,"%^BOLD%^%^RED%^As you work at the lock you suddenly "+
		"hear an unwanted click.%^RESET%^\n");
	TP->force_me("emote gulps.");
	toggle_trap("door","pick","lock");
	tell_room((DROOMS+"cbed3"),"%^BOLD%^%^RED%^A bell rings two times.\n%^RESET%^",TP);
	tell_room((DROOMS+"cbed4"),"%^BOLD%^%^RED%^A bell rings two times.\n%^RESET%^",TP);
	tell_room((DROOMS+"lab1"),"%^BOLD%^%^RED%^A bell rings two times.\n%^RESET%^",TP);
	tell_room(ETP,"%^BOLD%^%^GREEN%^A noxious gas quickly spews out of the lock "+
		"and fills the room.  Your eyes start burning and your mouthly quickly "+
		"dries up.%^RESET%^\n");
	return 0;

//not meant to hurt or poison..just to scare thief and alert the resident//
}