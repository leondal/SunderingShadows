
#include <std.h>

#include "/d/stella/short.h"

inherit ROOM;
int carving_gone, guarded, attempted;

void init(){
    ::init();
    add_action("summon_guardian","summon");
    if (interactive(TP)) {
	do_random_encounters(({MPATH"mund.c"}),10,1);
    }
}

void reset(){
    ::reset();
    carving_gone = 0;
    guarded = 1;
    attempted = 0;
    add_item("carving","From here, you are sure that the carving is an elaborate fanciful dragon.");
    add_item("dragon","From here, you are sure that the carving is an elaborate fanciful dragon.");
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
	({"carving","dragon"}):"From here, you are sure that the carving is an elaborate fanciful dragon.  "
      ]));
    set_exits(([
	"northeast": RPATH "court2",
	"northwest": RPATH "court4",
	"south": RPATH "tower1"
      ]));
    carving_gone = 0;
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
	TP->set_disable(30);
	guarded = 0;
	return 1;
    }

    else if (attempted) {
	tell_object(TP,"You say the words, but somehow there seems to be no power in them!");
	return 1;
    }
    attempted = 1;
    if ((str=="draconis")&&(!carving_gone)){
	say("\n%^BOLD%^As the name \"Draconis\" is spoken, the air shimmers around "
	  "the elaborate dragon carving.  \n"
	  "The carving wavers and seperates from the dome ... becoming larger!!\n\n"
	  "Droconis peers down at "+TPQCN+" and blinks a few times.\n\n"
	  "Draconis says \"Thank you for freeing me at last!  I leave now to take up "
	  "my post.\"\n"
	  "Draconis says \""+TPQCN+", here is a token of my appreciation of your assistance.\"\n",TP);

	tell_object(TP,"\n%^BOLD%^As the name \"Draconis\" is spoken, the air shimmers around "
	  "the elaborate dragon carving.  \n"
	  "The carving wavers and seperates from the dome ... becoming larger!!\n\n"
	  "Droconis peers down at you and blinks a few times.\n\n"
	  "Draconis says \"Thank you for freeing me at last!  I leave now to take up "
	  "my post.\"\n"
	  "Draconis says \"Here is a token of my appreciation of your assistance.\"\n");

	new(OPATH "dractoken.c")->move(TP);
	remove_item("carving");
	remove_item("dragon");
	carving_gone = 1;
	return 1;
    }
    else {
	notify_fail("Summon who?\n");
	return 0;
    }
    return 1;
}
