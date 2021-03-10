//slide1.c

#include <std.h>

inherit ROOM;


void create(){
      ::create();
	set_property("light",2);
	set_property("indoors",0);
	set_terrain(BEACH);
	set_travel(FRESH_BLAZE);
       set_short("A desert island");
        set_long("
    %^ORANGE%^
    A dry arid desert stretches out before you.  This tiny island is not much more than a spot of sand in the middle of a vast blue ocean.  A few sparse palm trees dot the sandy landscape.
    Your footprints are covered by the winds behind you.
    %^BOLD%^%^BLUE%^The ocean meets the land to the north and west.
");
    set_listen("default", "Sand blows in your eyes forcing you to cover your face!");
       set_exits(([
       "south" : "/d/islands/common/eldebaro/room8",
       "east" : "/d/islands/common/eldebaro/room13",
]));
       set_items(([
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
  do_random_encounters(({"/d/islands/common/mon/lostsoul.c", "/d/islands/common/mon/scorpion.c", "/d/islands/common/mon/crab.c", "/d/islands/common/mon/drowned.c", "/d/islands/common/mon/earwig.c"}),15,1);
}
