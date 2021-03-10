//Octothorpe (2/8/09)
//Underdark Mining Caverns Kobold Cavern Room Delta 2

#include <std.h>
#include "../defs.h"
inherit INH+"kobcavern2";

void create(){
   ::create();
   set_long(::query_long() +"%^BOLD%^ A large hole is found in the "+
      "ceiling of the tunnel at this point.%^RESET%^\n");
   add_item(({"hole"}),"%^BOLD%^%^BLACK%^The edges of the hole are "+
      "completely smooth, yet look somewhat climbable.");
   set_exits(([
      "north":RMS"kobcavernc2",
   ]));
   set_climb_exits(([
      "climb" : ({RMS"nucaverna5",25,20,200}),
   ]));
   set_fall_desc("You land with a good thud on the limestone floor "+
      "below...");
}