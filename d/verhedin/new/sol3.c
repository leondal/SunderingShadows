// Street of the Legions, Verhedin
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
  set_short("%^BOLD%^GREEN%^Street of the Legions, Verhedin%^RESET%^");
  set_long(
@VERHEDIN
%^BOLD%^GREEN%^Street of the Legions, Verhedin%^RESET%^
You are on a paved street running north to south through the city. 
South, you can clearly see an intersection with another street.  Farther
south, a fortress looms above the tops of the other buildings. 

You can go north or south down the street.
VERHEDIN
    );
  set_exits(([
    "south" : VNEW+"agd5",
    "north" : VNEW+"sol2"
   ]));
  set_listen("default","You hear sounds of activity in distant parts of the city.");
  set_smell("default","You can smell earth and grass kicked up by boots and horses.");
 }

void reset(){
	::reset();
}
