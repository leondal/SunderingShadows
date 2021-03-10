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
   " the chill wind through. The floor is covered in dust and caked with mud, almost"+
   " as though a small army has marched through here. Cobwebs are scattered about along"+
   " the walls. The hallway continues to the west and east. Ahead to the east you can"+
   " see a door on the south side of the passage, back to the west is the intersection"+
   " with the main hallway of the keep."
   );
   set_smell("default","The keep is filled with mud.");
   set_listen("default","The ceiling beams creak and moan with the wind.");
   set_items(([
   ({"walls","stone walls"}) : "The stone walls that make up the keep are"+
   " in a bit worse shape. There are several large cracks running through blocks,"+
   " and a few missing ones that let the chill wind cut right through.",
   "floor" : "The floor is made of stone bricks and is covered in dirt and mud. The"+
   " mud almost completely covers the floor, but there is so much you can't make out"+
   " any clear tracks.",
   "ceiling" : "The ceiling is made of carefully squared stone blocks that have"+
   " been fitted together and are supported by beams in some places. The"+
   " beams creak a bit and don't seem completely sturdy.",
   ({"beam","beams"}) : "The beams that support the ceiling above you tend"+
   " to creak and don't seem totally stable.",
   "mud" : "The mud completely covers the floor, almost as though a small army marched"+
   " through here recently.",
   "cobwebs" : "There are a few cobwebs in places along the walls.",
   ]));
   set_exits(([
   "west" : ROOMS+"keep14",
   "east" : ROOMS+"keep25",
   ]));
}
