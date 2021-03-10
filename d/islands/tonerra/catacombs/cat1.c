#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit CAT;

void create(){
  ::create();
  set_indoors(1);
  set_light(2);
  set_short("Catacombs");
  set_long(
@DESC
%^BLUE%^You are at the entrance to the catacombs beneath the
old monastery. The light coming down the stair from above 
does not seem to illuminate anything past this part of the
catacombs. 
DESC
  );
  set_listen("default","You hear some small creatures scurrying among the remains.");
  set_smell("default","You smell the rotting remains all around you.");
  set_exits(([
    "south":CATACOMBS+"cat2",
    "up":MONASTERY+"gar5",
  ]));
  set_items(([
    "bones":"Skeletons lie rotting all around you.",
    "slabs":"Stone slabs holding skeletons line the walls."
  ]));
}
