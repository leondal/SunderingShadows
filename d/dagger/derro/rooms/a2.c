#include <std.h>
#include "../derrodefs.h"

inherit ROOM;

void create(){
  ::create();
   set_terrain(MEADOWLANDS);
   set_travel(FOOT_PATH);
  set_property("light",2);
  set_short( "Path through the mountains"  );
  set_long(
  "%^BOLD%^Clearing in the mountains. %^RESET%^\n"+
  " This clearing leads off the main path and is surrounded on all sides by "
  "mountains and bushes that seem to close in on you when you take your eyes "
  "off them." );
  set_smell("default",
    "You can feel moisture in the air and the far off scent of sulfur." );
  set_listen("default", "The wind whistles through the mountains." );
  set_items(([
  "bushes":"Small scrubby mountain trees cling to the sides of the mountain "
    "faces that loom into the sky, preventing them from getting the light all "
    "plants need.",
  "mountains":"Foreboding looking mountains overshadow this little clearing.",
  ]));
  set_exits(([
  "east":ROOMS+"a4",
  "southwest":ROOMS"r1",
  "north":ROOMS+"a1"
  ]));
}
