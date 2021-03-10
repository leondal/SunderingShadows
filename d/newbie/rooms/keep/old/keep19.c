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
   "The hallway curves here, running back to the east as well as continuing"+
   " south into an eventual dead end. There are a lot of cobwebs in this corner"+
   " area, but the walls seem in slightly better shape here. The floor still has"+
   " a few mud tracks, but is mostly covered in dust and dirt. Directly south"+
   " of here you can see an opening on the east."
   );
   set_smell("default","The keep is filled with dust.");
   set_listen("default","The wind wails against the outside walls.");
   set_items(([
   ({"walls","stone walls"}) : "The stone walls that make up the keep are"+
   " in okay shape. There are a few cracks running through some blocks,"+
   " but they appear sturdy and mostly keep the wind out.",
   "floor" : "The floor is made of stone bricks and is covered in dirt and mud. The"+
   " mud has been tracked through the hallway by something, but you can't tell what.",
   "ceiling" : "The ceiling is made of carefully squared stone blocks that have"+
   " been fitted together and are supported by beams in some places. The"+
   " beams seem fairly sturdy in this section.",
   ({"beam","beams"}) : "The beams that support the ceiling seem sturdy enough.",
   "mud" : "The mud is mostly in the center of the floor here, and there is not"+
   " much of it, but you still can't make out clear tracks here.",
   ({"dust","dirt"}) : "Dirt and dust cover the floor here.",
   "cobwebs" : "There are several cobwebs here, especially in the corners.",
   ]));
   set_exits(([
   "south" : ROOMS+"keep20",
   "east" : ROOMS+"keep18",
   ]));
}
