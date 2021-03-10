#include <std.h>

inherit ROOM;


void create(){
      ::create();
	set_property("light",2);
	set_property("indoors",0);
	set_terrain(DESERT);
	set_travel(FRESH_BLAZE);
       set_short("A desert island");
        set_long("
    You climb up onto a large flat slab of stone.  It was a floor to the fortress at one time and has tilted and raised from the ground since.  A large symbol is carved into the slab but most of the smaller markings have eroded away.
    %^ORANGE%^
    A dry arid desert stretches out before you in all directions.  This tiny island is not much more than a spot of sand in the middle of a vast blue ocean.  A few sparse palm trees dot the sandy landscape.
");
   set_listen("default", "Sand blows in your eyes forcing you to cover your face!");
       set_exits(([
       "north" : "/d/islands/common/eldebaro/room26",
       "south" : "/d/islands/common/eldebaro/room28",
       "west" : "/d/shadow/virtual/sea/eldebaro.dock",
       "east" : "/d/islands/common/eldebaro/room33",
]));
       set_items(([
    "symbol" : "It is the feared marking of the Kinnesaruda Legacy.",
    "slab" : "A large flat slab of stone that extends to a height of twenty feet above the sand at the corner."
]));
	
set_pre_exit_functions( ({"north"}), ({"earwig_pit"}) );
set_pre_exit_functions( ({"south"}), ({"earwig_pit"}) );
set_pre_exit_functions( ({"west"}), ({"earwig_pit"}) );
set_pre_exit_functions( ({"east"}), ({"earwig_pit"}) );
}
int earwig_pit(){
if(present("earwig scorpion")) {
write("The Earwig Scorpion has you trapped!");
return 0;
  }
else return 1;
}
void init() {
  ::init();
  do_random_encounters(({"/d/attaya/mon/intruderII.c", "/d/islands/common/mon/scorpion.c", "/d/islands/common/mon/crab.c", "/d/islands/common/mon/drowned.c", "/d/islands/common/mon/earwig.c"}),15,1);
}
