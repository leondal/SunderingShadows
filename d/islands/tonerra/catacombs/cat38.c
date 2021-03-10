#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit CAT;

void create(){
  ::create();
  set_indoors(1);
  set_light(1);
  set_short("Catacombs");
  set_long(
@DESC
%^BLUE%^You are walking through the catacombs beneath the
old monastery. There are a few small torches giving off
some light but you cannot see very much in this part of
the catacombs. Walkways lead in all directions.
DESC
  );
  set_listen("default","You hear some small creatures scurrying among the remains.");
  set_smell("default","You smell the rotting remains all around you.");
  set_exits(([
    "north":CATACOMBS+"cat39",
    "south":CATACOMBS+"cat14",
  ]));
  set_items(([
    "bones":"Skeletons lie rotting all around you.",
    "slabs":"Stone slabs holding skeletons line the walls."
  ]));
}
