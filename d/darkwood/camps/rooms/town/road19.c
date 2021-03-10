#include <std.h>
#include "../../elfisland1.h";
inherit BTOWN;

void create() {
   ::create();
   set_long("%^RESET%^%^GREEN%^Towards the north the signs of inhabitation start take shape"+
      " when you look off in that direction. Off to the south the trail ends at the entrance"+
      " to the untouched forest that surrounds this populated area. A narrow footpath has been "
      "worn through the underbrush to the southwest, nearly blending in to the surrounding forest.\n"
   );
   set_items( ([
      "forest":"It is dark and foreboding.",
      "path":"A narrow footpath seems to have been worn through the underbrush to the southwest."
   ]) );
   set_exits( ([
      "north" : TOWN+"road18",
      "southwest" : TOWN+"wild1"
   ]) );
}
void reset()
{
   ::reset();
   if(!present("guard")) {
   new(MON+"elguard")->move(TO);
   new(MON+"elguard")->move(TO);
   }
}
