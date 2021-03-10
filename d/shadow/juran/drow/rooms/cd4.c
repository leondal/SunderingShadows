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
   	"The stonework here continues to have look of dwarven workmanship and "+
   	"any traces of light sources are still non-existent.  The walls are smooth "+
   	"and the floor is free from dust and debris. The floor is covered "+
   	"completely with a gray moss-like substance that is both soft and "+
   	"springy.  The moss comforts your feet while walking and absorbs much "+
   	"of the sound in the room.  A painting adorns the north wall and armor "+
   	"fused together for decoration stands guard on the east, south and west "+
   	"walls.  You see the hallway runs to the southwest.\n"+
   	"%^RESET%^"
   );
 	set_terrain(BUILT_CAVE);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
   set_property("light",-3);
   set_smell("default","The room smells clean and dry with traces of armor "+
   	"oils and leather.");
   set_listen("default","You hear very little save the noises you make yourself.");
   set_items(([
     	"moss" : "Gray and benign it looks as if its only purpose is to cover "+
     		"the floor.\n",
     	({"walls","wall"}) : "The walls are smooth and gray and the stonework looks to "+
     		"be of dwarven quality.\n",
     	"floor" : "Covered with a gray moss the floor is smooth, level, and free of "+
     		"dirt and debris.\n",
     	"ceiling" : "About 10 feet overhead the ceiling looks to be smooth and even.\n",
     	({"armour","armors"}) : "The armor here confirms your worst fear.  The "+
   		"armor is of drow workmanship and stands a silent vigil as if "+
        	"guarding the room.  The armors are old and fused together so "+
        	"that they can stand as if being worn by a drow guard.",
   	"painting" : "The painting is almost surreal.  It has the look of a city, "+
      	"but the city is plunged into utter darkness.  Buildings in the "+
      	"city are carved out of huge stalagmites and out of forests of "+
      	"huge mushrooms.  Very soft lighting appears throughout the "+
      	"cityscape, but surely there is not enough light there for "+
      	"anyone to live in for any amount of time.  You have never seen "+
      	"anything like this, but it has a beautiful, mystical quality "+
      	"about it."
      ]));

   set_search("painting","You find a button behind the painting.\n");

  	set_exits(([
		"southwest" : DROOMS+"cd3"
	]));
}
void init() {
  	::init();
  	add_action("press","press");
}
int press(string str) {
  	if(!str) {
   	tell_object(TP,"Press what?");
      return 1;
   }
  	if(str == "button"){
     	tell_object(TP,"You press the button behind the painting.  A panel opens in "+
     		"the wall to the northeast revealing a hole in the floor. Maybe you can "+
     		"descend into this tunnel if you have the skills, tools, and the courage.\n");
     	tell_room(ETP,""+TPQCN+" reaches behind the painting and suddenly a panel "+
     		"opens up in the northeast revealing a hole into the floor.  Maybe you "+
     		"can descend into this tunnel.\n",TP);

     	set_climb_exits((["descend":({DROOMS+"cdd0",20,6,100})]));
    	set_fall_desc("%^BOLD%^%^RED%^You fall a long way tumbling into the "+
			"darkness bouncing off the sides of the tunnel until you come to a sudden "+
			"and painful stop at the bottom!%^RESET%^\n");

		return 1;
	}
}