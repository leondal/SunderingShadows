#include <std.h>
#include <daemons.h>

#include "/d/dagger/marsh/tower/short.h"
inherit TROOM;
int FLAG,GRIM;
void init() {
    ::init();
    add_action("word_fun","say");
}
void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_long("%^MAGENTA%^You float within a cloud of %^BOLD%^purple swirling fog%^RESET%^%^MAGENTA%^. "
	"Before you stands two large stone doors covered in %^RED%^glowing glyphs%^MAGENTA%^. "
	"You can feel a powerful evil beyond the doors, but there appears to be no means of "
	"opening them. Deep inside your mortal soul you know that Vecna's resting ground is close."
	"%^RESET%^"
    );
    set_short("%^MAGENTA%^Within the Fog%^RESET%^");
    set_listen("default",
        "A loud howling can be heard coming from behind the doors."
    );
    set_smell("default",
        "The cold damp air from behind the doors smells horrible."
    );
    set_items(([
	"fog":"The fog you float in swirls all around you.",
	"doors":"The large stone doors are held together by magical glyphs "
	"to prevent them from opening.",
	"glyphs":"The glyphs are of the type that keep doors fastened magically until "
	"a certain word is utilized in their opening.",
	"floor":"There is no floor!",
	"ceiling":"There is no ceiling!",
    ]));
    set_exits(([
	"down": RPATH "e7",
    ]));
    set_pre_exit_functions(({"down"}),({"exitdown_fun"}));
    if(objectp(TO)) { new("/d/dagger/marsh/tower/mon/grimmy.c")->move(TO); }
}

int exitdown_fun() {
    if(TP->query_property("demongate flying") < 1) {
	TP->move_player( RPATH "a7" );
	message("info",
	    "%^CYAN%^"
	    "You fall through the hole and land roughly on several spikes!%^RESET%^"
	,TP);
	message("info",
	    "%^CYAN%^"
	    +TPQCN+" is an idiot!%^RESET%^"
	,ETP,TP);
	TP->do_damage("torso",700);
        TP->check_on_limb ( "torso" );
	return 0;
    } else {
	message("info",
	    "%^CYAN%^"
	    "You slowly fly down through the open floor.%^RESET%^"
	,TP);
	message("info",
	    "%^CYAN%^"
	    +TPQCN+" slowly flies down through the open floor.%^RESET%^"
	,ETP,TP);
	return 1;
    }
}
int word_fun(string str) {
    new("/cmds/mortal/_say.c")->cmd_say(str);
    if(str!="vertisdun")
        return 1;
    if(FLAG != 1) {

	message("info",
	    "%^MAGENTA%^With a slow shudder the ancient doors swing open.\nAn %^GREEN%^evil mist"
	    "%^MAGENTA%^ slowly seeps out from behind them.%^RESET%^"
	,TP);
	message("info",
	    "%^MAGENTA%^"+TPQCN+" speaks a phrase and the ancient doors swing slowly open with a shudder.\n"
	    "An %^GREEN%^evil mist%^MAGENTA%^ slowly seeps out from behind them.%^RESET%^"
        ,ETP,TP);
        TO->add_exit( RPATH "gate","doors" );
        message("users",
	    "%^BOLD%^%^BLACK%^An ancient evil slowly awakens and casts its eye upon Shadowgate.%^RESET%^"
        ,users());
        FLAG = 1;
        set_long(
            "%^MAGENTA%^You float within a cloud of %^BOLD%^purple swirling fog%^RESET%^%^MAGENTA%^. "
	    "Before you, standing open, are two large stone doors covered "
	    "in %^RED%^glowing glyphs%^MAGENTA%^. "
	    "A powerful evil, in the form of a swirling black mist, seeps slowly from within "
	    "the blackness behind the doors. Deep inside your mortal soul you know that Vecna's "
	    "resting ground is close."
	    "%^RESET%^");

        WORLD_EVENTS_D->inject_event((["Waking An Ancient Evil" : (["start message" : "%^BOLD%^%^BLACK%^Creatures across the world are angry and "+
        "more powerful.... Something has %^BOLD%^%^WHITE%^awoken%^BOLD%^%^BLACK%^ an ancient %^BOLD%^%^RED%^EVIL%^BOLD%^%^BLACK%^!%^RESET%^",
        "event type" : "monster modifications", "length" : 120,
        "notification" : "More dangerous monsters!", "event name" : "Waking An Ancient Evil", "modifier" : (["strength" : 2, "dexterity" : 2, "intelligence" : 2,
        "wisdom" : 2, "constitution" : 2, "charisma" : 2, "level" : 2, "health" : roll_dice(3,10)]), "announce" : 1, "announce to" : "world" ]),]));
        return 1;
    }
    return 1;
}
void reset() {
    ::reset();
    FLAG = 0;
    set_long("%^MAGENTA%^"
	"You float within a cloud of %^BOLD%^purple swirling fog%^RESET%^%^MAGENTA%^. "
	"Before you stands two large stone doors covered in %^RED%^glowing glyphs%^MAGENTA%^. "
	"You can feel a powerful evil beyond the doors, but there appears to be no means of "
	"opening them. Deep inside your mortal soul you know that Vecna's resting ground is close."
	"%^RESET%^"
    );
}
