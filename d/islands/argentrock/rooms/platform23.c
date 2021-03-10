//One of the main platform rooms -- Yves
#include <std.h>
#include "../argabbr.h"
inherit INH+"mainplat";

void create(){
    ::create();
    set_long(::query_long()+
        "Several smaller branches sprout from the trunk and form steps "
        "to the %^GREEN%^canopy%^ORANGE%^ above and platforms below."
    );
    add_item(
        ({"branches", "canopy" }),
            "%^ORANGE%^Thick, stout branches are %^GREEN%^growing%^ORANGE%^ from the trunk at evenly "
            "spaced intervals encircling the tree at a forty-five "
            "degree angle. They esentially form %^GREEN%^living%^ORANGE%^ steps "
            "to climb to the canopy above and platforms below.%^RESET%^"
    );
	set_exits(([
        "north" : PATH+"platform21",
        "west" : PATH+"platform22",
        "east" : PATH+"platform24",
        "south" : PATH+"platform25",
        "up" : PATH+"platform31",
        "down" : PATH+"platform15",
    ]));
}
