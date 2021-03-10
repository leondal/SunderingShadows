// Thorn@ShadowGate
// 970215
// City of Shadow 1997 revision
// Revised 000919 for Tsarven Occupation of Shadow

#include <std.h>
#include "/d/shadow/room/shadow.h"

inherit ROOM;

void create() {
  ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
  set_light(2);
  set_indoors(0);
  set_short("Garrison Road, Shadow");
  set_long(
@SHADOW
%^BOLD%^CYAN%^Garrison Road%^RESET%^
You are on Garrison Road, just north of the center of the great
city of Shadow.  To the southeast, you can see the Adventurer's Hall as
well as the bank and a large general supply store as well, a little
further on.  To the south, you see a wall that covers where Garrison
Road used to go directly into the Tower of the Immortals creating
a bend in the road around the wall.

Garrison Road continues to the north and southeast.
SHADOW
  );
  set_exits(([
    "southeast" : "/d/shadowgate/adv_main",
    "east" : "/d/shadow/room/city/cguild/fighter/ac_fighter",
    "north" : "/d/shadow/room/main/garrison4",
  ] ));
  set_items(([
    "road":"A cobblestone road through the city",
    "wall":"This wall appears to be built recently and is of a Tsarvani design.",
  ]));
  
  set_smell("default","You smell the cool fresh air.");
  set_listen("default","You hear the sounds of people moving around the city.");
}

void reset(){
   ::reset();
        if(!present("street_light",TO))
                new(MISCDIR+"street_light")->move(TO);
}
