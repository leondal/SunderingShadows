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
You are on a paved street running north to south through the city. To 
the north, there is an intersection with what appears to be a wide 
avenue.  Beyond the intersection, you see what you can make out from 
this perspective as some sort of parade field of some sort that is cut 
in half by the street passing through it.  

To the south, you can see a great fortress dominate this entire section 
of the city.  This road leads straight to a large gate and just before 
that, you can see a military checkpoint where Imperial troops are 
inspecting people approaching the fortress.

You can go north or south down the street.
VERHEDIN
    );
  set_exits(([
    "north" : VNEW+"agd5",
    "south" : VNEW+"sol5"
   ]));
  set_listen("default","You hear sounds of activity in distant parts of the city.");
  set_smell("default","You can smell earth and grass kicked up by boots and horses.");
 }

void reset(){
	::reset();
}
