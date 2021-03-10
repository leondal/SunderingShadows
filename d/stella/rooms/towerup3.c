
#include <std.h>

#include "/d/stella/short.h"

inherit ROOM;
int nest_item_found;
int guarded, attempted;

void reset(){
        ::reset();
	guarded = 1;
	attempted = 0;
	nest_item_found = 0;
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
      set_property("indoors",1);
      set_property("light",2);
      set_terrain(STONE_BUILDING);
      set_travel(PAVED_ROAD);
      set_name("Upper Tower");
      set_short("%^BLUE%^Upper Tower");
      set_long(
	     "%^BLUE%^You have entered the upper floor of one of the tall "
	     "guard towers which stand at the four corners of the castle.  "
	     "You can see long-unused arrow slits here for castle defense.  "
	     "There are doors opening onto the walkways which stretch along "
	     "the tops of the castle walls and connect the four towers.  The "
           "ceiling is quite high here."
      );
      set_listen("default",
        "You can still hear faint bird song from the garden."
      );
      set_smell("default",
        "It smells musty and unused in here."
      );
      set_items(([
	"ceiling":"You peer up at the ceiling and notice a trapdoor!",
	"trapdoor":"You realize that this tower must have a roof and that this is the way up.",
        "wall":"The wall is made entirely out of large blocks of rose and grey marble.  It "
           "is somehow both beautiful and intimidating at the same time.  That castle was built "
           "for strength as well as beauty.",
	"stairs":"The stairs wind down through the floor in a tight spiral",
        "courtyard":"From here, the courtyard looks as deserted as the rest of the castle",
	({"arrow slit","slit","slits","arrow slits"}):"You can tell that these haven't been used in "
	   "a long time because a bird has made a nest in one!",
	"nest":"The nest has seen recent use.  You think you can see something in the nest.  "
       ]));
      set_search("nest", (:TO,"search_nest":) );
      set_exits(([
         "southeast": RPATH "wall2",
         "southwest": RPATH "wall3",
	 "down": RPATH "tower3",
	 "trapdoor": RPATH "roof3"
       ]));
      set_invis_exits( ({"trapdoor"}) );
      set_pre_exit_functions( ({"trapdoor"}), ({"go_up"}) );
}

int go_up(){
      tell_object(TP,"You climb to the roof through a trapdoor.");
      say(TPQCN+ "climbs through a trapdoor.",TP);
      return 1;
}

void search_nest(){
  int item;

      if (!nest_item_found) {
	item = random(3)+1;
	switch(item) {
/*
	case 1:
          say(TPQCN +" finds something in a nest!\n",TP);
          tell_object(TP,"You find a lilac bloom in the nest!\n");
          new(OPATH "lilac.c")->move(TP);
          nest_item_found = 1;	  
	  return;
*/
	case 2:
          say(TPQCN +" finds something in a nest!\n",TP);
          tell_object(TP,"You find a hoard of gold in the nest!\n");
	  TP->add_money("gold",1000);
          nest_item_found = 1;	  
	  return;
        case 3:
          say(TPQCN +" finds something in a nest!\n",TP);
          tell_object(TP,"You find a note in the nest!\n");
          new(OPATH "note.c")->move(TP);
          nest_item_found = 1;	  
	  return;
	}
      } else {
          tell_object(TP,"You find nothing more in the nest!\n");
      }
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
