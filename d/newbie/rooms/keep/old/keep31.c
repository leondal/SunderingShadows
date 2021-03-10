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
   " To the south the hallway continues and you can see a door on the western side,"+
   " to the north the hallway continues and quickly turns to the west."
   );
   set_smell("default","The faint scent of urine is blown in by the breeze.");
   set_listen("default","The ceiling beams creak and moan with the wind.");
   set_items(([
   "floor" : "The floor is made of square stone blocks that have been carefully"+
   " fitted together. There is a lot of dust and dirt, you doubt this hallway gets"+
   " much use anymore.",
   ({"wall","walls"}) : "The eastern wall is in the worst shape, with many large cracks"+
   " and a few missing blocks in places, allowing the chill wind to come right in. The"+
   " west wall seems a bit more sturdy.",
   "ceiling" : "The ceiling is made of carefully squared stone blocks that have"+
   " been fitted together and are supported by beams in some places. The"+
   " beams creak a bit and don't seem completely sturdy.",
   ({"beam","beams"}) : "The beams that support the ceiling above you tend"+
   " to creak and don't seem totally stable.",
   ({"dust","dirt"}) : "Dirt and dust cover the floor here.",
   ]));
   set_exits(([
   "north" : ROOMS+"keep30",
   "south" : ROOMS+"keep32",
   ]));
}
