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
    	"You are now very deep within the earth.  Light from the surface is only "+
    	"a distant memory and the familiar noises of the surface are a thing of "+
    	"the past.  The stonework here continues to have look of dwarven "+
    	"workmanship and any traces of a light sources are still non-existent.  "+
    	"The walls are smooth and the floor is free from dust and debris. The "+
    	"floor is covered completely with a gray moss-like substance that is both "+
    	"soft and springy.  The moss comforts your feet while walking and absorbs "+
    	"much of the sound in the room.  You see a hole in the ceiling, which "+
    	"leads to somewhere above, and the hallway continues to the southeast.  "+
    	"You see a hole in the ceiling to the northeast.\n"+
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
      	"out if you had the skill or the tools.\n"
   ]));

   set_exits(([
		"southeast" : DROOMS+"cdd1"
	]));

   set_climb_exits((["climb":({DROOMS+"cd4",20,6,100})]));
   set_fall_desc("%^BOLD%^%^RED%^You fall a long way tumbling into the "+
		"darkness bouncing off the sides of the tunnel until you come to a sudden "+
		"and painful stop at the bottom!%^RESET%^\n");

}