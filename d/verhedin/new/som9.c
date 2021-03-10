// Street of the Merchants, Verhedin
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
  set_short("%^BOLD%^YELLOW%^Street of the Merchants, Verhedin%^RESET%^");
  set_long(
@VERHEDIN
%^BOLD%^YELLOW%^Street of the Merchants, Verhedin%^RESET%^
This is a cobblestonned street that appears to run north-south though
the city.  You notice that there is a fair amount of traffic in this
area, which looks to be a shopping district filled with stores.  To the
south, you see that this street intersects with another, wider street
running perpendicular to this one.  Across that street, you see a
%^BOLD%^WHITE%^magnificent white marble temple%^RESET%^ with a %^YELLOW%^BOLD%^golden dome%^RESET%^ rise high above the
city. 

At this end of the street, you can see the bank on the west side, a
building that would be considered impressive in its own right if it
hadn't been placed so close to the grand temple.  On the east side are a
number of more humble shops, most notably a tailor shop.

You see a signpost.

You can go north or south down the street from here.
VERHEDIN
    );
  set_exits(([
    "north" : VNEW+"som8",
    "south" : VNEW+"iw12",
    "east" : VNEW+"tailor",
    "west" : VNEW+"bank"
    ]));
  set_listen("default","This is a fairly busy area, but it is ordered and there is little noise.");
  set_smell("default","There is a faint smell of incense coming from the south.");
  set_items( ([
    "signpost" : "It reads in Elven and Common:  %^BOLD%^Street of the Merchants%^RESET%^",
    "temple" : "The temple appears to be a work of art unsurpassed by anything else in "
               "this part of the city.  Nearly 5 stories high, not including the dome, the "
               "temple seems to be built as much for defense as worship.   You can "
               "even see men in golden armor and white cloaks on the walls standing "
               "guard at certain intervals.  Although you can't make it out from here "
               "there is evidence that there are some fine carvings and decorative work "
               "gracing the blindingly white exterior.  Around the temple is what appears to "
			   "be some well manicured trees and bushes, perhaps even flowers."
  ]) );
}

void reset(){
	::reset();
}

