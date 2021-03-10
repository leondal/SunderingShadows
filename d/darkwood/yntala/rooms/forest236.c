//forest236
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest2.c";

void create(){
::create();
  set_long("%^GREEN%^You find yourself in a very %^BOLD%^"
"%^BLACK%^dark %^RESET%^%^GREEN%^part of the forest.  Very little"
" light finds its way through the %^BOLD%^%^BLACK%^gnarled"
" %^RESET%^%^GREEN%^old trees that twist their way eerily towards"
" the unseen sky above.  Several of them seem to be almost alive and one in particular"
" looks unusually forbidding.  %^RESET%^%^ORANGE%^Fallen trees"
" %^GREEN%^litter the ground around you, and a heavy,"
" %^BLUE%^oppressive %^GREEN%^feeling seems to fill the air here."
"%^RESET%^\n");
  set("night long","%^RESET%^%^BLUE%^This %^GREEN%^forest %^BLUE%^is even %^BOLD%^%^BLACK%^darker %^RESET%^%^BLUE%^at night, with"
" absolutely no moonlight touching the forest floor around you. "
" %^BOLD%^%^BLACK%^Shadows %^RESET%^%^BLUE%^dance seductively in"
" the darkness, beckoning you to come further into their midst,"
" and the trees even seem to take on a more eerie twist as they"
" hover overhead.  One tree in particular stands out here.%^RESET%^\n");
  set_items(([
     ({"floor","forest floor"}):"%^BOLD%^%^BLACK%^Shadows dance across the forest floor, making it difficult to see much.%^RESET%^",
     ({"forest","trees"}):"%^RESET%^%^ORANGE%^The trees here are old and gnarled, twisted in deformed ways that give off a %^BOLD%^%^BLACK%^spooky %^RESET%^%^ORANGE%^feeling.%^RESET%^",
     ({"light","lights"}):"%^RESET%^%^BLUE%^The only %^RESET%^light %^BLUE%^that manages to make its way through the dense %^GREEN%^canopy %^BLUE%^looks more like fine %^RESET%^spiderwebs %^BLUE%^falling from the sky.",
      "fallen trees":"%^GREEN%^Many fallen trees litter the ground here, most are %^ORANGE%^rotting %^GREEN%^and covered with moss.%^RESET%^",
      "tree":"%^RESET%^%^ORANGE%^There is one particularly large tree here that twists its way up past the others.  Near the base of its trunk you see an opening that perhaps you can enter.",
]));

set_exits(([
"north":INRMS+"forest237",
"south":INRMS+"forest23"
]));
}
void init(){
  ::init();
  add_action("enter","enter");
}
int enter(string str){
   if(str == "tree"||str=="the tree"||str=="hole"){
   tell_object(TP,"%^RESET%^%^ORANGE%^You kneel down on your hands and knees and hope for the best as you crawl into the old tree.%^RESET%^");
   tell_room(TO,"%^RESET%^%^ORANGE%^"+TPQCN+" kneels down near the base of the tree and crawls into a hole.",TP);
   this_player()->move_player(INRMS+"tree2");
   return 1;
   }
}
