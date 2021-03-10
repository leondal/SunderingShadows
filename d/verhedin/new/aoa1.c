
// Avenue of the Astrologers, Verhedin
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
  set_short("%^BOLD%^Avenue of the Astrologers, Verhedin%^RESET%^");
  set_long(
@VERHEDIN
%^BOLD%^Avenue of the Astrologers, Verhedin%^RESET%^

You can go northwest, west, southwest, or east down the street from here.
VERHEDIN
    );
  set_exits(([
    "northwest" : VNEW+"agd9",
    "west" : VNEW+"agd10",
    "southwest" : VNEW+"agd11",
    "east" : VNEW+"aoa2"
    ]));
  set_listen("default","Default listen.");
  set_smell("default","Default smell.");
 }

void reset(){
	::reset();
}

