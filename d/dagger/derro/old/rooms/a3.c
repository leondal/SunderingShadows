#include <std.h>
#include "../derrodefs.h"

inherit ROOM;

void create(){
  ::create();
   set_terrain(MEADOWLANDS);
   set_travel(FOOT_PATH);
  set_property("light",2);
  set_short( "Mountain clearing" );
  set_long(
  "%^BOLD%^Clearing in the mountains. %^RESET%^\n"
  "The mountains close in on you on all sides but through the bushes to the "
  "east you can see a small opening and to the south is the way that you came."
  "  You can see steam drifting from the west which quickly condenses in the cool air leaving the rocks and brush slick in places.\n" );
  set_smell("default",  "You can smell sulfur drifting from the east." );
  set_listen("default", "You can hear something bubbling from the east."  );
  set_items(([
  "brush":"Small patches of scrubby vegetation make passage difficult off the path.",
  "mountains":"Foreboding looking mountains overshadow this little clearing.",
  ]));
  set_exits(([
  "south":ROOMS"a4",
  "east":ROOMS"a6",
  ]));
}
