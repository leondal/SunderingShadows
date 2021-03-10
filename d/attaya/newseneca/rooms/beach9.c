//beach9.c - ~Circe~ 6/15/08 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit STORAGE"beach";

void create(){
   ::create();
   set_long(::query_long()+"The small %^ORANGE%^hut %^RESET%^stands "+
      "just northeast of here, though there does not seem to be any "+
      "entrance from the western side.  You do, however, see an "+
      "open window there along with a %^BOLD%^sign%^RESET%^.\n");
   set_exits(([
      "west" : ROOMS"beach8",
      "northwest" : ROOMS"beach3",
      "north" : ROOMS"beach4",
      "east" : ROOMS"beach10",
      "southwest" : ROOMS"shore4",
      "south" : ROOMS"shore5",
      "southeast" : ROOMS"shore6"
   ]));
   add_item("sign","You cannot read the sign from here.");
   add_item("hut","The hut is crafted from weathered wood left in "+
      "its natural hue.  The roof is made from woven leaves, which "+
      "have aged to be the same color as the building now.  The "+
      "western wall of the building has an open, glassless window "+
      "with a small counter for a ledge that "+
      "allows the occupants inside to conduct business with those "+
      "outside, while a %^BOLD%^sign %^RESET%^posted on the wall "+
      "explains what sort of business that might be.  The southern "+
      "wall has a doorway leading to the interior of the hut.");
}