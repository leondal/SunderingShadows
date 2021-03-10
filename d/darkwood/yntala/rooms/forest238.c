//updated to not allow you to enter vines to escape combat - Circe 6/4/07
//forest238
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest2.c";

void create(){
::create();
set_exits(([
"northeast":INRMS+"forest239",
"southwest":INRMS+"forest237"
]));
  set_name("An ancient forest");
  set_short("%^GREEN%^A %^BOLD%^%^BLACK%^dark %^RESET%^%^GREEN%^and ancient forest%^RESET%^");
  set_long("%^GREEN%^You find yourself in a very %^BOLD%^"
"%^BLACK%^dark %^RESET%^%^GREEN%^part of the forest.  Very little"
" light finds its way through the %^BOLD%^%^BLACK%^gnarled"
" %^RESET%^%^GREEN%^old trees that twist their way eerily towards"
" the unseen sky above.  %^RESET%^%^ORANGE%^Fallen trees"
" %^GREEN%^litter the ground around you, and a heavy,"
" %^BLUE%^oppressive %^GREEN%^feeling seems to fill the air here."
"  More than a few vines grow heavily in this area, almost as if they were hiding something."
"%^RESET%^\n");
  set("night long","%^RESET%^%^BLUE%^This %^GREEN%^forest %^BLUE%^is even %^BOLD%^%^BLACK%^darker %^RESET%^%^BLUE%^at night, with"
" absolutely no moonlight touching the forest floor around you. "
" %^BOLD%^%^BLACK%^Shadows %^RESET%^%^BLUE%^dance seductively in"
" the darkness, beckoning you to come further into their midst,"
" and the trees even seem to take on a more eerie twist as they"
" hover overhead.  The vines that grow here even take on an eerie twist, looking like twisting, live snakes clinging to the trees.%^RESET%^\n");
  set_smell("default","You smell dank vegetation.%^RESET%^");
  set_listen("default","The wind whistles through the trees.");
  set_items(([
     ({"floor","forest floor"}):"%^BOLD%^%^BLACK%^Shadows dance across the forest floor, making it difficult to see much.%^RESET%^",
     ({"forest","tree","trees"}):"%^RESET%^%^ORANGE%^The trees here are old and gnarled, twisted in deformed ways that give off a %^BOLD%^%^BLACK%^spooky %^RESET%^%^ORANGE%^feeling.%^RESET%^",
     ({"light","lights"}):"%^RESET%^%^BLUE%^The only %^RESET%^light %^BLUE%^that manages to make its way through the dense %^GREEN%^canopy %^BLUE%^looks more like fine %^RESET%^spiderwebs %^BLUE%^falling from the sky.",
      "fallen trees":"%^GREEN%^Many fallen trees litter the ground here, most are %^ORANGE%^rotting %^GREEN%^and covered with moss.%^RESET%^",
      "vines":"The vines are unusually thick and seem to almost be concealing something.  Looking more closely, it looks like you can enter their twisting masses.",
]));
}

void init(){
  ::init();
  add_action("enter","enter");
}
int enter(string str){
   if(str == "vines"||str=="the vines"){
   if(sizeof(TP->query_attackers()) != 0){
      tell_object(TP,"%^BOLD%^You're a little too busy right now!");
      return 1;
   }
   tell_object(TP,"%^RESET%^%^GREEN%^You carefully move the vines out of your way and walk through them.%^RESET%^");
   tell_room(TO,"%^RESET%^%^GREEN%^"+TPQCN+" carefully moves some vines out of the way and disappears into the forest!",TP);
   this_player()->move_player(INRMS+"base");
   return 1;
   }
}
