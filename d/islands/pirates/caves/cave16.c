#include <std.h>
#include "../piratedefs.h"
inherit ROOM;

void create(){
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_terrain(NAT_CAVE);
   set_travel(RUBBLE);
   set_name("Opening");
   set_short("Opening");
   set_long("%^BOLD%^An Opening%^RESET%^\n"
"You seem to have found an exit out of this blasted maze.  You can smell fresh sea air and feel the warm "
"ocean breeze.  This room is full of stalactites and stalagmites, though they are more eroded and weather-"
"beaten than the others in these caves.  All that is left now is to make you way down to the ocean.\n");
   set_smell("default","It smells of salt water and fresh air.");
   set_listen("default","You can hear the sounds of waves crashing against the shore.");

   set_items(([
     "stalagmites":"These are old and large although the smaller ones on the path have been bashed down.",
     "stalactites":"These hang menacingly from the ceiling.",
   ]));

   set_exits(([
     "down":COVE"path14",
     "northwest":CAVES"cave15"
   ]));
}

void init(){
   ::init();
   do_random_encounters(({MON"piercer"}),50,4);
}
