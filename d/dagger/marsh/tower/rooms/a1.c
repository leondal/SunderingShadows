//Set to load fog1.c to allow Grimmy to come out an play earlier - Octothorpe 7/18/09
#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit TROOM;
object ob;
void init() {
    ::init();
    add_action("message_fun","read");
    }
void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_long("%^RED%^"
	"The front ante-chamber of what must be the inside of the tower-like "
	"shadowy column, is made from a polished %^BOLD%^blood-red%^RESET%^%^RED%^ "
	"stone. Three narrow passageways head into the darkness to the north. "
	"To the south, a swirling, chaotic and shadowy "
	"%^GREEN%^mist%^RED%^ "
	"appears to shroud "
	"an opening which you pray leads back to the outside of this mysterious "
	"place of despair. A %^RESET%^skeleton%^RED%^ lays upon the "
	"floor, an arm "
	"outstretched with one bony finger uncurled from it's claw and a sinister "
	"snarl permanently etched into the jaw of this fallen warrior. Upon "
	"the west wall %^CYAN%^a message%^RED%^ has been engraved, perhaps "
	"a final warning to those who try to tread here while still walking among "
	"the living.%^RESET%^"
    );
    set_short("%^RED%^Tower Ante-chamber%^RESET%^");
    set_listen("default",
        "It is dead silent, as though sound itself fears to enter here."
    );
    set_smell("default",
        "You sense the presense of a powerful and decrepit evil."
    );
    set_items(([
	"stone":"%^RED%^The stone used to form the chamber is made from an unknown "
	"material and seems to glow in it's blood-red colour. As you gaze upon it, "
	"you hear the distant laughter of Grazzt.%^RESET%^",
	"mist":"%^GREEN%^The swirling mist covers the opening to the south.",
	"skeleton":"The skeleton of a fallen warrior lays upon the ground, grinning "
	"and pointing.",
	"finger":"The skeleton seems to be pointing to the north.",
	"claw":"The skeleton's claw of a hand remains closed into a fist, except "
	"for one long bony finger which lays uncurled and pointing.",
 	"message":"%^CYAN%^The message is a passage or verse. Try reading it.%^RESET%^"
    ]));
    set_exits(([
        "south": "/d/dagger/marsh/swamp/rooms/f_n010_p003",
        "northwest": RPATH "a2",
        "northeast": RPATH "a4",
        "north": RPATH "a3"
    ]));
    set_pre_exit_functions(({"north"}),({"exit_fun"}));
    set_pre_exit_functions(({"northeast"}),({"exitb_fun"}));
    set_pre_exit_functions(({"northwest"}),({"exita_fun"}));
    set_pre_exit_functions(({"south"}),({"GoThroughDoor"}));
    find_object_or_load("/d/dagger/marsh/tower/rooms/fog1");
    set_property("no phase",1);
}

int exit_fun() {
    write("%^BOLD%^%^ORANGE%^You hear a stifled moan come from the "
	"skeleton as you head through the northern passageway.%^RESET%^"
    );
    say("%^BOLD%^%^ORANGE%^As "+TPQCN+" heads north, the skeleton on the floor "
	"looks at you and cackles an eerie laughter.%^RESET%^"
    ,TP);
    return 1;
}
int exita_fun() {
    write("%^RED%^As you head to the northwest, a "
	"%^BOLD%^pillar of fire%^RESET%^%^RED%^ "
	"engulfs you!%^RESET%^"
    );
    say("%^RED%^As "+TPQCN+" heads northwest, a "
	"%^BOLD%^pillar of fire%^RESET%^%^RED%^ "
	"engulfs "
	+TP->query_possessive()+" "
	"body!%^RESET%^"
    ,TP);
    TP->do_damage("torso",50+random(50));
    return 1;
}
int exitb_fun() {
    write("%^RED%^As you head to the northeast, a "
	"%^BOLD%^pillar of fire%^RESET%^%^RED%^ "
	"engulfs you!%^RESET%^"
    );
    say("%^RED%^As "+TPQCN+" heads northeast, a "
	"%^BOLD%^pillar of fire%^RESET%^%^RED%^ "
	"engulfs "
	+TP->query_possessive()+" "
	"body!%^RESET%^"
    ,TP);
    TP->do_damage("torso",50+random(50));
    return 1;
}
int message_fun(string str) {
    if(!str) {
	notify_fail("Read what?\n");
	return 0;
    }
    if(str != "message") {
	notify_fail("Read what?\n");
	return 0;
    }
    write("%^BOLD%^%^BLUE%^You make out the scrawled message to read:\n\n"
	"%^RED%^"
	"    Just a babe in a black abyss,\n"
	"    No reason for a place like this,\n"
	"    The walls are cold and souls cry out in pain.\n\n"
	"    An easy way for the blind to go,\n"
	"    A clever path for the fools who know,\n"
	"    The secret of the hanged man...the smile on his lips.\n\n"
	"%^RESET%^"
    );
    say("%^RED%^"
	+TPQCN+" reads the message on the wall.%^RESET%^"
    ,TP);
    return 1;
}
int GoThroughDoor(){
object KEY;
    if(!KEY = present("mist_key",TP)) {
	write("%^CYAN%^The mist prevents your passage south!%^RESET%^");
	return 0;
    }
    write("%^CYAN%^The key in your possession hums as you slip through "
	"the mist.%^RESET%^"
    );
    say("%^CYAN%^"+TPQCN+" slips through the mist to the south.%^RESET%^"
    ,TP);
    KEY->remove();
    return 1;
}
