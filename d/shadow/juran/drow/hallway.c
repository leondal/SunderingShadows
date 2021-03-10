//Coded by Diego//

#include <std.h>
#include "jdrow.h"

inherit VAULT;

void create(){
::create();
	set_name("hallway");
	set_short("Hallway");
   set_long(
   	"%^BOLD%^%^BLUE%^"+
   	"This area has signs of habitation.  The stonework "+
   	"has the definite look of dwarven workmanship, but where you would see "+
   	"sconces and other places to hold light sources they are curiously "+
   	"absent.  The walls are smooth and the floor is free from dust and "+
   	"debris. The floor is covered completely with a gray moss-like substance "+
   	"that is both soft and springy.  The moss comforts your feet while walking "+
   	"and absorbs much of the sound in the room.\n"+
   	"%^RESET%^"
   );
  	set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
 	set_property("indoors",1);
   set_property("light",-3);
   set_smell("default","The room smells clean and dry.");
   set_listen("default","You hear very little save the noises you make yourself.");
   set_items(([
   	"moss" : "Gray and benign it looks as if its only purpose is to cover "+
      	"the floor.\n",
      ({"walls","wall"}) : "The walls are smooth and gray and the stonework "+
      	"looks to be of dwarven quality.\n",
      "floor" : "Covered with a gray moss the floor is smooth, level, and "+
        	"free of dirt and debris.\n",
      "ceiling" : "About 10 feet overhead the ceiling looks to be smooth and even.\n"
   ]));
}