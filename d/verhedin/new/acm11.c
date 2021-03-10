// Avenue of the Crescent Moon, Verhedin
// Thorn@ShadowGate
// 001027
// New City, Verhedin

#include <std.h>
#include "/d/tsarven/include/southern.h"
#include "/d/verhedin/include/city.h"

inherit ROOM;

void create() {
  room::create();
  set_light(2);
  set_short("%^BOLD%^Avenue of the Crescent Moon, Verhedin%^RESET%^");
  set_long(
@VERHEDIN
%^BOLD%^Avenue of the Crescent Moon, Verhedin%^RESET%^
You are on a wide, straight cobbled street.  On both sides of the
street, multi-story buildings placed close together display faded and
moth-eaten awnings above their windows.  The buildings appear dingy and
dirty, and seem to be in all around bad shape generally.  Many of the
buildings seem to be abandoned in this area and sit dark and windowless
in the background.

You can go east or west down the street from here.
VERHEDIN
    );
  set_exits(([
    "south" : VNEW+"aband1",
    "east" : VNEW+"acm12",
    "west" : VNEW+"acm10"
   ]));
  set_invis_exits( ({ "south" }) );
  set_listen("default","You hear the occasional crying of a child from one building or another.");
  set_smell("default","There is a mixture of a number of unsavory smells in the air.");
  set_items( ([
    "abandoned store" : "To the south, you see an open entrance into an "
	                    "abandoned store that you missed on first glance."
  ]) );
}

void reset(){
	::reset();
}
