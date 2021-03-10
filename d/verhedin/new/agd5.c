
// Avenue of the Golden Dawn, Verhedin
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
  set_short("%^BOLD%^Avenue of the Golden Dawn, Verhedin%^RESET%^");
  set_long(
@VERHEDIN
%^BOLD%^Avenue of the Golden Dawn, Verhedin%^RESET%^

You can go west, north, south, or east down the street from here.
VERHEDIN
    );
  set_exits(([
    "west" : VNEW+"agd4",
    "north" : VNEW+"sol3",
    "south" : VNEW+"sol4",
    "east" : VNEW+"agd6"
    ]));
  set_listen("default","Default listen.");
  set_smell("default","Default smell.");
 }

void reset(){
	::reset();
}

