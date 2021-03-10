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
commercial, with warehouses making up the majority of buildings. 
Judging by the look of the area, you can tell that this is probably not
the safest place in the city and the shadows of the buildings loom
large.  The fact that many of the warehouses are well fortified, and
that others lay almost abandoned only contibutes to this feeling.

You can see the fortified gate to a large warehouse to the east.

You see a signpost.

You can go north or south down the street from here.
VERHEDIN
    );
  set_exits(([
    "north" : VNEW+"acm12",
    "south" : VNEW+"som2",
    "east" : VNEW+"1ware1"
    ]));
  set_listen("default","It is quiet here, although you can hear more activity to the south.");
  set_smell("default","There are a number of scents too numerous to identify in the area.");
  set_items( ([
    "signpost" : "It reads in Elven and Common:  %^BOLD%^Street of the Merchants%^RESET%^"
  ]) );
 }

void reset(){
	::reset();
}
