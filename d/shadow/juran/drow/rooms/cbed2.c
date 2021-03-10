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
   	"This room is for favored guests.  The bed is large and is covered "+
   	"with satin and silks to provide nothing less than the best comforts "+
   	"for the guest that stays here.  Two chairs are, also, set in this room "+
   	"with a small table between them.  A chest is set at the foot of the bed."+
   	"%^RESET%^"
   );
  	set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
 	set_property("indoors",1);
   set_property("light",-3);
   set_smell("default","The room smells clean and dry.");
   set_listen("default","You hear very little save the noises you make yourself.");
   set_items(([
     	"moss" : "Gray and benign it looks as if its only purpose is to "+
     		"cover the floor.\n",
     	({"walls","wall"}) : "The walls are smooth and gray and the stonework "+
     		"looks to be of dwarven quality.\n",
     	"floor" : "Covered with a gray moss the floor is smooth, level, and "+
     		"free of dirt and debris.\n",
     	"ceiling" : "About 10 feet overhead the ceiling looks to be smooth and even.\n",
     	"bed" : "The bed is very large and could accommodate more than one "+
     		"person if required or desired.  It is covered with satin and fine "+
     		"silks to make the guest's time in this room as pleasant as "+
     		"possible.\n",
     	({"chairs","chair"}) : "Two chairs are set on either side of a small "+
     		"table.  The furniture is of very good workmanship, but of a simple "+
			"nature.\n",
		"chest" : "The chest is routinely what you would expect to hold extra "+
			"blankets and sheets for the guest.\n"
	]));
   set_exits(([
		"north" : DROOMS+"cdd2"
   ]));

   set_door("door",DROOMS+"cdd2","south","obsidian key");
   set_door_description("door","This is a normal looking wooden door "+
   	"with a simple lock.");
   set_string("door","open","You open the door into a dark hallway.\n");
}