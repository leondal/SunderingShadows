//One of the main platform rooms -- Yves
#include <std.h>
#include "../argabbr.h"
inherit INH+"mainplat";

void create(){
    ::create();
    set_exits(([
        "west" : PATH+"platform12",
        "southwest" : PATH+"platform15",
        "south" : PATH+"platform16",
	]));
}

