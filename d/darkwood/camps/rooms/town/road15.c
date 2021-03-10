#include <std.h>
#include "../../elfisland1.h";
inherit BTOWN;

void create() {
   ::create();
   set("long",
      "%^RESET%^%^GREEN%^This little trail serves as a means to get to the market"+
      " from the residential area of the village for the elves that have made this"+
      " area their home. To the north the forest seems to open up into a clearing and"+
      " there appears to be more elven grown structures to the south."
   );
   set_items( ([
      "clearing":"There is a clearing to the north.",
      "structures":"This looks like where the elves have built their homes."
   ]) );
   set_exits( ([
      "north" : TOWN+"road14",
      "southeast" : TOWN+"road16",
      "southwest" : TOWN+"road17"
   ]) );
}
