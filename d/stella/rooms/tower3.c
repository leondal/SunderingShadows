
#include <std.h>

#include "/d/stella/short.h"

inherit ROOM;
int painting_gone, guarded, attempted;

void init(){
    ::init();
    add_action("summon_guardian","summon");
    if (interactive(TP)) {
	do_random_encounters(({MPATH"mund.c"}),10,1);
    }
}

void reset(){
    ::reset();
    painting_gone = 0;
    guarded = 1;
    attempted = 0;
    add_item("painting","This is a somewhat faded portrait of a Regal looking woman reclining "
      "on an elegant ottoman");
    add_item("queen","This is a somewhat faded portrait of a Regal looking woman reclining "
      "on an elegant ottoman");
}

void create(){
    ::create();
    set_property("indoors",1);
    set_property("light",2);
      set_terrain(STONE_BUILDING);
      set_travel(PAVED_ROAD);
    set_name("Lower Tower");
    set_short("%^BLUE%^Lower Tower");
    set_long(
      "%^BLUE%^You have entered the lower floor of one of the tall "
      "guard towers which stand at the four corners of the castle.  "
      "This is a room built for function.  There is a table and chairs,  "
      "a rack that once held weapons, and stairs leading to the second floor.  "
      "You can see an inner door leading to the castle courtyard.  There is an "
      "old painting on the wall here."
    );
    set_listen("default",
      "You can still hear faint bird song from the garden."
    );
    set_smell("default",
      "It smells musty and unused in here."
    );
    set_items(([
	({"painting","queen"}):"This is a somewhat faded portrait of a Regal looking woman reclining "
	"on an elegant ottoman",
	"wall":"The wall is made entirely out of large blocks of rose and grey marble.  It "
	"is somehow both beautiful and intimidating at the same time.  That castle was built "
	"for strength as well as beauty.",
	"table":"This is a plain table that looks like it has seen many years of use.",
	({"chair","chairs"}):"the chairslook old, but are still sturdy and strong.",
	"rack":"This rack once held weapons that were ready to be used in defense of the castle.  "
	"The rack is long abandoned now though ... ",
	"stairs":"The stairs wind up through the ceiling in a tight spiral",
	"courtyard":"From here, the courtyard looks as deserted as the rest of the castle"
      ]));
    set_exits(([
	"south": RPATH "court3",
	"up": RPATH "towerup3"
      ]));
    painting_gone = 0;
}

int summon_guardian(string str){

    if (member_array("Stellar Quest",TP->query_quests()) >=0 ) {return 0;}


    if (present("mundanoid",ETP)){
	tell_object(TP,"The mundanoid attacks before you can finish speaking!");
	say("The mundanoid attacks before "+TPQCN+" can finish speaking!",TP);
	present("mundanoid",ETP)->force_me("kill "+TPQN);
	guarded = 0;
	return 1;
    }
    else if (guarded) {
	tell_object(TP,"A mundanoid appears and attacks before you can finish speaking!");
	say("A mundanoid appears and attacks before "+TPQCN+" can finish speaking!",TP);
	new(MPATH "mund_nw.c")->move(ETP);
	present("mundanoid",ETP)->force_me("kill "+TPQN);
	TP->set_disable(30);
	guarded = 0;
	return 1;
    }

    else if (attempted) {
	tell_object(TP,"You say the words, but somehow there seems to be no power in them!");
	return 1;
    }
    attempted = 1;
    if ((str=="cassiopeia")&&(!painting_gone)){
	say("\n%^BOLD%^As the name \"Cassiopeia\" is spoken, the air shimmers around "
	  "the faded painting. \n"
	  "The woman in the painting seems to become three dimensional!!\n\n"
	  "Cassiopeia smiles at "+TPQCN+" warmly.\n\n"
	  "She says \"Thank you for freeing me at last!  I leave now to take up "
	  "my post.\"\n"
	  "She says \""+TPQCN+", here is a token of my appreciation of your assistance.\"\n",TP);

	tell_object(TP,"\n%^BOLD%^As the name \"Cassiopeia\" is spoken, the air shimmers around "
	  "the faded painting.  \n"
	  "The woman in the painting seems to become three dimensional!!\n\n"
	  "Cassiopeia smiles at you warmly.\n\n"
	  "She says \"Thank you for freeing me at last!  I leave now to take up "
	  "my post.\"\n"
	  "She says \"Here is a token of my appreciation of your assistance.\"\n");

	new(OPATH "castoken.c")->move(TP);
	add_item("painting","This is a somewhat faded painting of an empty ottoman");
	remove_item("queen");
	painting_gone = 1;
	return 1;
    }
    else {
	notify_fail("Summon who?\n");
	return 0;
    }
    return 1;
}
