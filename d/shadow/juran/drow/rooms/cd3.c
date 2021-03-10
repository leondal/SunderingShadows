//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit DHALL;

void create(){
 	::create();
   set_exits(([
		"northeast" : DROOMS+"cd4",
		"southwest" : DROOMS+"cd2",
		"southeast" : DROOMS+"cd5"
   ]));

	set_door("door",DROOMS+"cd5","southeast","obsidian key");
   set_locked("door",0,"lock");
   (DROOMS+"cd5")->set_locked("door",0,"lock");
  	set_door_description("door","This is a normal looking wooden door with a "+
   	"simple lock.");
  	set_string("door","open","You open the door into a dark room.\n");
}