
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

You can go north, southwest, southeast, or south down the street from here.
VERHEDIN
    );
  set_exits(([
    "north" : VNEW+"agc13",
    "southwest" : VNEW+"iw8",
    "southeast" : VNEW+"iw10",
    "south" : VNEW+"iw9"
    ]));
  set_listen("default","Default listen.");
  set_smell("default","Default smell.");
 }

void reset(){
	::reset();
}
