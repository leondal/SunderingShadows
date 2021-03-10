//One of the main platform rooms -- Yves
#include <std.h>
#include "../argabbr.h"
inherit INH+"mainplat";

void create(){
    ::create();
    set_exits(([
        "northwest" : PATH+"platform12",
        "north" : PATH+"platform13",
        "west" : PATH+"platform15",
        "southwest" : PATH+"platform18",
        "south" : PATH+"platform19",
    ]));
}

