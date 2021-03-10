
#include <std.h>

inherit "/d/attaya/tower/spec/tower";

void create(){
	::create();
        set_terrain(WOOD_BUILDING);
        set_travel(STAIRWAY);
	set_name("black tunnel");
	set_short("black tunnel");
	set_property("indoors",1);
	set_property("light",-1);
set_long("
    This is a dark tunnel that leads up and down.  The staircase is made of wood, and each step echoes.  It is very cramped for you in here!
");
    set_listen("default", "You can hear the sound of rushing water beneath you.");
       set_exits(([
          "up":"/d/attaya/tower/floor4",
          "down":"/d/attaya/tower/floor5",
]));
	
	
}
