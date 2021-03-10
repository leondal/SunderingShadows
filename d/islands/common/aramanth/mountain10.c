#include <std.h>
#include "mountain.h";

inherit BASE;

void create(){
   ::create();
   set_long(
      "%^BOLD%^%^BLACK%^The stairs go up and up, ascending almost into the heavens."
      " However, they reach their end here. The stairs cap off right at the top"+
      " of the mountain. On the stairs near the top, you notice that all of them"+
      " are much darker than rest of the mountain. It is as if they have been scorched."
   );
   set_exits(([
      "top" : MOUNTAIN+"mountain11",
      "down" : MOUNTAIN+"mountain09",
   ]));
}