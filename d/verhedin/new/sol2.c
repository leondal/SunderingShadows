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
You are on a paved street running north to south through the city.  To
the north, you see a tall monument in the shape of a golden obelisk
topped by a crescent moon.  To the south, you glimpse another
intersection and beyond that what appears to be a great grim looking
fortress with banners waving above it and what looks from here like a
gate.  All around where you are standing, it looks like there is a well
trod field to each side which seems like it is big enough to march an
army across.

You can go north or south from here.
VERHEDIN
    );
  set_exits(([
    "south" : VNEW+"sol3",
    "north" : VNEW+"acm6",
   ]));
  set_listen("default","You hear sounds of activity in distant parts of the city.");
  set_smell("default","You smell the earth and grass kicked up by boots and horses.");
}

void reset(){
	::reset();
}
