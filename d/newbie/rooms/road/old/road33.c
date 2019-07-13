//road33.c

#include <std.h>
#include "../../newbie.h"

inherit ROOM;

void create(){
   ::create();
   set_property("light",2);
   set_property("no teleport",1);
   set_terrain(SCRUB_LANDS);
   set_travel(PAVED_ROAD);
   set_short("A wide gravel trail");
   set_long(
@NEWBIE
You are on a wide trail passing across mostly open land. You can
see a forest off in the distance to the north. The gravel trail is
thin over the hard-packed dirt. To the east, small rolling hills
can be seen.
NEWBIE
   );
   set_smell("default","You smell the fresh air of the open land.");
   set_listen("default","You hear the sound of the wind rushing across the open land.");
   set_exits(([
      "northwest":ROAD"road34",
      "east":ROAD"road32",
   ]));
}





