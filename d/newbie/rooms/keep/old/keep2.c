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
   "You are traveling down the hallway of a ruined keep. There are large"+
   " gaps in the walls from missing stone blocks, letting the chill wind"+
   " cut through the halls. %^GREEN%^Moss%^RESET%^ covers most of the"+
   " walls and extends down to sections of the floor, making walking"+
   " rather treacherous in places. Mud also covers the floor, it's probably"+
   " a mixture of the dust that's settled here with the water from the"+
   " leaking ceiling. Obviously no one takes care of this place. To the west"+
   " the hallway continues, to the east is the entrance of the keep."
   );
   set_smell("default","The keep is filled with a damp, dank smell.");
   set_listen("default","The scrabbling of tiny claws on stone echoes faintly.");
   set_items(([
   ({"walls","stone walls"}) : "The stone walls that make up the keep are"+
   " in pretty bad shape. There are blocks missing in some places, others"+
   " are cracked, and %^GREEN%^moss%^RESET%^ is growing over large sections."+
   " They do nothing to stop the chill wind from reaching the inner part"+
   " of the keep now.",
   "floor" : "The floor is made of stone bricks and is quite dirty. Mud and"+
   " %^GREEN%^moss%^RESET%^ hide most of it and make it slipper to walk on.",
   "ceiling" : "The ceiling is made of carefully squared stone blocks that have"+
   " been fitted together and are supported by beams in some places. The"+
   " beams have started to decay in some parts, and you don't get the"+
   " feeling that it is all too secure. One big earthquake might bring it"+
   " crashing down on your head.",
   "moss" : "%^GREEN%^Moss grows along most of the walls and has reached"+
   " down to cover parts of the floor as well. It is green and looks rather"+
   " slimy, making footing treacherous in some places.",
   "mud" : "The mud almost totally covers the floor. It's probably a mixture"+
   " of the settled dust with the water that appears to have leaked in"+
   " from the ceiling that is in rather bad shape.",
   ]));
   set_exits(([
   "west" : ROOMS+"keep3",
   "east" : ROOMS+"keep1",
   ]));
}

