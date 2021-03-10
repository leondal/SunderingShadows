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
You are on a paved street just inside the walls of the city.  To the
north, you can see the great gatehouse with its enormous porticullis and
iron shod doors.  To the south, you see a tall monument in the shape of
a golden obelisk topped by a crescent moon. 

You have the option of going through the walls to the outside via the
gates to the north, or you can continue south into the city.

There is a signpost here.
VERHEDIN
  );
  set_exits(([
    "north" : VNEW+"ngates",
    "south" : VNEW+"acm6"
   ]));
  set_listen("default","You hear the sound of wheels on cobblestones coming through the gates at all times.");
  set_smell("default","Your nose is stuffed with dust kicked up by wagons entering the city.");
  set_items( ([
    "monument" : "A tapered, four-sided golden spire that   "
	             "rises high into the air.  This monument has "
				 "a crescent at the point.  You can't tell much more "
				 "about it from this distance.",
    "signpost" : "It reads in Elven and Common:  "
	             "%^BOLD%^Avenue of the Crescent Moon%^RESET%^"
  ]) );
}

void reset(){
	::reset();
}
