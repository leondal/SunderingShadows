
#include <std.h>

#include "/d/stella/short.h"

inherit ROOM;
int guarded, attempted;


void init(){
	::init();
	guarded = 1;
	attempted = 0;
        if (interactive(TP)) {
	   do_random_encounters(({MPATH"mund.c"}),10,1);
	}
	}

void reset(){
        ::reset();
        if (!present("pony")) new(OPATH "pegasus")->move(TO);
 guarded = 1;
        attempted = 0;
        }

void create(){
      ::create();
      set_property("light",1);
      set_name("Castle Courtyard");
      set_short("%^BLUE%^Castle Courtyard");
    set_terrain(VILLAGE);
    set_travel(DIRT_ROAD);
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
         "northeast": RPATH "court3",
	 "southeast": RPATH "court1",
	 "west": RPATH "tower4",
       ]));
      }

int summon_guardian(string str){

if (member_array("Stellar Quest",TP->query_quests()) >=0 ) {return 0;}


if (present("mundanoid",ETP)){
  tell_object(TP,"The mundanoid attacks before you can finish speaking!");
  say("The mundanoid attacks before "+TPQCN+" can finish speaking!",TP);
  present("mundanoid",ETP)->force_me("kill "+TPQN);
  return 1;
}
else if (guarded) {
  tell_object(TP,"A mundanoid appears and attacks before you can finish speaking!");
  say("A mundanoid appears and attacks before "+TPQCN+" can finish speaking!",TP);
  new(MPATH "mund_nw.c")->move(ETP);
  present("mundanoid",ETP)->force_me("kill "+TPQN);
  guarded = 0;
  return 1;
}
else if (attempted) {
  tell_object(TP,"You say the words, but somehow there seems to be no power in them!");
  return 1;
}
attempted = 1;
  notify_fail("Summon who?\n");
  return 1;
}
