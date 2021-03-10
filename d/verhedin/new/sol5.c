// Street of the Legions, Verhedin
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
  set_short("%^BOLD%^GREEN%^Street of the Legions, Verhedin%^RESET%^");
  set_long(
@VERHEDIN
%^BOLD%^GREEN%^Street of the Legions, Verhedin%^RESET%^
You are on a paved street running north to south through the city. 
Right now you stand at a military checkpoint directly in the shadow of a 
great fortress built in the center of the city.  

To the north, the road moves away from the fortress into the city 
proper. A short distance away you can make out an intersection of the 
streets and what appears to be a large grassy field beyond.  Directly to 
the south is a great gate giving entry to the fortress that dominates 
the area.
VERHEDIN
    );
  set_exits(([
    "north" : VNEW+"sol4",
    "south" : VFORT+"ngate"
   ]));
  set_listen("default","You hear the occasional sound of crisp orders being given around you.");
  set_smell("default","You can vaguely smell a river nearby.");
 }

void reset(){
	::reset();
}
