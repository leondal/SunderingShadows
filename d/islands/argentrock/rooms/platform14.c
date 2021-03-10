//One of the main platform rooms -- Yves
#include <std.h>
#include "../argabbr.h"
inherit INH+"mainplat";

void create(){
    ::create();
    set_exits(([
        "north" : PATH+"platform11",
        "northeast" : PATH+"platform12",
        "east" : PATH+"platform15",
        "south" : PATH+"platform17",
        "southeast" : PATH+"platform18",
    ]));
}

