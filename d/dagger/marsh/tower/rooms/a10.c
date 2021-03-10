#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit TROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_long("%^RED%^"
	"The small and narrow alcove chamber is made of the same %^BOLD%^"
	"blood-red%^RESET%^%^RED%^ stone as seen in other parts of the tower. "
	"The stone calls out to you as though it is alive and held captive in "
	"an endless state of torment. A few small black %^CYAN%^candles%^RED%^ "
	"lay flickering on the floor creating an array of shadows which dance "
	"wildly upon the walls. A small dark hole is present within the ceiling."
	"%^RESET%^" 
    );
    set_short("%^RED%^Tower Alcove%^RESET%^");
    set_listen("default",
        "The sound of something dripping comes from the hole."
    );
    set_smell("default",
        "A stale but cool breeze washes over you from above."
    );
    set_items(([
	"stone":"%^RED%^The stone used to form the chamber is made from an unknown "
	"material and seems to glow in it's blood-red colour. As you gaze upon it, "
	"you hear the distant laughter of Grazzt.%^RESET%^",
	"candles":"%^GREEN%^A few small black %^CYAN%^candles%^GREEN%^ "
	"lay flickering on the floor creating an array of shadows which dance "
	"wildly upon the walls.%^RESET%^",
	"walls":"Shadows dance upon the walls.",
	"shadows":"The shadows sway in and about...almost as though they were alive.",
	"hole":"The hole leads up into the darkness.",
    ]));
    set_exits(([
        "northeast": RPATH "a13",
        "up": RPATH "b3",
    ]));

    set_pre_exit_functions(({"northeast"}),({"exitb_fun"}));
    set_pre_exit_functions(({"up"}),({"GoThroughDoor"}));
}
int GoThroughDoor() {
    if(present("vampyre")) {
        write("The vampyre blocks your way!");
        return 0;
    }
    if(TP->query_property("demongate flying")) return 1;
    if(TP->query_property("levitating")) return 1;		
    write(
	"%^BLUE%^The hole is too far above you to allow access through it.%^RESET%^"
    );
    say(
	"%^BLUE%^"+TPQCN+" takes a wild jump at the hole, but misses!%^RESET%^"
    ,TP);
    return 0;
}
int exitb_fun() {
   if(present("vampyre")) {
        write(
	    "%^BOLD%^%^RED%^Vampyre shouts: Run in fear, "+TPQCN+" you maggot child!%^RESET%^"
	    "\n%^RED%^Vampyre swipes you across the back with his claws as you flee!%^RESET%^"
	);
	say(
	    "%^BOLD%^%^RED%^Vampyre tells you: %^RESET%^You would be wise to "
	    "flee as "+TPQCN+" the maggot child just did!"
	,TP);
	TP->do_damage(TP->return_target_limb(),random(40));
        return 1;
    }
    return 1;
}
