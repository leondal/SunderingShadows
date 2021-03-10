//One of the main platform rooms -- Yves
#include <std.h>
#include "../argabbr.h"
inherit INH+"mainplat";

void create(){
    ::create();
    set_exits(([
        "northwest" : PATH+"platform15",
        "north" : PATH+"platform16",
        "west" : PATH+"platform18",
    ]));
}

