#include <std.h>
#include "keep.h"
inherit VAULT;

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
   " On the west is a slightly rotted and somewhat rusted door. The hallway continues"+
   " to the north and south."
   );
   set_smell("default","There is an unpleasant smell coming from somewhere.");
   set_listen("default","The ceiling beams creak and moan with the wind.");
   set_items(([
   "floor" : "The floor is made of square stone blocks that have been carefully"+
   " fitted together. There is a lot of dust and dirt, you doubt this hallway gets"+
   " much use anymore.",
   ({"wall","walls"}) : "The eastern wall is in the worst shape, with many large cracks"+
   " and a few missing blocks in places, allowing the chill wind to come right in. On"+
   " the west wall there is a door.",
   "ceiling" : "The ceiling is made of carefully squared stone blocks that have"+
   " been fitted together and are supported by beams in some places. The"+
   " beams creak a bit and don't seem completely sturdy.",
   ({"beam","beams"}) : "The beams that support the ceiling above you tend"+
   " to creak and don't seem totally stable.",
   ({"dust","dirt"}) : "Dirt and dust cover the floor here.",
   "door" : "The door appears a bit rotted and rusty, but still servicable.",
   ]));
   set_exits(([
   "north" : ROOMS+"keep31",
   "south" : ROOMS+"keep33",
   "west" : ROOMS+"keep35",
   ]));
   set_door("door",ROOMS+"keep35","west","keep master_key");
}
