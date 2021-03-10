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
You are on a wide, straight cobbled street.  Here the street passes
though an area that appears to be well-travelled, though not crowded. 
On both sides, multi-story buildings placed close together display
colorful awnings over their windows and the doors and shutters are
ornately carved.

To the north, you can see a building with a multi-colored awning and
tables set outside.  On the building is a shingle that serves as a sign.

You can go east, west, or north down the street from here.
VERHEDIN
    );
  set_exits(([
    "east" : VNEW+"acm6",
    "west" : VNEW+"acm4",
    "north" : VNEW+"gm_tavern"
   ]));
  set_listen("default","You hear the sounds of loud socializing to the north.");
  set_smell("default","You detect the scent of incense in the air.");
  set_items( ([
    "shingle" : "This is a sign board with the picture of a grey, snowcapped mountain."
  ]) );
 }

void reset(){
	::reset();
}


