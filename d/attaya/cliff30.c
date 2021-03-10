#include <std.h>

inherit "/d/attaya/spec/ledge3";

void create(){
	::create();
    set_exits(([
                   "west":"/d/attaya/cliff29",
                   "east":"/d/attaya/cliff31"
                   ]));
}

