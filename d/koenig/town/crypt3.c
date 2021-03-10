#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
  set_property("light", 0);
  set_property("indoors", 1);
  set_short("A Dark Room Beneath the Crypt");
  set_long("%^BOLD%^%^BLACK%^You now find yourself at the bottom of the stairs with many different "+
"directions to go. However, all the passages are rather %^RESET%^dark%^BOLD%^%^BLACK%^ and %^RESET%^spooky%^BOLD%^%^BLACK%^, "+
"and wouldn't it be nice if you had a fine glass of %^RESET%^%^MAGENTA%^wine%^BOLD%^%^BLACK%^ right about now? In a lighted area, preferably one without so many %^RESET%^cobwebs%^BOLD%^%^BLACK%^.%^RESET%^");
  set_exits( ([
     "north" : "/d/koenig/town/crypt4",
     "south" : "/d/koenig/town/crypt5",
     "west" : "/d/koenig/town/crypt6",
     "up" : "/d/koenig/town/crypt2"
]) );
}
