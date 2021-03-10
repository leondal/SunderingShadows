
// West Road, Verhedin 
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
  set_short("%^BOLD%^West Road, Verhedin%^RESET%^");
  set_long(
@VERHEDIN
%^BOLD%^West Road, Verhedin%^RESET%^

You can go southwest, or northwest down the street from here.
VERHEDIN
    );
  set_exits(([
    "southwest" : VOLD+"wr2",
    "northwest" : VOLD+"wr4"
   ]));
  set_listen("default","Default listen.");
  set_smell("default","Default smell.");
 }

void reset(){
	::reset();
}
