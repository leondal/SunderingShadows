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
   "You are traveling down the hallway of a ruined keep. The walls are in fairly"+
   " good shape here. The floor still has a few mud tracks that are a little"+
   " clearer here, but is still mostly covered in dust and dirt. Directly south"+
   " you see a door to the east, but the rest of the hallway appears to have been"+
   " blocked by the ceiling collapsing. To the north the hallway continues,"+
   " curving back to the east."
   );
   set_smell("default","The keep is filled with dust.");
   set_listen("default","The wind wails against the outside walls.");
   set_items(([
   ({"walls","stone walls"}) : "The stone walls that make up the keep are"+
   " in okay shape. There are a few cracks running through some blocks,"+
   " but they appear sturdy and mostly keep the wind out.",
   "floor" : "The floor is made of stone bricks and is covered in dirt and mud. The"+
   " mud has obviously been tracked through here by someone.",
   "ceiling" : "The ceiling is made of carefully squared stone blocks that have"+
   " been fitted together and are supported by beams in some places. The"+
   " beams seem fairly sturdy in this section.",
   ({"beam","beams"}) : "The beams that support the ceiling seem sturdy enough.",
   "mud" : "The mud is mostly in the center of the floor here, and there is not"+
   " much of it. There are clear tracks here, indicating a very large humanoid.",
   "tracks" : "Clear tracks have been left in the hallway by a very large"+
   " creature wearing muddy boots. Unless whoever it is has unproportionately"+
   " large feet, they are probably over nine feet tall.",
   ({"dust","dirt"}) : "Dirt and dust cover the floor here.",
   "cobwebs" : "There are several cobwebs along the walls here.",
   ]));
   set_exits(([
   "south" : ROOMS+"keep22",
   "north" : ROOMS+"keep20",
   ]));
}

void reset()
{
   ::reset();
   if(!random(3)) return;
   if(!present("spider") && !present("rat")) {
      switch(random(15)) {
         case 0..7:
            new(MONS+"spider")->move(TO);
            break;
         case 8..10:
            new(MONS+"rat")->move(TO);
            break;
         case 11..13:
            new(MONS+"rat")->move(TO);
            new(MONS+"rat")->move(TO);
            break;
         case 14:
            new(MONS+"rat")->move(TO);
            new(MONS+"rat")->move(TO);
            new(MONS+"rat")->move(TO);
            break;
      }
   }
}
