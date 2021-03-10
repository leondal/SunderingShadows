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
You are on a wide, straight cobbled street that appears to bend here to
allow access to the south and west.  On both sides of the street,
multi-story buildings placed close together display faded and moth-eaten
awnings above their windows.  The buildings appear dingy and dirty, and
seem to be in all around bad shape generally. 

There appears to be a store to the northeast where you can see leather
and some leather goods in plain view within.

There is a signpost here.

You can go south or west down the street from here.
VERHEDIN
    );
  set_exits(([
    "northeast" : VNEW+"leather",
    "south" : VNEW+"som1",
    "west" : VNEW+"acm11"
   ]));
  set_listen("default","You hear the occasional crying of a child from one building or another.");
  set_smell("default","You pick up the scent of leather from the northeast.");
  set_items( ([
    "signpost" : "It reads in Elven and Common:  %^BOLD%^Avenue of the Crescent Moon%^RESET%^"
  ]) );
 }

void reset(){
	::reset();
}
