//Coded by Diego//
//Mar 27 2001//

#include <std.h>
#include "../jdrow.h"

inherit VAULT;

void create(){
	::create();
   set_name("kitchen");
   set_short("Kitchen");
   set_long(
   	"This is a small room with every bit of the space used for one purpose "+
   	"or another.  There is a small cook stove in the southeast corner of the "+
   	"room.  In the middle of the room is a combination food preparation "+
   	"table, cutting board.  Hanging from the east wall are cooking utensils, "+
   	"knives and meat cleavers.\n"
   );
 	set_terrain(BUILT_CAVE);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",-3);
   set_smell("default","The room smells of cooked food and wood smoke.");
   set_listen("default","The room is quiet.");
   set_items(([
     	"moss" : "Gray and benign it looks as if its only purpose is to "+
     		"cover the floor.\n",
     	({"walls","wall"}) : "The walls are smooth and gray and the stonework "+
     		"looks to be of dwarven quality.\n",
     	"floor" : "Covered with a gray moss the floor is smooth, level, and "+
     		"free of dirt and debris.\n",
     	"ceiling" : "About 10 feet overhead the ceiling looks to be smooth and even.\n",
     	"cook stove" : "This is a small stove, but looks like a large meal could "+
     		"be cooked upon it if planned properly.  No wood can be found to "+
     		"fuel the fire and upon closer examination it is unclear just how "+
     		"the stove is heated.\n",
     	({"table","cutting board"}) : "Looks clean enough to eat off of.\n",
     	({"cooking utensils","knives","cleavers"}) : "Well cleaned before being "+
     		"hung, they have the look of much use.  The knives and cleavers are "+
     		"razor sharp.\n"
   ]));
   set_exits(([
		"west" : DROOMS+"cd6"
   ]));

  	set_door("kitchen door",DROOMS+"cd6","west","obsidian key");
   set_door_description("kitchen door","This is a normal looking wooden door "+
   	"with a simple lock.");
   set_string("kitchen door","open","You open the door into a dark hallway.\n");

}