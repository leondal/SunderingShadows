inherit "/std/food.c";

#include <std.h>
#include "../vesprus.h"


void create(){
   ::create();
  set_name("%^RESET%^rotting fish");
  set_id(({"fish","raw fish","food","old fish","rotten fish"}));
  set_strength(10);
  set_weight(1);
  set_short("%^RESET%^a %^ORANGE%^rotting %^RESET%^raw fish%^RESET%^");
  set_destroy();
  set_long("%^RESET%^%^ORANGE%^This fish doesn't look so fresh anymore.  A slight %^RESET%^slime %^ORANGE%^seems"
" to have built up over the %^RESET%^s%^BOLD%^c%^RESET%^al%^BOLD%^e%^RESET%^s %^ORANGE%^and"
" %^RESET%^glazes %^ORANGE%^the %^BOLD%^%^BLACK%^beady eyes.  %^RESET%^%^ORANGE%^It doesn't look"
" very appetiting at all, and the strong, foul smell arising from it further confirms any suspicions that somebody"
" obviously did not know how to keep fish fresh.%^RESET%^");
  set_your_mess("%^RESET%^%^ORANGE%^picks up the raw, rotting fish and takes a bite right out of the side of it before gagging.%^RESET%^");
  set_my_mess("%^RESET%^%^ORANGE%^You pick up the raw fish and take a bite right out of the side, scales, goo, and"
" all.  The first thing you notice is that it is cold, incredibly salty, and the aweful smell it gives off overrides"
" any sense of taste it may have once had.  ...Then you realize that the consistency is much like a rotten, gooey,"
" slimey banana that has been stepped on and you suddenly feel the urge to vomit.%^RESET%^");
}
