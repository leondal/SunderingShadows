//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit VAULT;

void create(){
	::create();
   set_name("dining room");
   set_short("Dining Room");
   set_long(
   	"This looks to be an area where meals are served and while clean it "+
    	"look like it gets little use.  A long oak table dominates the center of "+
    	"the room with eight chairs set around it, three to a side and one at each end."
   );
 	set_terrain(BUILT_CAVE);
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
     	({"table","chair","chairs"}) : "The table and chairs are made of oak.  "+
   		"The furniture is of good quality yet simple workmanship.\n"
	]));
   set_exits(([
		"north" : DROOMS+"cd5",
		"east" : DROOMS+"cd8"
   ]));

   set_door("dining room door",DROOMS+"cd5","north","obsidian key");
   set_door_description("dining room door","This is a normal looking wooden door "+
   	"with a simple lock.");
   set_string("dining room door","open","You open the door into a dark room.\n");

  	set_door("kitchen door",DROOMS+"cd8","east","obsidian key");
   set_locked("kitchen door",0,"lock");
   	(DROOMS+"cd8")->set_locked("kitchen door",0,"lock");
   set_door_description("kitchen door","This is a normal looking wooden door with a "+
   	"simple lock.");
   set_string("kitchen door","open","You open the door into a dark room.\n");

}