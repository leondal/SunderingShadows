#include <std.h>
#include "../dragon.h";

inherit BTOWER;

void create() {
   ::create();
   set_long(
      "%^RESET%^This massive chamber is lit by light orbs which"+
      " are placed along the walls in perfect intervals. Large"+
      " %^BOLD%^%^WHITE%^pillars %^RESET%^are holding the ceiling of the tower up and the"+
      " marble floors glow in a sparkling light. A long carpet"+
      " starts off wide, but narrows down as it heads north."+
      " There is a small circle of stones here on the floor."
   );
   set_items( ([
      "pillars" : "These are large marble pillars which support the ceiling of the tower.",
      "carpet" : "This plush red carpet is wide and flows onward to the north.",
      ({"circle","circle of stones"}) : "Stones are laid out in a circular pattern, with exact spacing inbetween each stone."
]) );
   set_exits( ([
      "north" : TOWER+"final",
   ]) );
}
