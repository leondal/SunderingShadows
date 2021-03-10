//r4 adding a hidden exit -hades
//7/11/13
#include <std.h>
#include "../derrodefs.h"

inherit ROOM;

void create(){
  ::create();
   set_terrain(LIGHT_FOREST);
   set_travel(FOOT_PATH);
  set_property("light",2);
  set_short( "Path through the dense forest" );
  set_long(
  "Path through the dense forest.\n"
  "  %^CYAN%^The forest closes in on all sides of this forest path."
  "  To the north Mt Krakus rises barely seen through the tops of "+
  "the trees."
  "  The woods start to thin as you climb higher towards the"+
  " mountains edges."
  "  The path leads northwest further up to the mountain"+
  " and back to the dense forest to the southeast."
  "\n"
  );
  set_smell("default",
  "You can smell the fresh scent of pines and mountain air."
  );
  set_listen("default",
  "The wind whistles through the trees."
  );
  set_search("default","The thick trees make you wonder"+
  " what could be hidden behind their trunks.");
  set_search("trees","Searching the trees, you think you"+
  " see a path leading off to the east.");
  set_items(([
  "trees":"They start to thin to more scrubby types to the northwest.",
  ({"mountain", "Mt. Krakus", "krakus", "Krakus"}):"Mt. Krakus over "+
  "shadows you even hidden in these trees and you can wonder of "+
  "the evil that lies under it.",
  "path":"It looks like someone has taken pains to make "+
  "sure it wasn't too obvious to the casual observer.",
  ]));
  set_exits(([
  "southeast":ROOMS"r5",
  "northwest":ROOMS"r3",
  "east":ROOMS"hidden",
  ]));
  set_invis_exits(({"east"}));
}
