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
"metal, leaning together in vague semblances of structure.  A dark tunnel opens from the cavern wall itself, "
"with a pair of metal tracks leading away into the %^BOLD%^%^BLACK%^darkness %^RESET%^within.\n\n"
"Pinned to the wall is a %^ORANGE%^canvas %^RESET%^with a crude map scrawled upon in in what looks like %^RED%^blood%^RESET%^.\n");

   set_exits(([
     "east":ROOMS"cavern2",
   ]));
}

void init(){
    ::init();
  add_action("Look","look");
  add_action("Look","exa");
}
//map added by ~Circe~ 5/2/13 in response to requests from players
//This map is the same as the one in Shadow and Tabor.
int Look(string str){
    if(!str || (str != "floor" && str != "map" && str != "canvas")) return 0;
  TP->more("/d/common/text/main_map"); 
        return 1;
}