#include <std.h>
#include "../../elfisland1.h";
inherit BTOWN;

void create() {
   ::create();
   set("long",
      "%^RESET%^%^GREEN%^The trees seem decorated all around you. Many of the trees"+
      " are lined with carved staircases with handrails for support. Each of the staircases"+ 
      " spiral up the sides of trees and leads up into treetop homes."+
      " There are some homes that are on ground level at the base of the trees,"+
      " but it is not very common."
   );
   set_items( ([
      "staircases":"These stairs are carved from the trees themselves and spiral up into the homes of the elves.",
      "homes":"These homes are set inside trees hollowed out by elven magic that lets the elves live in the trees without hurting the growth of the tree.",
      "trees":"The trees here have been grown into homes.  Some are set further back in the forest than others.",
   ]) );
   set_exits( ([
      "northwest" : TOWN+"road16",
      "south" : TOWN+"road19"
   ]) );
   set_search("trees","%^RESET%^%^GREEN%^There is a path leading further into the forest here.%^RESET%^");
}
void init(){
  ::init();
  add_action("walk","walk");
}
int walk(string str){
   if(str == "forest"||str=="into the forest"||str=="into forest"){
   tell_object(TP,"%^RESET%^%^GREEN%^You feel adventurous and walk into the surrounding forest.%^RESET%^");
   tell_room(TO,"%^RESET%^%^GREEN%^"+TPQCN+" disappears into the surrounding forest.",TP);
   this_player()->move_player("/d/player_houses/ramius/rooms/ram1");
   return 1;
   }
}

