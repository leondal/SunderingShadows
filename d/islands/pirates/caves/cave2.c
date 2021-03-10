#include <std.h>
#include "../piratedefs.h"
inherit ROOM;

void create(){
   ::create();
   set_property("indoors",1);
   set_property("light",0);
   set_terrain(NAT_CAVE);
   set_travel(RUBBLE);
   set_name("Caverns");
   set_short("Caverns");
   set_long("%^BOLD%^A Cavern%^RESET%^\n"
"You've descended into a cavern.  The darkness closes in on you.  It is cool down here.  The stalagmites "
"jutting up from the floor are more massive than in the upper caves.  The stalactites are also larger and "
"more menacing.  You have two choices from here: continue descending by following the northeast path, or you "
"can climb back to the cavern entrance.\n");
   set_smell("default","It smells dank and wet.");
   set_listen("default","You can hear water dripping.");

   set_items(([
     "floor":"You can see signs of passage here, it follows a meandering path through the cavern.",
     "stalagmites":"These are old and large although the smaller ones on the path have been bashed down.",
     "stalactites":"These hang menacingly from the ceiling.",
   ]));

   set_exits(([
     "up":CAVES"cave1",
     "northeast":CAVES"cave3"
   ]));
}

void init(){
   ::init();
   do_random_encounters(({MON"piercer"}),40,6);
}
