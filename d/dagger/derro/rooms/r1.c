#include <std.h>
#include "../derrodefs.h"

inherit ROOM;

void create(){
  ::create();
   set_terrain(NEW_MOUNTS);
   set_travel(RUTTED_TRACK);
  set_property("light",2);
  set_short("Shadowy path" );
  set_long(
  "Shadowy path.\n"
  "  %^CYAN%^Great rock walls tower above you here with a thin sliver of horizon visible to the south where you came from."
  "  Smaller scrub bushes surround the path and their brambles make it harder to move through them."
  "  The rocky flanks of Mt Krakus loom above you here and block the rest of the mountain to the north."
  "  The path narrows through dense thickets to the northeast and leads back to the path down the slope to the south."
  "\n"
  );
  set_smell("default",
  "The smell of pine lingers and you start to sense a hint of something else."
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
  "south":ROOMS"r2",
  "northeast":ROOMS"a2",
  ]));
}
