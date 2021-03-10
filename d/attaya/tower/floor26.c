
#include <std.h>

inherit "/d/attaya/tower/spec/tower";

void create(){
	::create();
        set_travel(STAIRWAY);
	set_name("escape route");
	set_short("escape route");
	set_property("indoors",1);
	set_property("light",2);
    set_long("%^CYAN%^You are climbing down a metal rung ladder into a powerful current of water. The %^CYAN%^m%^BOLD%^%^BLACK%^i%^BLACK%^s%^BLACK%^t%^RESET%^%^CYAN%^ off the water rises up this shaft of metal mesh and soaks you. The ladder is fastened to the circular shaft of mesh and decends until it reaches a point just above the raging surface.");
    set_listen("default", "The raging water beneath you is deafening.");
    set_exits(([
       "up":"/d/attaya/tower/floor25",
       "down":"/d/attaya/tower/floor27",
    ]));
    set_pre_exit_functions( ({"down"}), ({"go_down"}) );
}

int go_down() {
   if(present("judatac")) {
      write("Judatac blocks your way!");
      return 0;
   }
   else return 1;
}

void reset() {
   ::reset();
   if(!present("judatac") && random(10))
      new("d/attaya/mon/judatac")->move(TO);
}
