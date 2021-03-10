
// Market Street, Verhedin 
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
  set_short("%^BOLD%^Market Street, Verhedin%^RESET%^");
  set_long(
@VERHEDIN
%^BOLD%^Market Street, Verhedin%^RESET%^

You can go west or east down the street from here.
VERHEDIN
    );
  set_exits(([
    "west" : VOLD+"ms7",
    "east" : VOLD+"ms9"
   ]));
  set_listen("default","Default listen.");
  set_smell("default","Default smell.");
 }

void reset(){
	::reset();
}
