#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit TROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_long("%^RED%^"
	"The small and narrow chamber is made of the same %^BOLD%^"
	"blood-red%^RESET%^%^RED%^ stone as seen in other parts of the tower. "
	"The stone calls out to you as though it is alive and held captive in "
	"an endless state of torment. A few small black %^CYAN%^candles%^RED%^ "
	"lay flickering on the floor creating an array of %^BLUE%^shadows%^RED%^ "
	"which dance "
	"wildly upon the walls. A long dark spiral staircase leads down into "
	"the darkness."
	"%^RESET%^" 
    );
    set_short("%^RED%^Tower Stairwell%^RESET%^");
    set_listen("default",
        "The sound of something dripping fills the stairwell."
    );
    set_smell("default",
        "A stale but cool breeze flows through the room."
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
	"staircase":"The staircase leads down into the darkness.",
    ]));
    set_exits(([
        "south": RPATH "e10",
        "down": RPATH "d12",
    ]));

    set_pre_exit_functions(({"south"}),({"exitb_fun"}));
    set_pre_exit_functions(({"down"}),({"exita_fun"}));
}
int exita_fun() {
    write(
	"%^BLUE%^You slowly climb the creaking stairs down into the darkness.%^RESET%^"
    );
    say(
	"%^BLUE%^"+TPQCN+" looks around nervously, then heads down the stairs.%^RESET%^"
    ,TP);
    return 1;
}
int exitb_fun() {
    write(
	"%^RED%^A blast of heat surrounds you as you move south.%^RESET%^"
    );
    say(
	"%^RED%^"+TPQCN+" cackles evilly and heads south!%^RESET%^"
    ,TP);
    return 1;
}
