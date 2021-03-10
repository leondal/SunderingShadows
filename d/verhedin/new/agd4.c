
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

You can go west, northeast, southeast, or east down the street from here.
VERHEDIN
    );
  set_exits(([
    "west" : VNEW+"agd3",
    "northeast" : VNEW+"sol3",
    "southeast" : VNEW+"sol4",
    "east" : VNEW+"agd5"
    ]));
  set_listen("default","Default listen.");
  set_smell("default","Default smell.");
 }

void reset(){
	::reset();
}
