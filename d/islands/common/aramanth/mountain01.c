#include <std.h>
#include "mountain.h";

inherit BASE;

void create(){
   ::create();
   set_long(
      "%^RESET%^%^ORANGE%^As you walk along the wall of the cliffs here on the beach"+
      " you notice a path hugging the towering stone structure above you."+
      " The path is pretty rugged and it would seem it has not been used in"+
      " some time. As you look up it almost seems as if the mountain reaches"+
      " the sky."
   );
   set_exits(([
      "west" : ARAMANTH,
      "southeast" : MOUNTAIN+"mountain02",
   ]));
}