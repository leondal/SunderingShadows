
#include <std.h>

#include "/d/stella/short.h"

inherit ROOM;

void init(){
	::init();
        if (interactive(TP)) {
	   do_random_encounters(({MPATH"mund.c"}),10,1);
	}
	}

void reset(){
        ::reset();
        if (!present("fountain")) new(OPATH "cyg")->move(TO);
        }

void create(){
      ::create();
      set_property("light",1);
      set_name("Castle Courtyard");
    set_terrain(VILLAGE);
    set_travel(DIRT_ROAD);
      set_short("%^BLUE%^Castle Courtyard");
      set_long(
	     "%^BLUE%^You are in the castle courtyard.  It is deserted here except for "
	     "a large, dome-shaped building.  From here, you can see that there is a "
             "guard tower at each of the four corners of the castle.  You cannot see over "
	     "the tall walls that join them."
      );
      set_listen("default",
        "Your footsteps echo in this deserted place."
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
        "courtyard":"The courtyard looks as deserted except for a dome-shaped building",
	({"dome","building","dome shaped building"}):"The dome seems to made of a single hemisphere "
	   "shaped piece of black marble.  The dome has been intricately carved.  Strangely, the "
	   "building has no visible windows.  ",
	"carving":"You can't quite figure out what the carving is ... perhaps from another angle?"
       ]));
      set_exits(([
         "southwest": RPATH "court1",
	 "northwest": RPATH "court3",
	 "east": RPATH "tower2"
       ]));
      }

