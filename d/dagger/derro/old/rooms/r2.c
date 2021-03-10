#include <std.h>
#include "../derrodefs.h"

inherit ROOM;

void create(){
  ::create();
   set_terrain(NEW_MOUNTS);
   set_travel(RUTTED_TRACK);
  set_property("light",2);
  set_short( "Shadowy path" );
  set_long(
  "Shadowy path.\n"
  "  %^CYAN%^You've left the dense forest far behind you to the southeast."
  "  Smaller scrub bushes surround the path and their brambles make it harder to move through them."
  "  The rocky flanks of Mt Krakus loom above you here and block the rest of the mountain to the north."
  "  The path leads north up to the mountain and back down to the dense forest to the southeast."
  "\n"
  );
  set_smell("default",
  "You can smell the fresh scent of pines and mountain air."
  );
  set_listen("default",
   "The wind is deadened by the rocks."
  );
  set_items(([
  "trees":"They start to thin to more scrubby types to the northwest.",
  ({"mountain", "Mt. Krakus", "krakus", "Krakus"}):"Mt. Krakus over shadows you even hidden in these trees and you can wonder of the evil that lies under it.",
  "path":"It looks like someone has taken pains to make sure it wasn't too obvious to the casual observer.",
  ]));
  set_exits(([
  "southeast":ROOMS"r3",
  "north":ROOMS"r1",
  ]));
}
