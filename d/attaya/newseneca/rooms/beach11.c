//beach11.c - ~Circe~ 6/15/08 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit STORAGE"beach";

void create(){
   ::create();
   set_long(::query_long()+"The small %^ORANGE%^wooden hut%^RESET%^ "+
      "stands just northwest of here.  This section of the beach "+
      "runs up against the arm of the %^BOLD%^"+
      "%^BLACK%^j%^RESET%^%^ORANGE%^e%^RESET%^t%^BOLD%^t%^BLACK%^y"+
      "%^RESET%^, which extends from the sea and runs northward to "+
      "meet the face of the cliff.\n");
   set_exits(([
      "west" : ROOMS"beach10",
      "southwest" : ROOMS"shore6",
      "south" : ROOMS"shore7"
   ]));
   add_item("hut","The hut is crafted from weathered wood left in "+
      "its natural hue.  The roof is made from woven leaves, which "+
      "have aged to be the same color as the building now.  The "+
      "southern wall has a doorway leading to the interior of the hut.");
}