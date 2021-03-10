#include <std.h>

inherit "/d/attaya/spec/cliff";

void create(){
	::create();
	set_name("black tunnel.");
	set_short("%^BOLD%^%^BLACK%^Black tunnel");    
	set_property("indoors",1);
	set_property("light",0);
    set_long("%^BOLD%^%^BLACK%^Black tunnel
%^BOLD%^%^BLACK%^This is a dark tunnel that leads up and down.  Metal rungs form a ladder on the wall.  It is very cramped for you in here! There is some light above you.");
    set_exits(([
                   "up":"/d/attaya/cliff20",
                   "down":"/d/attaya/cliff17",
                   ]));
}


