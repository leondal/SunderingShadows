#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit TROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_long("%^RED%^"
	"The intersection of hallways is made of the same %^BOLD%^"
	"blood-red%^RESET%^%^RED%^ stone as seen in other parts of the tower. "
	"The stone calls out to you as though it is alive and held captive in "
	"an endless state of torment.\n%^CYAN%^The ceiling and the floor is "
	"non-existant here; instead a large hole leads up into the darkness and another down. "
	"%^RESET%^" 
    );
    set_short("%^RED%^Tower Chute Chamber%^RESET%^");
    set_listen("default",
        "A loud howling can be heard coming from above you."
    );
    set_smell("default",
        "The cold damp air from above smells horrible."
    );
    set_items(([
	"stone":"%^RED%^The stone used to form the chamber is made from an unknown "
	"material and seems to glow in it's blood-red colour. As you gaze upon it, "
	"you hear the distant laughter of Grazzt.%^RESET%^",
	"floor":"There is no floor!",
	"ceiling":"There is no ceiling!",
    ]));
    set_exits(([
        "north": RPATH "c8",
	"up": RPATH "d6",
	"down": RPATH "b8",
    ]));

    set_pre_exit_functions(({"north"}),({"exita_fun"}));
    set_pre_exit_functions(({"up"}),({"GoThroughDoor"}));
    set_pre_exit_functions(({"down"}),({"exitdown_fun"}));
}
int exita_fun() {
    write("%^BOLD%^%^BLUE%^"
	"A scream of unearthly volume rings out from the hole in "
	"the ceiling behind you.%^RESET%^"
    );
    say("%^BOLD%^%^BLUE%^"
	"A high pitched scream fills the room.%^RESET%^"
    ,TP);
    return 1;
}
int GoThroughDoor() {
    if(TP->query_property("demongate flying") == 0) {
	write("%^CYAN%^"
	    "You jump up and down and flap your arms like an idiot!%^RESET%^"
	);
	say("%^CYAN%^"
	    +TPQCN+" jumps up and down and flaps "
	    +TP->query_possessive()+
            " arms like an idiot!%^RESET%^"
	,TP);
	return 0;
    } else {
	write("%^CYAN%^"
	    "You fly up through the open ceiling.%^RESET%^"
	);
	say("%^CYAN%^"
	    +TPQCN+" slowly flies up through the open ceiling.%^RESET%^"
	,TP);
	return 1;
    }
}
int exitdown_fun() {
    if(TP->query_property("demongate flying") < 1) {
	TP->move_player( RPATH "a7" );
	write("%^CYAN%^"
	    "You fall through the hole and land roughly on several spikes!%^RESET%^"
	);
	say("%^CYAN%^"
	    +TPQCN+" is an idiot!%^RESET%^"
	,TP);
	TP->do_damage("torso",50);
	return 0;
    } else {
	write("%^CYAN%^"
	    "You slowly fly down through the open floor.%^RESET%^"
	);
	say("%^CYAN%^"
	    +TPQCN+" slowly flies down through the open floor.%^RESET%^"
	,TP);
	return 1;
    }
}
