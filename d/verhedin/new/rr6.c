
// Royal Road, Verhedin
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
  set_short("%^BOLD%^Royal Road, Verhedin%^RESET%^");
  set_long(
@VERHEDIN
%^BOLD%^Royal Road, Verhedin%^RESET%^

You can go north, south, east, or west down the street from here.
VERHEDIN
    );
  set_exits(([
    "north" : VNEW+"rr5",
    "west" : VNEW+"???5",
    "south" : VNEW+"rr7",
    "east" : VNEW+"???6"
   ]));
  set_listen("default","Default listen.");
  set_smell("default","Default smell.");
 }

void reset(){
	::reset();
}

