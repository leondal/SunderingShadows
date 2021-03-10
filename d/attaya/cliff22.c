#include <std.h>

inherit "/d/attaya/spec/ledge2";

void create(){
	::create();
    set_exits(([
                   "west":"/d/attaya/cliff23",
                   "east":"/d/attaya/cliff21"
                   ]));
}

