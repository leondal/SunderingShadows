//r5.c - updated to include entrance to Shrydelhi's meadow by Circe 9/26/03
#include <std.h>
#include "../derrodefs.h"

inherit ROOM;

void create(){
  ::create();
  set_terrain(HEAVY_FOREST);
  set_travel(FOOT_PATH);
  set_property("light",2);
  set_name("Path through the dense forest");
  set_short("Path through the dense forest");
  set_long(
  "Path through the dense forest.\n"+
  "%^CYAN%^The forest closes in on all sides of this forest path.  "+
  "To the north, Mt. Krakus rises, barely seen through the tops of the trees.  "+
  "The path turns to the northwest and runs back east through the woods.  "+
  "The dense forest seems as though it could be hiding something behind the "+
  "stalwart trunks."+
  "\n"
  );
  set_smell("default","You can smell the fresh scent of pines and mountain air.");
  set_listen("default","The gentle murmuring of a brook rises on the wind.");
  set_items(([
  "trees":"Tall evergreens close in on the path from all sides, making it difficult to see "+
     "if there is anything off the path.",
  ({"mountain", "Mt. Krakus", "krakus", "Krakus"}):"Mt. Krakus overshadows you even hidden "+
     "in these trees, and you wonder of the evil that lies under it.",
  "path":"It looks like someone has taken pains to make sure it wasn't too "+
     "obvious to the casual observer.  A few other half-paths seem to branch off in various directions.",
  ]));
  set_search("default","The thick trees make you wonder what could be hidden behind their trunks.");
  set_search("trees","Searching the trees, you think you see a path leading off to the northeast.");
  set_exits(([
  "east":ROOMS"r6",
  "northwest":ROOMS"r4",
  "northeast":"/d/player_houses/shrydelhi/path1",
  ]));
  set_invis_exits(({"northeast"}));
}
