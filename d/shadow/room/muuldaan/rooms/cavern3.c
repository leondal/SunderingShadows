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
"been cleared, revealing enough stone floor to navigate around the area.  A few little %^ORANGE%^shanties "
"%^RESET%^have been set up in the area, though they're merely a few pieces of scavenged wood, cloth and "
"metal, leaning together in vague semblances of structure.  West of you is quite a collection of rubbish, "
"and an odd, sharp smell emanates from there.\n");

   set_exits(([
     "northeast":ROOMS"cavern4",
     "southeast":ROOMS"cavern2",
     "west":ROOMS"healer",
   ]));
}
