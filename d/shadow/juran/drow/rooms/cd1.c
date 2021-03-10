//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit DHALL;

void create(){
   ::create();
   set_exits(([
		"east" : DROOMS+"cd2",
		"west" : DROOMS+"cd0"
   ]));

   set_door("door",DROOMS+"cd0","west","obsidian key");
   set_door_description("door","Sturdy and heavy this door is made of oak and "+
   	"ironbound.  It looks like it could take quite a beating and yet still "+
    	"remain standing. The door is locked and you can make out a keyhole under "+
    	"the handle.");
   set_string("door","open","You open the door into a dark hallway.\n");
}