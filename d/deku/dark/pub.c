#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_terrain(BUILT_CAVE);
    set_travel(DIRT_ROAD);
    set_short("The Underground cellar");
    set_long(
@KAYLA
The cavern opens into a 40 by 30 foot chamber with a flat stone ceiling
30 feet overhead.  The chamber is dimly lit, and dark shapes hang above 
you in the air.  The shadowy forms of sacks, barrels, and crates fill
the room stacked to heights above you heads.  Most of them appear to
be empty. The floor is sticky, as if something has been spilled on it
and insects buzz around the room.
KAYLA
    );
    set_exits(([
//      "temple":"/d/magic/temples/shar",
       "enter" : "/d/deku/dark/shar_ruins",
       "south" : "/d/deku/dark/hall4"
    ] ));
    set_smell("default","Smells of salted meat, rotting fruits, moldy breads"
                        " and stale beer assault your noses.");
    set_items(([
       "shapes":"The hanging shapes are skinned animal carcasses suspended"
                " from hooks in the ceiling.",
       "meat":"The meat looks like it has been salted and left to cure, but"
              " it is spoiled.",
       "sacks":"A few sacks are filled with breads, all covered with harmfull"
               " mold."
    ] ));
  set_pre_exit_functions(({"enter"}),({"GoThroughDoor"}));
}
//added in response to bug reports that the hunter was bothering the acolytes.  Circe 12/21/03
int GoThroughDoor(){
        if(TP->id("assassin") || TP->id("hunter")) return 0;
   return 1;
}

