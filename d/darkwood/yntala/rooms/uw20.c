//uw20
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"underwater.c";

void create(){
::create();
   set_exits(([
"up":INRMS+"uw21",
"west":INRMS+"uw19"
]));
   set_items(([
({"crack","cracks"}):"%^ORANGE%^These cracks look a little different than the rest of them, maybe you should take a closer look.%^RESET%^"
]));
   set_search("cracks","You notice that one of the cracks here is larger than the rest, maybe you can enter it?");
}
void init(){
   ::init();
   add_action("enter","enter");
}
int enter(string str){
   if(str == "crack"||str == "the crack"){
   tell_object(TP,"%^BOLD%^%^BLACK%^You squeeze through the crack.%^RESET%^");
   tell_room(ETP,""+TPQCN+" disappears in a poof of %^BOLD%^%^WHITE%^bubbles!%^RESET%^",TP);
   this_player()->move_player(INRMS+"uw23");
   return 1;
   }
   if(str == "cracks"){
   tell_object(TP,"%^CYAN%^Now that's an interesting concept, but instead of trying to become numerous little pieces of fish food in order to enter all the cracks, why don't you just try to get through one?");
  return 0;
  }
  tell_object(TP,"%^BOLD%^%^CYAN%^Don't you just want to enter the crack?%^RESET%^");
  return 1;
}
