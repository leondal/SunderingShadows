#include <std.h>
#include "mountain.h";

inherit BASE;

void create(){
   ::create();
   set_long(
      "%^BOLD%^%^BLACK%^The bridge leads right into an imposing staircase"+
      " that is also formed from the mountain. The stairs are wide and large"+
      " as if made for a giant or creature of massive proportions. The air"+
      " is very thin up here and you are surrounded by fog. You are so high"+
     " that you feel you could reach the sky with a good jump."
   );
   set_exits(([
      "stairs" : MOUNTAIN+"mountain10",
      "bridge" : MOUNTAIN+"mountain08",
   ]));
}
