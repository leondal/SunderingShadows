//cncstable1 - hitching post for Tabor.  Coded by Circe 4/23/04

#include <std.h>
#include "../include/tabor.h"

inherit "/d/common/inherit/hitching_post";

void create() {
  ::create();
  set_terrain(CITY);
  set_travel(DIRT_ROAD);
  set_property("light", 1);  // was 2 but inherit is already 2, stacking to 4 *Styx* 3/7/05
  set_property("indoors", -1);
  set_long(
@TABOR
%^BOLD%^A Hitching Post%^RESET%^
%^GREEN%^This small yard is a grassy, open-air area where horses 
may be tethered.  Here, they can munch on grass and rest 
while their owners relax at the %^YELLOW%^Crown and Castle Inn%^RESET%^%^GREEN%^.  
There are five %^ORANGE%^tethering posts %^GREEN%^here, arranged in a large 
circle with ample space between.  Beside each tethering 
post is a %^ORANGE%^small trough %^GREEN%^filled with %^CYAN%^water%^GREEN%^.

%^RESET%^An open doorway leading to the stable is to the north.
TABOR
  );
  set_items(([
     ({"post","posts","hitching post","hitching posts","tether","tethering post","tethering posts"}) : "There are several posts set up here to tether horses to. They are"+
	" basically long wooden bars that are supported on either end"+
	" that you loop the reins of a horse around to keep them there."+
	" There are three posts all together, all in a row.",
     ({"grass","ground"}) : "%^BOLD%^%^GREEN%^The grass here is vibrant "+
        "green from the natural fertilizer.  It is trampled and kept "+
        "short from the grazing horses.",
     ({"trough","troughs","small trough","small troughs"}) : "%^CYAN%^"+
        "Each of the small troughs is made of varnished wood sealed to "+
        "protect it against the elements.  They are all filled with clear, "+
        "cool water for the enjoyment of the horses.",
  ]));
  set_smell("default","You smell the odor of hay as well as horse manure.");
  set_listen("default","You hear whinnies and neighs of horses.");
  
  set_exits( ([
    "north" : ROOMDIR+"cncstable",
  ]) );
      set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
}
