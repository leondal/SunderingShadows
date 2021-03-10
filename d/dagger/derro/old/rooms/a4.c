#include <std.h>
#include "../derrodefs.h"

inherit ROOM;

void create(){
  ::create();
   set_terrain(MEADOWLANDS);
   set_travel(FOOT_PATH);
  set_property("light",2);
  set_short( "Clearing in the mountains" );
  set_long(
  "%^BOLD%^Clearing in the mountains. %^RESET%^\n"+
  " This clearing continues to all sides.   The mountains loom overhead but you get a strange sense of calm from the northeast.\n" );
  set_smell("default", "A faint hint of sulfur hangs over the area." );
  set_listen("default", "You can hear a faint popping noise to the northeast." );
  set_items(([
  "brush":"Small patches of scrubby vegetation make passage difficult off the path.",
  "mountains":"Foreboding looking mountains overshadow this little clearing.",
  ]));
  set_exits(([
  "west":ROOMS+"a2",
  "north":ROOMS+"a3",
  "south":ROOMS+"a5",
  "east":ROOMS"a7",
  ]));
}
