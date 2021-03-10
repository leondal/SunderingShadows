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

To the east, you see a store whose %^BOLD%^BLUE%^dark blue awnings%^RESET%^ are covered with
arcane symbols in %^BOLD%^YELLOW%^gold%^RESET%^.  To the west, there is a storefront with %^RED%^red
awnings%^RESET%^ and %^WHITE%^BOLD%^silver runes%^RESET%^ sown into them.  Both look like fairly upscale
shops that seem a bit out of place in this busy commercial area.

You can go north or south down the street from here.
VERHEDIN
    );
  set_exits(([
    "north" : VNEW+"som3",
    "south" : VNEW+"som5",
    "east" : VNEW+"alhazred",
    "west" : VNEW+"fatwah"
    ]));
  set_listen("default","You hear loud cries to the south.");
  set_smell("default","There are some wonderful, but disturbing smells emanating from the stores.");
}

void reset(){
	::reset();
}
