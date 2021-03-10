#include <std.h>

inherit "/d/attaya/spec/cliff2";

void create(){
	::create();
    set_long(::query_long()+"
The ladder is difficult to grasp as the rungs are frozen. You begin to come to the realization that you could fall to your death any second. You contemplate jumping. It is terribly cold here and you rub your arms together to keep warm. The Tower stands not far above you. You are in it's shadow now!");
    set_exits(([
                   "up":"/d/attaya/cliff75",
                   "down":"/d/attaya/cliff73",
                   ]));
    set_smell("default", "The air is getting thinner at this altitude.");
}


