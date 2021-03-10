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
   set_short("Dead End of a Ruined Keep");
   set_long(
   "You have come to the end of the hallway, for the roof has caved in"+
   " to the west and collapsed the passage. Many heavy stones have"+
   " piled here and there are far too many to attempt to move. The trail of"+
   " debris extends all around you and into the hallway to the north."
   );
   set_smell("default","There is an unpleasant smell coming from somewhere.");
   set_listen("default","The ceiling beams creak and moan with the wind.");
   set_items(([
   "floor" : "The floor is made of square stone blocks that have been carefully"+
   " fitted together. There is a lot of dust and dirt, you doubt this hallway gets"+
   " much use anymore.",
   ({"wall","walls"}) : "The walls are holding up alright, considering that the"+
   " ceiling collapsed not far from here. There are a few cracks but no real holes"+
   " here.",
   "ceiling" : "The ceiling is made of carefully squared stone blocks that have"+
   " been fitted together and are supported by beams in some places. The"+
   " beams creak a bit and don't seem completely sturdy. You can tell that the ceiling"+
   " collapsed further down the passage and the debris from that appears to have"+
   " tumbled into this room.",
   ({"beam","beams"}) : "The beams that support the ceiling above you tend"+
   " to creak and don't seem totally stable.",
   ({"dust","dirt"}) : "Dirt and dust cover the floor here.",
   "debris" : "There is a large pile of debris here that appears to be blocking the"+
   " northern hallway. It is mostly smaller sections of the stone blocks and some of"+
   " the ceiling's support beams, you might be able to %^BOLD%^dig north%^RESET%^"+
   " if you want to get out. To the west the stones are much too large for you to even"+
   " attempt to move.",
   ]));
   set_exits(([
   "north" : ROOMS+"keep33",
   ]));
   find_object_or_load("/d/newbie/rooms/keep/keep34");
   TO->collapse_exit("north");
}

void reset()
{
   ::reset();
   TO->collapse_exit("north");
   if(!present("carrion crawler")) {
      new(MONS+"carrion")->move(TO);
   }
}
