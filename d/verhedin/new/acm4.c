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
though an area that appears to be quiet and residential.  On both sides,
multi-story homes built close together display colorful awnings over
their windows and the doors and shutters are ornately carved.  Some of
the upper levels have wooden screens over them in a manner often found
farther to the south in cities like Tsarven and Elbarin.  

You can go east or west down the street from here.
VERHEDIN
    );
  set_exits(([
    "east" : VNEW+"acm5",
    "west" : VNEW+"acm3"
   ]));
  set_listen("default","You hear the sounds of a busy city.");
  set_smell("default","You detect the scent of incense in the air.");
 }

void reset(){
	::reset();
}


