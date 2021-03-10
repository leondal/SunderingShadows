//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit VAULT;

void create(){
 	::create();
   set_name("guest bedroom");
   set_short("Guest Bedroom");
   set_long(
   	"%^CYAN%^"+
   	"The room is a bedroom for guests, but it really nothing spectacular.  "+
   	"The bed is a little stiff and the room is not very big, but it would "+
   	"serve as a place of rest if someone needed it.  The room while Spartan "+
   	"is clean and fresh."+
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
     	"floor" : "Covered with a gray moss the floor is smooth, level, and free "+
     		"of dirt and debris.\n",
     	"ceiling" : "About 10 feet overhead the ceiling looks to be smooth and even.\n",
     	"bed" : "The bed is not much more than a cot, but has warm bedding and "+
     		"would serve well enough for sleep.\n"
   ]));
   set_exits(([
		"south" : DROOMS+"cdd1"
   ]));

   set_door("door",DROOMS+"cdd1","south","obsidian key");
   set_door_description("door","This is a normal looking wooden door "+
   	"with a simple lock.");
   set_string("door","open","You open the door into a dark hallway.\n");

}