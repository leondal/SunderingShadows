//Coded by Diego//

#include <std.h>
#include "../secrets.h"

inherit VAULT;

void create(){
	::create();
	set_name("west cage room");
   set_short("west cage room");
   set_long(
   	"%^BOLD%^%^BLACK%^"+
   	"This room is nothing more than a rectangular room with scuff "+
   	"marks and scratches in the stone floor.%^RESET%^\n"
   );
   set_property("indoors",1);
   set_property("light",2);
   set_smell("default","You smell the sweat and fear of the slaves.");
   set_smell("default","You smell old sweat.");
   set_listen("default","The room is quiet save for the sounds you make.");
   set_items(([
		({"scuff marks","scratches","marks"}) : "The marks "+
			"appear to be caused by something large that was dragged "+
			"along the floor, maybe several somethings.  "+
			"The seem relatively new.\n"
  	]));
   set_exits(([
		"east" : SARADIN+"cent_room"
	]));

  	set_door("west door",SARADIN+"cent_room","east","red key");
   set_door_description("west door","The door is made of solid oak "+
   	"with a barred window.\n");
   set_string("west door","open","The door opens with a creak into "+
   	"a room that looks like an office.\n");

}