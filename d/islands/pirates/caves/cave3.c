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
"You have descended further into the huge underground cavern.  It is completely dark here.  The stalagmites "
"jutting up from the floor are more massive than in the upper caves.  The stalactites are also larger and "
"more menacing.  If you head north you will be descending even further into the cavern.  Southwest is the "
"way back to the entrance.\n");
   set_smell("default","It smells dank and wet.");
   set_listen("default","You can hear water dripping.");

   set_items(([
     "floor":"You can see signs of passage here, it follows a meandering path through the cavern.",
     "stalagmites":"These are old and large although the smaller ones on the path have been bashed down.",
     "stalactites":"These hang menacingly from the ceiling.",
   ]));

   set_exits(([
     "southwest":CAVES"cave2",
     "north":CAVES"cave4"
   ]));
}

void init(){
   ::init();
   do_random_encounters(({MON"piercer"}),20,2);
}
