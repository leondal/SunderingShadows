
// Haggler's Alley, Verhedin
// Thorn@ShadowGate
// 001027
// New City, Verhedin
// ha3.c

#include <std.h>
#include "/d/tsarven/include/southern.h"
#include "/d/verhedin/include/city.h"

inherit ROOM;

void create() {
  room::create();
  set_light(2);
  set_short("%^BOLD%^Haggler's Alley, Verhedin%^RESET%^");
  set_long(
@VERHEDIN
%^BOLD%^Haggler's Alley, Verhedin%^RESET%^

You can go east and west down the street from here.
VERHEDIN
    );
  set_exits(([
    "west" : VNEW+"ha2",
    "east" : VNEW+"ha4"
   ]));
  set_listen("default","Default listen.");
  set_smell("default","Default smell.");
 }

void reset(){
	::reset();
}

