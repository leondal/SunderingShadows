#include <std.h>

inherit "/d/attaya/spec/ledge3";

void create(){
	::create();
    set_long(::query_long()+" A staircase set into the mountain begins here and desends into warmer altitudes.");
    set_exits(([
                   "east":"/d/attaya/cliff30",
                   "down":"/d/attaya/cliff28"
                   ]));
}

