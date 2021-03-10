
// Temple Court, Verhedin
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
  set_short("%^BOLD%^Temple Court, Verhedin%^RESET%^");
  set_long(
@VERHEDIN
%^BOLD%^Temple Court, Verhedin%^RESET%^

You can go northwest, north, northeast, southeast or south down the street from here.
VERHEDIN
    );
  set_exits(([
    "north" : VNEW+"iw11",
    "northwest" : VNEW+"iw10",
    "northeast" : VNEW+"iw12",
    "southeast" : VNEW+"tc3",
    "south" : VNEW+"tc2"
   ]));
  set_listen("default","Default listen.");
  set_smell("default","Default smell.");
 }

void reset(){
	::reset();
}
