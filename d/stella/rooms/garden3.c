
#include <std.h>

#include "/d/stella/short.h"

inherit ROOM;
int flower_picked = 0;
int bush_gone, guarded, attempted;
int guarded2, attempted2;

void init(){
    ::init();
//    add_action("pick_flower", "pick");
    add_action("summon_guardian","summon");
}

void reset(){
    ::reset();
    bush_gone = 0;
    guarded = 1;
    attempted = 0;
    add_item("bush","As you examine the bush more closely, you realize it looks like a large "
      "bear!");
    add_item("bear","As you examine the bush more closely, you realize it looks like a large "
      "bear!");
}

void create(){
    ::create();
    set_terrain(GARDEN);
    set_travel(PAVED_ROAD);
    set_name("Castle Garden");
    set_short("%^GREEN%^Castle Garden");
    set_long(
      "%^GREEN%^This is the garden which surrounds the Marble Castle.  "
      "You are walking along a white gravel path which winds through "
      "the garden in-between flower beds, trees, and shrubs.  There is an "
      "odd looking bush here.  "
    );
    set_listen("default",
      "You hear a few birds in the trees and the breeze blowing through the trees."
    );
    set_smell("default",
      "You can smell some lovely flowers!"
    );
    set_smell("flowers",
      "You can smell %^CYAN%^lilac%^RESET%^ and %^RED%^roses%^RESET%^ mixed in with "
      "a variety of other flowers!"
    );
    set_items(([
	({"castle","marble castle"}):"You can see the outer wall of the castle.  ",
	({"bear","bush"}):"As you examine the bush more closely, you realize it looks like a large "
	"bear!",
	"wall":"The wall is made entirely out of large blocks of rose and grey marble.  It "
	"is somehow both beautiful and intimidating at the same time.  That castle was built "
	"for strength as well as beauty.",
	"path":"%^WHITE%^The path is made from white gravel which crunches beneath your feet.%^RESET%^",
	({"flower","flowers","flower beds"}):"There are a variety of flowers, all "
	"artistically arranged into flower beds surrounded by white stone borders",
	"trees":"The trees sway gently in the mild breeze",
	"shrubs":"The shrubs are about waist height and look well tended",
	"lilac":"You see some lovely blue lilac blossoms.  Perhaps you might pick one?",
	"rose":"You see some beautiful red roses.  Perhaps you might pick one?"
      ]));
    set_exits(([
	"northwest": RPATH "garden4",
	"southwest": RPATH "garden2"
      ]));
    bush_gone = 0;
}

int summon_guardian(string str){

    if (present("mundanoid",ETP)){
	tell_object(TP,"The mundanoids attacks before you can finish speaking!");
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

    if ((str=="ursa")&&(!bush_gone)){
	say("\n%^BOLD%^As the name \"Ursa\" is spoken, the air shimmers around "
	  "the bear-shaped bush. \n"
	  "The bush becomes a solid, breathing bear!!\n\n"
	  "Ursa yawns and turns to "+TPQCN+".\n\n"
	  "He says \"Thank you for freeing me at last!  I leave now to take up "
	  "my post.\"\n"
	  "He says \""+TPQCN+", here is a token of my appreciation of your assistance.\"\n",TP);

	tell_object(TP,"\n%^BOLD%^As the name \"Ursa\" is spoken, the air shimmers around "
	  "the bear-shaped bush.  \n"
	  "The bush becomes a solid, breathing bear!!\n\n"
	  "Ursa yawns and turns to you.\n\n"
	  "He says \"Thank you for freeing me at last!  I leave now to take up "
	  "my post.\"\n"
	  "He says \"Here is a token of my appreciation of your assistance.\"\n");

	new(OPATH "ursatoken.c")->move(TP);
	remove_item("bear");
	remove_item("bush");
	bush_gone = 1;
	return 1;
    }
    else {
	notify_fail("Summon who?\n");
	return 0;
    }
    return 1;
}

/*
int pick_flower(string str) {

    if (!str) {
	notify_fail("Pick what?\n");
	return 0; }

    if (str == "flower") {
	notify_fail("Which flower?\n");
	return 0; }

    if ((str != "lilac")&&(str != "rose")) {
	notify_fail("You don't see that here.\n");
	return 0; }

    if (flower_picked) {
	notify_fail("The flowers have all been picked\n");
	return 0; }

    if(present("mundanoid", ETP)) {
	tell_object(TP, "You can't do that with a mundanoid here!!");
	say("The mundanoid knocks down "+TPQCN+" and laughs.", TP);
	guarded2 = 0;
	return 1;
    }
    else if(guarded) {
	tell_object(TP, "A mundanoid appears and attacks you!");
	say("A mundanoid knocks down "+TPQCN+" and laughs.", TP);
	new(MPATH "mund_nw.c")->move(ETP);
	present("mundanoid", ETP)->force_me("kill "+TPQN);
	guarded2 = 0;
	attempted2 = 1;
	return 1;
    }


    if (str=="lilac") {
	say(TPQCN +" bends down and picks a flower!\n",TP);
	tell_object(TP,"You pick a lovely Lilac bloom!\n");
	new(OPATH "lilac.c")->move(TP);
	flower_picked = 1;
	return 1;
    }
    else if (str=="rose") {
	say(TPQCN +" bends down and picks a flower!\n",TP);
	tell_object(TP,"You pick a lovely Rose bloom!\n");
	new(OPATH "rose.c")->move(TP);
	flower_picked = 1;
	return 1;
    }
    return 1;
}
*/
