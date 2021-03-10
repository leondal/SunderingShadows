//market2.c

#include <std.h>
#include "../tharis.h"

inherit "/d/tharis/Tharis/market";

void create(){
   ::create();
   set_property("light",2);

   set_short(
@JAVAMAKER
The northeast corner of the market
JAVAMAKER
   );

   set_long(
@JAVAMAKER
%^BOLD%^%^BLUE%^The northeast corner of the market%^RESET%^
This is the northeast corner of the Tharis marketplace. Here
vendors shout, each louder than that last. The bustle of the citizens
and the tourists and the foreign merchants and the local merchants
bounces you around not a small bit. There is a sign swinging over
a door to the northeast. The market bustles more to the south and
west.
JAVAMAKER
   );

   set_smell("default","You smell the food from the vendors and the people around you.");
   set_listen("default","The crowd is loud.");
   set_items(([
      "crowd":"This is a busy busy place. Obvisouly a great haven for thieves.",
      "sign":"The sign reads > The singing Merchant, the dancing wench <.",
   ]));

   set_exits(([
      "southwest":ROOMS"market3",
      "northeast":ROOMS"mbar",
      "south":ROOMS"market4",
      "northwest":ROOMS"main8",
      "west":ROOMS"market1",
      "southeast":ROOMS"estreet1",
      "east" : ROOMS"hotel",
   ]));

   set_invis_exits(({}));
   set_trap_functions(({}),({}),({}));
   set_pre_exit_functions(({}),({}));
   set_post_exit_functions(({}),({}));
   set_door("door",ROOMS"mbar","northeast","blah");
   set_open("door",0);
}


void reset(){
   ::reset();

}

void init(){
   ::init();

}







