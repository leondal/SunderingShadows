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
dirty, and seem to be in poor shape structurally.

To the south, you see what is obviously a seedy tavern.  Whether you'd
want to take a closer or not look is more in doubt.

You can go east or west down the street from here.
VERHEDIN
    );
  set_exits(([
    "east" : VNEW+"acm10",
    "west" : VNEW+"acm8",
    "south" : VNEW+"poortavern"
   ]));
  set_listen("default","You hear the occasional crying of a child from one building or another.");
  set_smell("default","There is a hint of stale alcohol in the air.");
}

void reset(){
	::reset();
}
