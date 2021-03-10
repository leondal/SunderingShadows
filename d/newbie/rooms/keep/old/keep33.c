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
   set_short("Hallway of a Ruined Keep");
   set_long(
   "You are traveling down the hallway of a ruined keep. You can feel the chill"+
   " wind blowing in from the north and through the many cracks in the walls here."+
   " Just north of here there is a door on the west, and the hallway continues"+
   " further, leading back to the mess hall. There is a lot of debris piled here"+
   " from the collapsed ceiling up ahead."
   );
   set_smell("default","There is an unpleasant smell coming from somewhere.");
   set_listen("default","The ceiling beams creak and moan with the wind.");
   set_items(([
   "floor" : "The floor is made of square stone blocks that have been carefully"+
   " fitted together. There is a lot of dust and dirt, you doubt this hallway gets"+
   " much use anymore.",
   ({"wall","walls"}) : "The eastern wall is in the worst shape, with many large cracks"+
   " and a few missing blocks in places, allowing the chill wind to come right in. The"+
   " western wall seems to be holding up a bit better.",
   "ceiling" : "The ceiling is made of carefully squared stone blocks that have"+
   " been fitted together and are supported by beams in some places. The"+
   " beams creak a bit and don't seem completely sturdy. You can tell that the ceiling"+
   " collapsed further down the passage and the debris from that appears to have"+
   " tumbled into this room.",
   ({"beam","beams"}) : "The beams that support the ceiling above you tend"+
   " to creak and don't seem totally stable.",
   ({"dust","dirt"}) : "Dirt and dust cover the floor here.",
   "debris" : "There is a large pile of debris here that appears to be blocking the"+
   " hallway. It is mostly smaller sections of the stone blocks and some of the"+
   " ceiling's support beams, you might be able to %^BOLD%^dig south%^RESET%^"+
   " if you have the time and energy to clear the passage.",
   ]));
   set_exits(([
   "north" : ROOMS+"keep32",
   "south" : ROOMS+"keep34",
   ]));
//   find_object_or_load("/d/newbie/rooms/keep/keep34");
  TO->collapse_exit("south");
}

void reset()
{
   ::reset();
   TO->collapse_exit("south");
}
