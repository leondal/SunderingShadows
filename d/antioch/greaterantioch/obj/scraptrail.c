#include <std.h>
#include "../gantioch.h"
inherit OBJECT;

create(){
   ::create();
   set_id(({"scraps","scrap","trail","pile","scraps pile","scrap pile"}));
   set_name("scrap trail");
   set_obvious_short("%^RESET%^A pile of scraps");
   set_short("%^RESET%^A pile of scraps");
   set_long(
      "%^RESET%^%^ORANGE%^This looks to be minor pieces of scrap and wreckage that the creautres"+
      " that robbed and destroyed the caravan no longer wanted. It seems to be thrown half-hazardly"+
      " in such a way that a trail may be forming. Perhaps if you follow the pieces you will find where"+
	  " they went."
   );
   set_weight(1000000);
   set_value(1300);
}

