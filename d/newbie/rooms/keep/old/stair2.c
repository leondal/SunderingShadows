#include <std.h>
#include "keep.h"
inherit ROOM;

void create()
{
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_short("Stairway of a Ruined Keep");
   set_long(
   "You are standing at the top of a set of stairs that lead down to the first"+
   " floor of the keep. The stairs themselves are very dusty, but are in good"+
   " condition. You notice quite a few spider webs near the ceiling here, but"+
   " that seems to be it for the life signs up here. To the east you see what"+
   " appear to be guard barracks."
   );
   set_smell("default","The keep is filled with dust.");
   set_listen("default","Everything is fairly quiet here.");
   set_items(([
   ({"stairs","steps"}) : "The stone stairs leading down to the first floor of"+
   " the keep are in fairly good condition, they're just dusty and obviously"+
   " haven't been used much if at all since the keep came to be in ruins.",
   "cobwebs" : "There are several cobwebs in the corners along the ceiling.",
   "ceiling" : "The ceiling seems sturdy enough, despite being filled with"+
   " cobwebs.",
   ]));
   set_exits(([
   "east" : ROOMS+"floor1",
   "down" : ROOMS+"stair1",
   ]));
}

void reset()
{
   ::reset();
   if(!random(2) && !present("spider")) {
      new(MONS+"spider")->move(TO);
   }
}
