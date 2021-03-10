//path1.c
#include "../../kildare.h"

inherit TPATH;

void create()
{
   ::create();
   set_long(
@CIRCE
%^BOLD%^%^CYAN%^A Small Clearing
%^RESET%^%^CYAN%^A small clearing opens up just before a cave 
leading into the side of this peak.  Large rocks have been cleared 
away and piled to the sides, making this a shelter from the wind.  
The rocky ground in the middle is dotted with clumps of grass, 
and a few gnarled bushes stand along the edge.  In the distance, 
a few taller peaks rise above this place, dotted with evergreen 
trees.  A small path runs away from the cave to the northeast, and 
small stone buildings can be seen in that direction.
CIRCE
    );

    set_exits(([
        "cave" : ROOMS"cave9",
      "northeast" : TROOMS"path2"
        ]));

}
