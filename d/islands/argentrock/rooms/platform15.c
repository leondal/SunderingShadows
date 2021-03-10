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
        ({"branches", "canopy"}),
            "%^ORANGE%^Thick, stout branches are %^GREEN%^growing%^ORANGE%^ "
            "from the trunk at evenly spaced intervals encircling the tree at "
            "a forty-five degree angle. They esentially form "
            "%^GREEN%^living%^ORANGE%^ steps to climb to the platforms above "
            "and below.%^RESET%^"
    );
    set_exits(([
        "northwest" : PATH+"platform11",
        "north" : PATH+"platform12",
        "northeast" : PATH+"platform13",
        "west" : PATH+"platform14",
        "east" : PATH+"platform16",
        "southwest" : PATH+"platform17",
        "south" : PATH+"platform18",
        "southeast" : PATH+"platform19",
        "up" : PATH+"platform23",
        "down" : PATH+"platform01",
    ]));
}

