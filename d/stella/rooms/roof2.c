
#include <std.h>

#include "/d/stella/short.h"

inherit ROOM;
int guarded, attempted;

void reset(){
        ::reset();
	guarded = 1;
	attempted = 0;
	}

void init(){
	::init();
        add_action("summon_guardian","summon");
        if (interactive(TP)) {
	   do_random_encounters(({MPATH"mund.c"}),10,1);
	}
	}

void create(){
      ::create();
      set_property("light",1);
      set_terrain(VILLAGE);
      set_travel(PAVED_ROAD);
      set_name("Tower Roof");
      set_short("%^BLUE%^Tower Roof");
      set_long(
	     "%^BLUE%^You are on the roof of one of the towers!  It is pretty empty here "
	     "except for a stone gargoyle.  You have an incredible view from "
	     "up here.  To the outside you see down into the tower gardens and "
	     "to the inside the courtyard with it's dome-shaped building. "
      );
      set_listen("default",
        "You can still hear faint bird song from the garden."
      );
      set_smell("default",
        "You take a deep breath of fresh air after those musty towers."
      );
      set_items(([
	"gargoyle":"The gargoyle is a two-headed troll with the ugliest faces you've ever seen.",
	"floor":"You lok down at the floor and notice a trapdoor!",
	"trapdoor":"This is the way back into the tower",
        "courtyard":"From here, the courtyard looks as deserted except for a dome-shaped building",
	({"dome","building","dome shaped building"}):"The dome seems to made of a single hemisphere "
	   "shaped piece of black marble.  The dome has been intricately carved but you can't see much "
	   "detail from here.  Strangely, the building has no visible windows.  ",
	"garden":"You look down into a beautiful garden containing a variety of flowers."
       ]));
      set_exits(([
	 "trapdoor": RPATH "towerup2"
       ]));
      set_pre_exit_functions( ({"trapdoor"}), ({"go_down"}) );
      }

int go_down(){
      tell_object(TP,"You climb down from the roof through a trapdoor.");
      say(TPQCN+ "climbs through a trapdoor.",TP);
      return 1;
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
