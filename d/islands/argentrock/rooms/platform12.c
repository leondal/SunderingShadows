//One of the main platform rooms -- Yves
#include <std.h>
#include "../argabbr.h"
inherit INH+"mainplat";

void create(){
    ::create();
    set_exits(([
        "west" : PATH+"platform11",
        "east" : PATH+"platform13",
        "southwest" : PATH+"platform14",
        "south" : PATH+"platform15",
        "southeast" : PATH+"platform16",
    ]));
}

