#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit TROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_long("%^RED%^"
	"The small and narrow hallway is made of the same %^BOLD%^"
	"blood-red%^RESET%^%^RED%^ stone as seen in other parts of the tower. "
	"The stone calls out to you as though it is alive and held captive in "
	"an endless state of torment. A few small black %^CYAN%^candles%^RED%^ "
	"lay flickering on the floor creating an array of shadows which dance "
	"wildly upon the walls."
	"%^RESET%^" 
    );
    set_short("%^RED%^Tower Hallway%^RESET%^");
    set_listen("default",
        "It is dead silent, as though sound itself fears to roam here."
    );
    set_smell("default",
        "The haunting smell of a burial crypt lingers here."
    );
    set_items(([
	"stone":"%^RED%^The stone used to form the chamber is made from an unknown "
	"material and seems to glow in it's blood-red colour. As you gaze upon it, "
	"you hear the distant laughter of Grazzt.%^RESET%^",
	"candles":"%^GREEN%^A few small black %^CYAN%^candles%^GREEN%^ "
	"lay flickering on the floor creating an array of shadows which dance "
	"wildly upon the walls.%^RESET%^",
	"walls":"Shadows dance upon the walls.",
	"shadows":"The shadows sway in and about...almost as though they were alive."
    ]));
    set_exits(([
        "west": RPATH "c3",
        "southeast": RPATH "c2",
    ]));
    set_pre_exit_functions(({"west"}),({"exita_fun"}));
}
int exita_fun() {
    if(present("golem")) {
        write("The golem prevents you from going west!");
        return 0;
    }
    return 1;
}

void reset() {
    ::reset();
    if(!present("golem")) {
        new( MPATH "golem.c" )->move(TO);
    }
}
