

// Harbor Road, Verhedin 
// Thorn@ShadowGate
// 001027
// New City, Verhedin
// hr1.c

#include <std.h>
#include "/d/tsarven/include/southern.h"
#include "/d/verhedin/include/city.h"

inherit ROOM;

void create() {
  room::create();
  set_light(2);
  set_short("%^BOLD%^Harbor Road, Verhedin%^RESET%^");
  set_long(
@VERHEDIN
%^BOLD%^Harbor Road, Verhedin%^RESET%^

You can go north, northeast, northwest, or south down the street from here.
VERHEDIN
    );
  set_exits(([
    "north" : VOLD+"ps5",
    "northwest" : VOLD+"ps4",
    "south" : VOLD+"hr2",
    "northeast" : VNEW+"ib1"
   ]));
  set_listen("default","Default listen.");
  set_smell("default","Default smell.");
 }

void reset(){
	::reset();
}
