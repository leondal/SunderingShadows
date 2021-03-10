#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit VAULT;

int entered;
string long_desc();

void create() {
  ::create();
  set_property("indoors", 1);
  set_property("light", 2);
  set_short("An empty chamber");
  set_long((:TO, "long_desc":));
  set_terrain(STONE_BUILDING);
  set_travel(DECAYED_FLOOR);
  set_smell("default","The air is dry, dusty, and very still");
  set_listen("default","You can't hear anything beyond the thudding of"
                      +" your own heart.");

  set_items( ([ 
     ({ "wall", "walls", "block", "blocks"}):
                         "The walls are made from huge blocks of solid"
                         +" granite. It is impressive that these massive"
                         +" blocks were moved at all, even if the"
                         +" stonework itself is a little rough, the"
                         +" uneven surfaces allowing a few cracks or gaps"
                         +" between the blocks",

  ({ "cracks", "gaps", "crack", "gap"}):"The cracks and gaps are quite"
                                       +" small; certainly not big enough"
                                       +" for anyone to pass in between.", 

  "ceiling" : "the ceiling is made of the same gray stone as the walls",

  "floor" :"The floor is smooth, but laid over with a fine film of dust. "

  ]) );

}

