#include <std.h>
#include "../witchlair.h"
inherit BASE"grove_inh2.c";

void create() {
 ::create();
   set_long(::query_long()+"\n%^BOLD%^%^BLACK%^A large %^GREEN%^hole "
"%^BLACK%^is near the base of the wall here, facing westward. It seems "
"big enough that you might be able to crawl through it.");
 set_exits(([
  "south":ROOMS"grove5",
  "southeast":ROOMS"grove6",
  "west":ROOMS"path1",
  "east":ROOMS"grove9",
 ]));
}
