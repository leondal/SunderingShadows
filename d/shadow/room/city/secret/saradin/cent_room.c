//Coded by Diego//

#include <std.h>
#include "../secrets.h"

inherit VAULT;

void create(){
	::create();
	set_name("center room");
   set_short("center room");
   set_long(
   	"%^RESET%^%^CYAN%^"+
   	"This room has the look of an office.  There "+
   	"is a large, massive desk which dominates the room.  This "+
   	"room has a door in the east and the west as well as "+
   	"the hallway to the south.  The doors look to "+
   	"be made of %^ORANGE%^solid oak %^CYAN%^with a "+
   	"%^BOLD%^%^BLACK%^iron barred window%^RESET%^%^CYAN%^ "+
   	"in each."+
   	"%^RESET%^\n"
   );
   set_property("indoors",1);
   set_property("light",2);
   set_smell("default","The smell of old sweat is strong here.");
   set_listen("default","The room is quiet save the sounds you make.");
   set_items(([
   	({"desk","massive desk","large desk"}) : "The desk is huge and is very "+
             "used.  It is scratched up.\n"
   ]));
   set_exits(([
		"south" : SARADIN+"hid_hall",
		"east" : SARADIN+"east_cages",
		"west" : SARADIN+"west_cages"
	]));

	set_search("desk","You search the desk, rifle through the "+
		"drawers, and find nothing more than common office supplies.\n");
	set_search("massive desk","You search the desk, rifle through the "+
		"drawers, and find nothing more than common office supplies.\n");


   set_door("east door",SARADIN+"east_cages","east","red key");
   set_door_description("east door","The door is made of solid oak "+
   	"with a barred window.\n");
   set_string("east door","open","The door opens with a creak into "+
   	"an empty room.\n");
   set_locked("east door",0,"lock");

   set_door("west door",SARADIN+"west_cages","west","red key");
   set_door_description("west door","The door is made of solid oak "+
   	"with a barred window.\n");
   set_string("west door","open","The door opens with a creak into "+
   	"an empty room.\n");
   set_locked("west door",0,"lock");
}
