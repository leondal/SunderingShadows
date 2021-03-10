
// Prince Street, Verhedin 
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
  set_short("%^BOLD%^Prince Street, Verhedin%^RESET%^");
  set_long(
@VERHEDIN
%^BOLD%^Prince Street, Verhedin%^RESET%^

You can go west, northeast, east, or southeast down the street from here.
VERHEDIN
    );
  set_exits(([
    "west" : VOLD+"ps3",
    "east" : VOLD+"ps5",
    "northeast":VOLD+"rir12",
    "southeast":VOLD+"hr1"
   ]));
  set_listen("default","Default listen.");
  set_smell("default","Default smell.");
 }

void reset(){
	::reset();
}
