//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit DHALL;

void create(){
	::create();
   set_exits(([
		"west" : DROOMS+"cdd1",
		"east" : DROOMS+"cdd3",
		"south" : DROOMS+"cbed2"
   ]));

   set_door("door",DROOMS+"cbed2","south","obsidian key");
   set_locked("door",0,"lock");
   	(DROOMS+"cbed2")->set_locked("door",0,"lock");
   set_door_description("door","The door is a normal looking door made from oak "+
   	"with a simple lock.");
   set_string("door","open","You open the door into a dark room.\n");

}