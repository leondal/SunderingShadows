//road26.c

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
You are at the crossroads of two trails crossing the land. Along the
trail to the north, you see a large forest. The land levels out and
becomes clearer to the west, while to the east you see gently rolling
hills.
NEWBIE
   );
   set_smell("default","You smell the fresh air of the open land.");
   set_listen("default","You hear the sound of the wind rushing across the open land.");
   set_exits(([
      "west":ROAD"road28",
      "east":ROAD"road26",
      "north":ROAD"sfroad1",
      "south":ROADOUT"mtnroad1",
   ]));
}





