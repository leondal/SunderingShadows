#include <std.h>
#include "../witchlair.h"
inherit BASE"grove_inh2.c";

void create() {
 ::create();
   set_long(::query_long()+"\n%^BOLD%^%^BLACK%^A large %^GREEN%^hole "
"%^BLACK%^is near the base of the wall here, facing eastward. It seems "
"big enough that you might be able to crawl through it.");
 set_exits(([
  "south":ROOMS"grove4",
  "southwest":ROOMS"grove3",
  "west":ROOMS"grove6",
  "northwest":ROOMS"grove9",
  "north":ROOMS"grove10",
  "east":ROOMS"path2",
 ]));
}
