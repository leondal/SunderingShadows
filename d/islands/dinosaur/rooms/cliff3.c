#include <std.h>
#include "/d/islands/dinosaur/short.h"

inherit ROOM;

void create(){
    ::create();
   set_terrain(ROCKY);
   set_travel(RUTTED_TRACK);
    set_short("%^YELLOW%^Rocky Cliffs");
    set_long(
      "You are on the face of the northern cliffs above the jungle.  From here you can see all out over the jungle, even to the rocky cliffs in the ocean to the south.  To the east in the distance you can barely make out a tower on the cliffs."
    );
    set_listen("default", "from time to time you can hear the call of a strange flying animal.");
    set_items( ([
      "tower" : "You can't make out any details from this vantage point.",
      "ocean" : "The ocean looks very blue from here.",
    ]) );
    set_exits( ([
      "southwest" : RPATH "jung89",
    ]) );
}
