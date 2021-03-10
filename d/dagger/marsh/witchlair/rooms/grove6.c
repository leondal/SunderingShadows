#include <std.h>
#include "../witchlair.h"
inherit BASE"grove_inherit.c";

void create() {
 ::create();
 set_long(::query_long()+"\n%^BOLD%^%^BLACK%^A massive "
"%^RESET%^%^GREEN%^tree %^BOLD%^%^BLACK%^rises into the sky here,"
" larger than most you've seen in your time on this earth.%^RESET%^");
TO->add_item("tree","%^RESET%^%^GREEN%^This thing must be simply "
"*ancient*. The trunk is easily wide enough to fit a small building"
" inside. Enormous %^ORANGE%^ro%^BOLD%^%^BLACK%^o"
"%^RESET%^%^ORANGE%^ts %^GREEN%^rise and fall beneath the earth like"
" the humps of a great sea serpent. This tree's bulk rises into the sky"
" farther than your eye can follow, past the mist itself, toward the "
"heavens. One has to wonder how this giant has evaded sight from "
"beyond the marsh.");
 set_exits(([
  "west":ROOMS"grove5",
  "northwest":ROOMS"grove8",
  "north":ROOMS"grove9",
  "northeast":ROOMS"grove10",
  "down":ROOMS"roots",
  "east":ROOMS"grove7",
  "southeast":ROOMS"grove4",
  "south":ROOMS"grove3",
  "southwest":ROOMS"grove2",
 ]));
}
