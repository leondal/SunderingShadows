#include <std.h>
#include "../yntala.h"
inherit ROOM;
int searched;

void create()
{
   ::create();
   set_property("light",2);
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
   set_name("%^RESET%^%^ORANGE%^On a path through the thorns%^RESET%^");
   set_short("%^BOLD%^%^ORANGE%^A pathway through a wall of thorns%^RESET%^%^");
   set_long((:TO,"ldesc":));
   set_smell("default","%^BOLD%^%^BLACK%^You can smell cooking fish.%^RESET%^");
   set_listen("default","You can hear children somewhere in the background.");
   set_items(([
   ({"thorns","thornbushes"}):"%^RESET%^%^ORANGE%^The thornbushes twist wickedly between the trees and plants. A few tufts of %^RESET%^fur %^ORANGE%^hang off of a few especially pointy thorns.%^RESET%^",
   ({"tree","trees"}):"%^RESET%^%^GREEN%^The trees here are dark and dense, with %^ORANGE%^thornbushes %^GREEN%^twisting in between them.%^RESET%^",
   "undergrowth":"%^GREEN%^The undergrowth here is thick and tries to compete for light with the numerous %^ORANGE%^thornbushes.%^RESET%^",
   ({"fur","tufts of fur"}):"A few tufts of fur hang off of the %^RESET%^%^ORANGE%^thorns %^RESET%^here.",
   "path":"%^GREEN%^The path is very narrow, but clear of thorns.%^RESET%^",
]));
   set_search("default","%^RESET%^%^ORANGE%^Something in the thornbushes catches your attention.%^RESET%^");
   set_search("thorns",(:TO,"search_pile":));
   set_search("thornbushes",(:TO,"search_pile":));
   set_exits(([
"east":INRMS"meadowedge1",
"west":INRMS"forest21"
]));
}

void reset() {
   ::reset();
   searched = 1 ;
   if(!present("centaur")){
   new(TMONDIR+"centaurg.c")->move(TO);
   }
}
void search_pile() {
   if(searched <= 0) {               
	  tell_object(TP,"It looks like this area has been searched already.");
        return ;
   }

   if (searched == 1) {  
      write("%^RESET%^%^ORANGE%^You found a bracelet in the twisted thorns!\n");
      tell_room(TO,""+TPQCN+" searches around and finds a bracelet in the thorns.", TP);
      new(OBJD+"brambleb.c")->move(TO);
      searched = 0;
   return ;
   }
}
string ldesc(string str){
   return("%^RESET%^%^ORANGE%^You have made your way into a path through a wall of thornbushes.  The thorns twist and turn in all directions throughout the %^GREEN%^trees %^ORANGE%^and %^GREEN%^undergrowth, %^ORANGE%^making it impossible to pass through them any other way.%^RESET%^\n");
} 

