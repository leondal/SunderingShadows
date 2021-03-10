#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit ROOM;
int CHECK1;
void init() {
    ::init();
    add_action("search_fun","search");
    CHECK1 = 0;
}
void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_long("%^RED%^"
	"The intersection of hallways is made of the same %^BOLD%^"
	"blood-red%^RESET%^%^RED%^ stone as seen in other parts of the tower. "
	"The stone calls out to you as though it is alive and held captive in "
	"an endless state of torment. A few small black %^CYAN%^candles%^RED%^ "
	"lay flickering on the floor in a large circle. The ceiling is "
	"non-existant here; instead a large hole leads up into the darkness. "
	"You wonder how safe it is to stand here where something could fall down "
	"on top of you. Furthermore, the floor is littered with many long sharp "
	"spikes sticking upwards, as though waiting to impale anything which should "
	"have the misfortune to fall from above."
	"%^RESET%^" 
    );
    set_short("%^RED%^Tower Hallway Intersection%^RESET%^");
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
	"candles":"%^GREEN%^A few small black %^CYAN%^candles%^GREEN%^ "
	"lay flickering on the floor in a large circle shape.%^RESET%^",
	"ceiling":"The ceiling is open in a large hole leading into the darkness "
	"above.",
	"spikes":"The floor is littered with numerous spikes.",
    ]));
    set_exits(([
        "north": RPATH "a11",
	"south": RPATH "a3",
        "west": RPATH "a6",
        "east": RPATH "a8",
	"up": RPATH "b8",
    ]));

    set_pre_exit_functions(({"north"}),({"exita_fun"}));
    set_pre_exit_functions(({"south"}),({"exita_fun"}));
    set_pre_exit_functions(({"east"}),({"exita_fun"}));
    set_pre_exit_functions(({"west"}),({"exita_fun"}));
    set_pre_exit_functions(({"up"}),({"GoThroughDoor"}));

}
int exita_fun() {
    write("%^BOLD%^%^BLUE%^"
	"A low, deep howl of pure agony echos down from the hole in "
	"the ceiling behind you.%^RESET%^"
    );
    say("%^BOLD%^%^BLUE%^"
	"A low, deep howl fills the room."
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
int search_fun(string str) {
    if(!str) {
	notify_fail("Search what?\n");
        return 0;
    }
    if(str != "spikes") {
	notify_fail("Search what?\n");
        return 0;
    }
    if(CHECK1 != 0) {
	notify_fail("You find nothing.\n");
	return 0;
    }
    write("%^CYAN%^You search the spikes and find a note!%^RESET%^");
    say("%^CYAN%^"+TPQCN+" finds something among the spikes!%^RESET%^",TP);
    new( OPATH "note1.c" )->move(TP);
    CHECK1 = 1;
    return 1;
}
void reset() {
    ::reset();
    CHECK1 = 0;
}
