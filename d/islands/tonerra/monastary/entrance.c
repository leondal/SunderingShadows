//entrance.c

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"


inherit ROOM;

void create(){
   ::create();
  set_properties((["indoors": 1,"light":0, "used sticks":1]));
  set_terrain(STONE_BUILDING);
  set_travel(PAVED_ROAD);
   set_short("The aged entrance to the monastery");
   set_long(
@OLI
   %^GREEN%^The aged entrance to the monastery%^RESET%^
%^RESET%^You stand in the entrance way to the ancient monastery. For
countless generations, monks have studied the arts of combat,
weaponry and self discipline here. Only a few are allowed to enter
and even fewer succeed in their goals. A great %^BOLD%^%^BLACK%^circle%^RESET%^ is drawn on
the floor here. A %^BOLD%^%^GREEN%^serpentine line%^RESET%^ cuts through the middle, reminding
you of a battle between %^BOLD%^%^BLACK%^dark%^RESET%^ and %^BOLD%^light%^RESET%^. The passage
extends northeast and northwest.
OLI
   );
   set_smell("default","Insence is burning around you.");
   set_listen("default","A low chant echoes to your ears.");

   set_exits(([
   "northeast":MONASTERY+"hall1",
   "northwest":MONASTERY+"hall9",
   "south":MONASTERY+"stairs"
   ]));

   set_items(([
   "circle":"This is a great Tai chi chu painted on the floor. You see the battle between the darkness and light struggling.",
   ]));
}

void reset(){
   ::reset();
}
