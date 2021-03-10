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
   "You are traveling down the hallway of a ruined keep. The walls here are in bad"+
   " shape, with large cracks in some sections and a few missing blocks that let"+
   " the chill wind through. The floor is covered in dust and mud, though a bit"+
   " more dust in this section. Cobwebs are scattered about along the walls. The"+
   " hallway continues to the west and east. To the east is the intersection with"+
   " the main hallway of the keep, to the west you can see the hallway turn back"+
   " to the south."
   );
   set_smell("default","The keep is filled with dust.");
   set_listen("default","The ceiling beams creak and moan with the wind.");
   set_items(([
   ({"walls","stone walls"}) : "The stone walls that make up the keep are"+
   " in a bit worse shape. There are several large cracks running through blocks,"+
   " and a few missing ones that let the chill wind cut right through.",
   "floor" : "The floor is made of stone bricks and is covered in dirt and mud. The"+
   " mud has been tracked through the hallway by something, but you can't tell what.",
   "ceiling" : "The ceiling is made of carefully squared stone blocks that have"+
   " been fitted together and are supported by beams in some places. The"+
   " beams creak a bit and don't seem completely sturdy.",
   ({"beam","beams"}) : "The beams that support the ceiling above you tend"+
   " to creak and don't seem totally stable.",
   "mud" : "The mud doesn't completely cover the floor here, but there is still"+
   " a lot of it, but no clear tracks are discernible.",
   ({"dust","dirt"}) : "Dirt and dust cover the floor here.",
   "cobwebs" : "There are a few cobwebs in places along the walls.",
   ]));
   set_exits(([
   "west" : ROOMS+"keep17",
   "east" : ROOMS+"keep15",
   ]));
}
