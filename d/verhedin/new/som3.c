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

You can go north or south down the street from here.
VERHEDIN
    );
  set_exits(([
    "north" : VNEW+"som2",
    "south" : VNEW+"som4"
    ]));
  set_listen("default","It is fairly quiet here, although you can hear more activity to the south.");
  set_smell("default","There are a number of scents too numerous to identify in the area.");
 }

void reset(){
	::reset();
}
