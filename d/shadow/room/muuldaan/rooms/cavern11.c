#include <std.h>
#include "../defs.h"
inherit INH+"town";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^WHITE%^A dark cavern\n"
"%^RESET%^The roof of this dark cavern arcs far above you, lost from view in the cave's %^BOLD%^%^BLACK%^shadows"
"%^RESET%^.  The walls are made of dull stone, still rough and jagged as though naturally formed.  Leading "
"down this side corridor, the piles of %^ORANGE%^trash %^RESET%^and %^BLUE%^debris %^RESET%^that "
"usually cover the ground start to thin, as though someone had been making an effort to clear them away.  "
"The corridor narrows to the west, and comes to what appears to be a dead end.\n");

   set_exits(([
     "southeast":ROOMS"cavern6",
     "west":ROOMS"psion",
     "northwest":ROOMS"psion2",
   ]));
}

void reset(){
   ::reset();
   if(!present("aged gemcutter")) new(MON"psi_gemcutter")->move(TO);
}
