
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

You can go north, west, or south down the street from here.
VERHEDIN
    );
  set_exits(([
    "north" : VOLD+"hr4",
    "south" : VOLD+"hr6",
    "west" : VOLD+"hr14"
   ]));
  set_listen("default","Default listen.");
  set_smell("default","Default smell.");
 }

void reset(){
	::reset();
}
