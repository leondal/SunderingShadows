//One of the main platform rooms -- Yves
#include <std.h>
#include "../argabbr.h"
inherit INH+"mainplat";

void create(){
    ::create();
    set_exits(([
        "east" : PATH+"platform12",
        "south" : PATH+"platform14",
        "southeast" : PATH+"platform15",
    ]));
}

