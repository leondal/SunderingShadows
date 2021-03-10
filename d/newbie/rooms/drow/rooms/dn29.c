#include <std.h>
#include "../drownew.h"

inherit PASSAGE;

void create(){
::create();
  	set_exits(([
		"southwest" : DNROOMS+"dn25",
		"northeast" : DNROOMS+"dn30"
    	]));
	set_door("door",DNROOMS+"dn30","northeast");
    	set_door_description("door","The door is heavily made and is reinforced "+
		"with iron bands.");
   set_locked("door",1);
   lock_difficulty("door",-70,"lock");   	set_string("door","open","You open the door into a dark hallway.\n");

}