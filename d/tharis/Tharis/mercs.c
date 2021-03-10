//mercs.c

#include <std.h>
#include "../tharis.h"

inherit VAULT;

void create(){
   ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
   set_property("light",2);
   set_property("indoors",1);

   set_short(
@JAVAMAKER
The Mercenary Guild Hall
JAVAMAKER
   );

   set_long(
@JAVAMAKER
   %^BLUE%^The Mercenary Guild Hall%^RESET%^
This room is lined with weapons and armor. To one side you
see a large set of shelves with books in them. In the middle
is a long table with benches along it. There are stacks of halberds,
swords and other such things. You see a large clenched fist in
one corner.
JAVAMAKER
   );

   set_smell("default","You smell the oils and leathers that are common to armories.");
   set_listen("default","You hear the chortles of the lounging mercenaries.");
   set_items(([
      "stacks":"These stacks have everything you could imagine in here. Polearms swords clubs maces arrows quarrels.",
      "table":"This looks like a meeting/eating table.",
      "fist":"This is a statue of a hand clenched into a fist.",
   ]));

   set_exits(([
      "north":ROOMS"a24",
   ]));

   set_invis_exits(({}));
   set_trap_functions(({}),({}),({}));
   set_pre_exit_functions(({}),({}));
   set_post_exit_functions(({}),({}));
   set_door("door",ROOMS"a24","north","blah");
}


void reset(){
   ::reset();

}

void init(){
   ::init();

}







