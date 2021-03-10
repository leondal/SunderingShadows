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
   ]) );
   set_exits( ([
      "northwest" : TOWN+"road15",
      "west" : TOWN+"road17",
      "southeast" : TOWN+"road18"
   ]) );
}
