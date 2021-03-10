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
the city.  From the look of the buildings, they appear to be mostly
commercial, with warehouses making up the majority of buildings.  The
fact that many of the warehouses are well fortified, and that others lay
almost abandoned gives you a feeling that you are not in the safest of
places.

You can see the fortified gate to a large warehouse to the east.  There
is another warehouse to to west which has an even better guarded and
fortified gate.  Over that gates hangs a sign.

You can go north or south down the street from here.
VERHEDIN
    );
  set_exits(([
    "north" : VNEW+"som1",
    "south" : VNEW+"som3",
    "east" : VNEW+"tware1",
    "west" : VNEW+"2ware1"
    ]));
  set_listen("default","It is quiet here, although you can hear more activity to the south.");
  set_smell("default","There are a number of scents too numerous to identify in the area.");
  set_items( ([
    "sign" : "You see the sign of three bees on the sign above the gate.\n"
             "%^WHITE%^BOLD%^  ,-.      ,-.      ,-. \n"
             "  \\_/      \\_/      \\_/ \n"
             "%^YELLOW%^>{%^BOLD%^BLACK%^|||%^RESET%^YELLOW%^}   "
             "%^YELLOW%^>{%^BOLD%^BLACK%^|||%^RESET%^YELLOW%^}   "
             "%^YELLOW%^>{%^BOLD%^BLACK%^|||%^RESET%^YELLOW%^} \n"
             "%^WHITE%^  / \\      / \\      / \\ \n"
             "  `-^      `-^      `-^ \n"
  ]) );
}

void reset(){
	::reset();
}
