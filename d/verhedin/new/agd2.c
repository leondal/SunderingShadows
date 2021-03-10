// Avenue of the Golden Dawn, Verhedin
// Thorn@ShadowGate
// 010117
// New City, Verhedin

#include <std.h>
#include "/d/tsarven/include/southern.h"
#include "/d/verhedin/include/city.h"

inherit ROOM;

void create() {
  room::create();
  set_light(2);
  set_short("%^BOLD%^YELLOW%^Avenue of the Golden Dawn, Verhedin%^RESET%^");
  set_long(
@VERHEDIN
%^BOLD%^YELLOW%^Avenue of the Golden Dawn, Verhedin%^RESET%^
You are on a wide cobbled street.  Here the street passes though an area 
that appears to be quiet and residential.  On both sides, multi-story 
homes built close together display colorful awnings over their windows 
and the doors and shutters are ornately carved.  Some of the upper 
levels have wooden screens over them in a manner often found farther to 
the south.

To the southeast, well beyond the roofs of the houses, you can make out 
the upper walls of a gigantic, solid-looking fortress.  

You can go east or northwest down the street from here.
VERHEDIN
    );
  set_exits(([
    "east" : VNEW+"agd3",
    "northwest" : VNEW+"agd1"
   ]));
  set_listen("default","You hear the muted sounds of a busy city.");
  set_smell("default","You pick up the smells of a nearby river.");
  set_items( ([
    "fortress" : "All you can see from this distance are the crenellations on the "
                 "roof and its sheer mass."
  ]) );
}

void reset(){
	::reset();
}
