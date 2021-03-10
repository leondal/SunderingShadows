#include <std.h>
#include "short.h"

inherit CITYOUT;

void create() {
   ::create();
   set_short("Bell tower");
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_long(
@DESC
You stand at the top of the bell tower in the %^CYAN%^Cathedral of Seneca%^RESET%^.  
The city stretches out before you and beyond the city walls the 
ocean glistens in an alluring shade of turquoise. The island of the 
Kinnesaruda lies to the northwest, shrouded in a mysterious fog. 
The enormous bells hang on a metal rod at least two feet thick! They 
are rang by pulling a nearby lever on the floor that is attached to 
a pulley system. The bells have long been used to signal warning 
and invasion.

A notice is posted on the lever base.
DESC
);
   set_exits(([
      "down":"/d/attaya/seneca/church9",
   ]));
   set_items(([
      "bells" : "The bells are enormous and made of brass, they hang into this room from a heavy rod that runs across two brick pyles.",
      "island" : "The island of the Kinnesaruda on Attaya's western coast is a place of extreme danger and mystery.  On a clear day, you can see the Crystalline Tower of the Black Dawn from here.",
      "lever" : "It is a shiny brass lever.",
      "notice" : "It reads: %^BOLD%^The bells may be rung to call a marriage ceremony, signal an invasion in Seneca, or for other emergency gatherings ONLY.",
      "stairs" : "The stairs are made from wood planks and bound by metal wire.  An iron railing gives you some security.",
      "staircase" : "The stairs are made from wood planks and bound by metal wire.  An iron railing gives you some security.",
   ]));
}

void reset() {
   ::reset();
   if(!present("bell 2"))
      new("/d/attaya/seneca/obj/bell")->move(TO);
   new("/d/attaya/seneca/obj/bell")->move(TO);
}
