#include <std.h>
#include "../dragon.h";

inherit BBOTTOM;

void create() {
   ::create();
   set_long(
      "%^BOLD%^%^BLACK%^The ceiling as caved in on the long hallway leading norththwards."+
      " The water is uncomfortably deep here and it seems this is where the ceiling"+
      " gave in to whatever flooding took place on the floor above. When you try"+
      " to get a look at the floor above, all you see is the rubble that piles down"+
      " onto the floor."
   );
   set_items( ([
      "rubble" : "When you look through the rubble, you manage to find a hole that lets you see a set of stairs on the other side."
   ]) );
   set_exits( ([
      "southwest" : TOWER+"bottom01",
   ]) );
}
