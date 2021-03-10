#include <std.h>
#include "keep.h"
inherit ROOM;

void create()
{
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
   set_property("indoors",1);
   set_property("light",1);
   set_short("Stairway of a Ruined Keep");
   set_long(
   "You are standing at the bottom of a set of stairs that lead up onto the"+
   " second floor of the keep. The stairs are in surprisingly good condition,"+
   " despite being a bit dusty. It's hard to tell from here what might be on"+
   " the second floor. The hallway is back to the west."
   );
   set_smell("default","The keep is filled with dust.");
   set_listen("default","Everything is fairly quiet here.");
   set_items(([
   ({"stairs","steps"}) : "The stone stairs leading up to the second floor of"+
   " the keep are in fairly good condition, they're just dusty and obviously"+
   " haven't been used much if at all since the keep came to be in ruins.",
   ]));
   set_exits(([
   "west" : ROOMS+"keep20",
   "up" : ROOMS+"stair2",
   ]));
}

void reset()
{
   ::reset();
   if(!random(4) && !present("spider")) {
      new(MONS+"spider")->move(TO);
   }
}
