#include <std.h>
#include "/d/islands/dinosaur/short.h"

inherit ROOM;

void create(){
    ::create();
   set_terrain(ROCKY);
   set_travel(RUTTED_TRACK);
    set_short("%^YELLOW%^Rocky Cliffs");
    set_long(
      "You are on the face of the northern cliffs above the jungle of the dinosaurs.  From here you can peer out above the jungle, barely able to make out the cliffs towering above the ocean to the south end of the jungle.  Just before you, not far to the east a great tower stands looking over the jungle, a strange mist surrounding it.  You feel an eerie and evil presence within it."
    );
    set_listen("default", "from time to time you can hear the call of a strange flying animal.");
    set_items( ([
      "tower" : "You can't make out any details from this vantage point.",
      "ocean" : "The ocean looks very blue from here.",
    ]) );
    set_exits( ([
      "west" : RPATH "cliff16",
      "tower" : TOWER "entergate.c",
    ]) );
}
