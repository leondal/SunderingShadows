#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit TROOM;

void create() {
    ::create();
   set_travel(STAIRWAY);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_long("%^RED%^"
	"The small and narrow chamber is made of the same %^BOLD%^"
	"blood-red%^RESET%^%^RED%^ stone as seen in other parts of the tower. "
	"The stone calls out to you as though it is alive and held captive in "
	"an endless state of torment. A few small black %^CYAN%^candles%^RED%^ "
	"lay flickering on the floor creating an array of shadows which dance "
	"wildly upon the walls. A long dark spiral staircase leads up into "
	"the darkness."
	"%^RESET%^" 
    );
    set_short("%^RED%^Tower Stairwell%^RESET%^");
    set_listen("default",
        "The sound of something dripping comes from up the stairs."
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
	"staircase":"The staircase leads up into the darkness.",
    ]));
    set_exits(([
        "south": RPATH "a13",
        "up": RPATH "b1",
    ]));

    set_pre_exit_functions(({"south"}),({"exitb_fun"}));
    set_pre_exit_functions(({"up"}),({"exita_fun"}));
}
int exita_fun() {
    if(present("vampyre")) {
        write("The vampyre blocks your way!\n");
        return 0;
    }
    write(
	"%^BLUE%^You slowly climb the creaking stairs up into the darkness.%^RESET%^"
    );
    say(
	"%^BLUE%^"+TPQCN+" looks around nervously, then heads up the stairs.%^RESET%^"
    ,TP);
    return 1;
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
