#include <std.h>
#include "../drownew.h"

inherit PASSAGE;

void create(){
::create();
   set_exits(([
      "west" : DNROOMS+"dn3",
      "southeast" : DNROOMS+"dn5"
   ]));
   set_door("door",DNROOMS+"dn3","west");
   set_door_description("door","The door is heavily made and is reinforced "+
      "with iron bands.");
   set_locked("door",1);
   lock_difficulty("door",-70,"lock");  	
   set_string("door","open","The door opens into a dark hallway.\n");

}
