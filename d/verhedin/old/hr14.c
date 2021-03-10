
// Harbor Road, Verhedin 
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
  set_short("%^BOLD%^Harbor Road, Verhedin%^RESET%^");
  set_long(
@VERHEDIN
%^BOLD%^Harbor Road, Verhedin%^RESET%^

You can go east, west, northeast, or southeast down the street from here.
VERHEDIN                 
    );
  set_exits(([
    "west" : VOLD+"hr13",
    "northeast" : VOLD+"hr4",
    "east" : VOLD+"hr5",
    "southeast" : VOLD+"hr6"
   ]));
  set_listen("default","Default listen.");
  set_smell("default","Default smell.");
 }

void reset(){
	::reset();
}
