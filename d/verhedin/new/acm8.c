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
street, multi-story buildings placed close together display colorful,
but faded awnings above their windows.  The buildings appear plain, but
in good repair otherwise.  However to the east, the buildings are not so
well off and you feel that you are on the edge of a poorer section of
town.

You can go east or west down the street from here.
VERHEDIN
    );
  set_exits(([
    "east" : VNEW+"acm9",
    "west" : VNEW+"acm7"
   ]));
  set_listen("default","You hear the the muffled sound of activity to the west.");
  set_smell("default","The air here is not scented, but not totally repugnant.");
 }

void reset(){
	::reset();
}
