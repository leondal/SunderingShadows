//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit DHALL;

void create(){
   ::create();
   set_exits(([
		"northwest" : DROOMS+"cdd0",
		"north" : DROOMS+"cbed1",
		"east" : DROOMS+"cdd2"
   ]));

  	set_door("door",DROOMS+"cbed1","north","obsidian key");
   set_locked("door",0,"lock");
   	(DROOMS+"cbed1")->set_locked("door",0,"lock");
   set_door_description("door","The door is a normal looking door made from oak "+
   	"with a simple lock.");
   set_string("door","open","You open the door into a dark room.\n");
}