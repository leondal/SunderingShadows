
#include <std.h>

#include "/d/stella/short.h"

inherit ROOM;

void init(){
	::init();
        if (interactive(TP)) {
	   do_random_encounters(({MPATH"mund.c"}),10,1);
	}
	}

void create(){
      ::create();
      set_property("light",1);
      set_terrain(VILLAGE);
      set_travel(PAVED_ROAD);
      set_name("Castle Wall");
      set_short("%^BLUE%^Castle Wall");
      set_long(
	     "%^BLUE%^You are walking along the outer wall of the castle.  "
	     "Ahead of and behind you, you can see entrances to the guard towers.  "
	     "You can see down into the castle courtyard from here.  There is only one "
	     "large, dome-shaped building standing in the middle of the otherwise deserted "
	     "courtyard!  Was this entire castle built to protect that one building?  "
	     "Towards the outside of the castle you can see the castle gardens.  "
      );
      set_listen("default",
        "You can still hear faint bird song from the garden."
      );
      set_smell("default",
        "You take a deep breath of fresh air after those musty towers."
      );
      set_items(([
	({"tower","guard towers"}):"As you look at the guard towers, you notice gargoyles on the roofs",
	({"gargoyle","gargoyles"}):"You can't make out much detail from this distance",
        "wall":"The wall is made entirely out of large blocks of rose and grey marble.  It "
           "is somehow both beautiful and intimidating at the same time.  That castle was built "
           "for strength as well as beauty.",
        "courtyard":"From here, the courtyard looks as deserted except for a dome-shaped building",
	({"dome","building","dome shaped building"}):"The dome seems to made of a single hemisphere "
	   "shaped piece of black marble.  The dome has been intricately carved but you can't see much "
	   "detail from here.  Strangely, the building has no visible windows.  ",
	"garden":"You look down into a beautiful garden containing a variety of flowers."
       ]));
      set_exits(([
         "northwest": RPATH "towerup4",
	 "southeast": RPATH "towerup1"
       ]));
}
