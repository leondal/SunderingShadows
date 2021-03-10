
#include <std.h>

inherit "/d/attaya/tower/spec/tower";

void create(){
	::create();
      set_travel(STAIRWAY);
	set_name("escape route");
	set_short("escape route");
	set_property("indoors",1);
	set_property("light",2);
set_long("%^CYAN%^You are climbing down a metal rung ladder into a powerful current of water. The mist off the water rises up this shaft of metal mesh and soaks you. The ladder is fastened to the circular shaft of mesh and decends until it reaches a point just above the raging surface.");
    set_listen("default", "The raging water beneath you is deafening.");
       set_exits(([
          "up":"/d/attaya/tower/floor24",
          "down":"/d/attaya/tower/floor26",
]));
	
	
}
