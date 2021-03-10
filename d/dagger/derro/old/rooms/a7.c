#include <std.h>
#include "../derrodefs.h"

inherit ROOM;

void create(){
  ::create();
   set_terrain(MEADOWLANDS);
   set_travel(FOOT_PATH);
  set_property("light",2);
  set_short( "Clearing in the mountains." );
  set_long(
  "%^BOLD%^Clearing in the mountains.%^RESET%^ \n"+
  "  The clearing continues to the north and the west.  The mountains overshadow everything in this valley."
  "  The rocks and scrub trees glisten with moisture to the north.\n" );
  set_smell("default", "You can faintly smell sulfur."  );
  set_listen("default", "A faint bubbling comes from the north" );
  set_items(([
  "rocks":"The grey rock is drab and depressing.  There is a thin sheen of water on the rocks to the north.",
  ({"brush", "scrub"}):"Small mountain scrub bushes.   They cling to the rocks "
     "and crack them with their roots.",
  ]));
  set_exits(([
  "north":ROOMS+"a6",
  "west":ROOMS+"a4",
  ]));
}
