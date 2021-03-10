#include <std.h>

inherit ROOM;


void create(){
      ::create();
        set_property("light",2);
        set_property("indoors",0);
        set_terrain(DESERT);
        set_travel(FRESH_BLAZE);
      set_short("A desert island");
        set_long("A large outcropping of dark rock breaks the smoothness of the desert sands here.\n   A dry arid desert stretches out before you in all directions.  This
tiny  island is not much more than a spot of sand in the middle of a vast blue
ocean.  \nA few sparse palm trees dot the sandy landscape.  Your footprints are covered by the winds behind you.
");
   set_listen("default", "Sand blows in your eyes forcing you to cover your
face!");
       set_exits(([
       "north" : "/d/islands/common/eldebaro/room19",
       "south" : "/d/islands/common/eldebaro/room21",
       "west" : "/d/islands/common/eldebaro/room15",
       "east" : "/d/islands/common/eldebaro/room23",
       "doorway" : "/d/guilds/fist/hall/hall1.c",
]));
set_invis_exits(({"doorway"}));       
   set_items(([
   ({"rocks","outcropping"}):"The large rocks seem to form a colossal monument in the form of three boulders that look very much like a mysterious doorway.",
   ({"boulders","monument","doorway"}) : "Three boulders: two sit upright
like columns, the third lays across the tops of the first two, forming a
doorway of sorts, oriented east-west. They appear to have been here for a
very long time."
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
  do_random_encounters(({"/d/islands/common/mon/lostsoul.c",
"/d/islands/common/mon/scorpion.c", "/d/islands/common/mon/crab.c",
"/d/islands/common/mon/drowned.c",
"/d/islands/common/mon/earwig.c"}),15,1);
  do_random_encounters(({"/d/islands/common/mon/lostsoul.c",
"/d/islands/common/mon/scorpion.c", "/d/islands/common/mon/crab.c",
"/d/islands/common/mon/drowned.c",
"/d/islands/common/mon/earwig.c"}),15,1);
}