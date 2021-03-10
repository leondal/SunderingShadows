#include <std.h>
#include "../defs.h"
inherit INH+"town";

void create(){ 
   ::create();
   set_long("%^BOLD%^A dark cavern%^RESET%^\n"
"The roof of this dark cavern arcs far above you, lost from view in the cave's %^BLACK%^%^BOLD%^shadows"
"%^RESET%^.  The walls are made of dull stone, still rough and jagged as though naturally formed.  Piles of "
"%^ORANGE%^trash%^RESET%^ and %^BLUE%^debris%^RESET%^ cover nearly the entire ground, where various "
"creatures have obviously taken up residence amidst the squalour.  Through the mess, a rough pathway has "
"been cleared, coming to a dead end here amidst even larger piles of rubbish.  A few little%^ORANGE%^ "
"shanties %^RESET%^have been set up in the area nearby, though they're merely a few pieces of scavenged "
"wood, cloth and metal, leaning together in vague semblances of structure.  A few creatures, however, "
"pick their way through the piles and into an alcove behind, ignoring the rubbish strewn about.\n");

   set_exits(([
     "north":ROOMS"cavern6",
     "southwest":ROOMS"mage",
   ]));
}

void reset(){
   ::reset();
   if(!present("tuugek"))
     find_object_or_load(MON"tuugek")->move(TO);
}
