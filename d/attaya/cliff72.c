#include <std.h>

inherit "/d/attaya/spec/ledge3";

void create(){
	::create();
    set_exits(([
                   "west":"/d/attaya/cliff71",
                   "east":"/d/attaya/cliff73",
                   "down":"/d/attaya/cliff70"
                   ]));
    set_smell("default", "It is so very cold and lonely up here.");
    set_listen("default", "Cold winds rip past you.");
}

