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
area, which looks to be a shopping district filled with stores.

To the west, you see a sign over a store that is obviously meant to
indicate a clothier.  On the other side of the street, as if to
complment the clothing store, there is a store with a sign shaped like a
fancy turban hanging above it.
 
You can go north or south down the street from here.
VERHEDIN
    );
  set_exits(([
    "north" : VNEW+"som7",
    "south" : VNEW+"som9",
    "east" : VNEW+"clothier",
    "west" : VNEW+"hatter"
    ]));
  set_listen("default","It is fairly quiet here, although you can hear more activity to the north.");
  set_smell("default","There are a number of scents too numerous to identify in the area.");
 }

void reset(){
	::reset();
}

