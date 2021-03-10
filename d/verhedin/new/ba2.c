
// Bazaar Avenue, Verhedin
// Thorn@ShadowGate
// 001027
// New City, Verhedin
// ba2.c

#include <std.h>
#include "/d/tsarven/include/southern.h"
#include "/d/verhedin/include/city.h"

inherit ROOM;

void create() {
  room::create();
  set_light(2);
  set_short("%^BOLD%^Bazaar Avenue, Verhedin%^RESET%^");
  set_long(
@VERHEDIN
%^BOLD%^Bazaar Avenue, Verhedin%^RESET%^

You can go northeast and west down the street from here.
VERHEDIN
    );
  set_exits(([
    "west" : VNEW+"ba1",
    "northeast" : VNEW+"ba3"
   ]));
  set_listen("default","Default listen.");
  set_smell("default","Default smell.");
 }

void reset(){
	::reset();
}

