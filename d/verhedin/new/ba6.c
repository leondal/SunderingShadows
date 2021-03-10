
// Bazaar Avenue, Verhedin
// Thorn@ShadowGate
// 001027
// New City, Verhedin
// ba6.c

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

You can go west down the street from here.
VERHEDIN
    );
  set_exits(([
    "northwest" : VNEW+"rr5",
    "southwest" : VNEW+"rr7",
    "west" : VNEW+"rr6"
   ]));
  set_listen("default","Default listen.");
  set_smell("default","Default smell.");
 }

void reset(){
	::reset();
}

