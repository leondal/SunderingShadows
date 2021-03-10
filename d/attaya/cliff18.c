
#include <std.h>

inherit "/d/attaya/spec/cliff";

void create(){
	::create();
	set_name("black tunnel.");
	set_short("black tunnel.");
	set_property("indoors",1);
	set_property("light",-1);
set_long("
%^BOLD%^%^BLACK%^This is a dark tunnel that leads up and down.  Metal rungs form a ladder on the wall.  It is very cramped for you in here!
");
       set_exits(([
          "up":"/d/attaya/cliff19",
          "down":"/d/attaya/cliff17",
]));


}
