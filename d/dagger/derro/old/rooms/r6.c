#include <std.h>
#include "../derrodefs.h"

inherit ROOM;

void create(){
  ::create();
   set_terrain(HEAVY_FOREST);
   set_travel(FOOT_PATH);
  set_property("light",2);
  set_short( "Path through the dense forest" );
  set_long(
  "Path through the dense forest.\n"
  "  %^CYAN%^The forest closes in on all sides of this forest path."
  "  To the north Mt Krakus rises barely seen through the tops of the trees."
  "  The path continues east and west through the woods."
  "\n"
  );
  set_smell("default",
  "You can smell the fresh scent of pines and mountain air."
  );
  set_listen("default",
  "The wind whistles through the trees."
  );
  set_items(([
  "trees":"Tall evergreens closes in on the path from all sides",
  ({"mountain", "Mt. Krakus", "krakus", "Krakus"}):"Mt. Krakus over shadows you even hidden in these trees and you can wonder of the evil that lies under it.",
  "path":"It looks like someone has taken pains to make sure it wasn't too obvious to the casual observer.",
  ]));
  set_exits(([
  "east":ROOMS"r7",
  "west":ROOMS"r5",
  ]));
}
