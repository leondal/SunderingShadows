//One of the main platform rooms -- Yves
#include <std.h>
#include "../argabbr.h"
inherit INH+"mainplat";

void create(){
    ::create();
    set_exits(([
        "north" : PATH+"platform14",
        "northeast" : PATH+"platform15",
        "east" : PATH+"platform18",
    ]));
}

