#include <std.h>

inherit "/d/deku/open/cave_r3i.c";

void create() {
   ::create();
   set_long( ::query_long()+"To the north, a hide hangs partially over the "
       "opening as a sort of crude door.");
   set_smell("default","The sickening musty odor is very strong from the north.");
   set_exits(([
       "north" : "/d/deku/open/waste",
      "south" : "/d/deku/open/cave_r3i",
       "east" : "/d/deku/open/unfin"
   ] ));
}
