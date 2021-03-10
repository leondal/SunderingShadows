//One of the main platform rooms -- Yves
#include <std.h>
#include "../argabbr.h"
inherit INH+"mainplat";

void create(){
    ::create();
    set_exits(([
        "northwest" : PATH+"platform14",
        "north" : PATH+"platform15",
        "northeast" : PATH+"platform16",
        "west" : PATH+"platform17",
        "east" : PATH+"platform19",
    ]));
}

