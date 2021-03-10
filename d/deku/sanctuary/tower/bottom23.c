#include <std.h>
#include "../dragon.h";

inherit BBOTTOM;

void create() {
   ::create();
   set_long(
      "%^BOLD%^%^BLACK%^The ceiling as caved in on the long hallway leading souththwards."+
      " The water is uncomfortably deep here and it seems this is where the ceiling"+
      " gave in to whatever flooding took place on the floor above. When you try"+
      " to get a look at the floor above, all you see is the rubble that piles down"+
      " onto the floor."
   );
   set_items( ([
      "rubble" : "The rubble looks rather well set and digging through it would be nearly impossible."
   ]) );
   set_exits( ([
      "northeast" : TOWER+"bottom19",
   ]) );
}
