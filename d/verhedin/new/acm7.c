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
colorful, but somewhat faded awnings over their windows and the doors
and shutters are carved.  Looking towards the east, you can see that the
buildings along the street seem to be in less repair than the ones here.
To the west, you can see what looks like a large monument rise above the
street.

You can go east or west down the street from here.
VERHEDIN
    );
  set_exits(([
    "east" : VNEW+"acm8",
    "west" : VNEW+"acm6",
   ]));
  set_listen("default","You hear the sound of wheels on cobblestones to the west.");
  set_smell("default","You detect a hint of incense in the air.");
  set_items( ([
    "monument" : "A tapered, four-sided golden obelisk that   "
	             "rises high into the air.  This monument has "
				 "a crescent at the point.",
  ]) );
}

void reset(){
	::reset();
}
