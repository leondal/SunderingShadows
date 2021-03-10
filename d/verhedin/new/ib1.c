
// Imperial Bridge, Verhedin
// Thorn@ShadowGate
// 001027
// New City, Verhedin
// som4.c

#include <std.h>
#include "/d/tsarven/include/southern.h"
#include "/d/verhedin/include/city.h"

inherit ROOM;

void create() {
  room::create();
  set_light(2);
  set_short("%^BOLD%^Imperial Bridge, Verhedin%^RESET%^");
  set_long(
@VERHEDIN
%^BOLD%^Imperial Bridge, Verhedin%^RESET%^

You can go west, east, northwest, or southwest down the street from here.
VERHEDIN
    );
  set_exits(([
    "northwest" : VOLD+"rir12",
    "southwest" : VOLD+"hr1",
    "west" : VOLD+"ps5",
    "east" : VNEW+"ib2"
   ]));
  set_listen("default","Default listen.");
  set_smell("default","Default smell.");
 }

void reset(){
	::reset();
}
