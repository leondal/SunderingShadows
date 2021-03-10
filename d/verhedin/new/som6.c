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
area, and that many of the people you see are garbed in either plain
clerical robes or the robes of less accomplished magi.  Others seem to
be wearing hair shirts or garbed in plain white from head to toe in the
manner of pilgrims.

To the east, you see what appears to be a temple of some kind, although
you see no indication of the god that is worshipped there.  West, you
see a side entry to a stone building with large glass display windows.

You can go north or south down the street from here.
VERHEDIN
    );
  set_exits(([
    "north" : VNEW+"som5",
    "south" : VNEW+"som7",
    "east" : VNEW+"utemple",
    "west" : VNEW+"ali"
    ]));
  set_listen("default","You hear loud cries to the north.");
  set_smell("default","You smell an odor of burnt flesh from the north and incense to the east.");
 }

void reset(){
	::reset();
}

