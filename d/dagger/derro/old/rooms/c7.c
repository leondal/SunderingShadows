#include <std.h>
#include "../derrodefs.h"

inherit ROOM;

void create(){
  ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  set_property("no teleport",1);
  set_property("light",2);
  set_property("indoors",1);
  set_short(  "%^RED%^Richly decorated hall%^RESET%^"  );
  set_long(
  "%^RED%^Richly decorated hall.%^RESET%^\n"
  "  This hall is decorated in massive tapestries, statues and other gaudy ornamentation.  There are no globes in the ceiling here with the ever present glow coming from the north."
  "  Numerous corpses of derro litter the floor here."
  "\n"
  );
  set_smell("default", "You get the occasional whiff of the scent of decaying flesh." );
  set_listen("default",
  "You can hear nothing here but the sound of the warm wind as it swirls about."
  );
  set_items(([
  "floor":"The floor looks carved from the bedrock of the mountains.",
  "walls":"Those walls to the east and southwest appear carved while the half of the room to the north appears to be natural formed, rounded and barely worked.",
  "ceiling":"The ceiling here is higher than the rest of the complex, and appears to be natural to the north and carved from the bedrock further to the east and southwest.",
  "tapestries":"These are mismatched pieces looted from many places, with elven works hanging next to those of humans. They're all dirty and ill cared for.",
  "statues":"Chipped and cracked these are pieces picked without thought to how they appear down here just to have them was enough for the being who put them here.",
  "corpses":"Hacked and mutilated with massive strokes.  None of them looked like they took more than one hit each to die, although that one hit often turned one Derro into two. They appear to have been running from the south trying to escape something.",
  ]));
  set_exits(([
  "north":ROOMS"c6",
  "southwest":ROOMS"c8",
  "east":ROOMS"c11"
  ]));
}
