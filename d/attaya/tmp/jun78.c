
#include <std.h>

inherit ROOM;

void create(){
	::create();
	set_short("Old growth jungle.");
	set_property("indoors",0);
	set_property("light",1);
set_long("
    %^BOLD%^You slip and fall amidst a veil of rocks and dust to the beach!

%^RESET%^
    You are lying in a pile of rocks and debris near the beach.  The sky is once again visible overhead.
    A few palms grow from the rocky hillside.
");
       set_exits(([
         "southwest":"/d/attaya/beach2n",
]));
	
      set_smell("default", "The air smells of rain and humidity");
      set_listen("default", "The ocean's waves can be heard nearby.");
set_items(([
    "canopy": "It completely blocks out the light.",
    "mud": "It is sloppy and brown, and looks like...  wet soil.",
    "graves": "They are overgrown and have been long forgotten.",
    "bones": "A few bones peek out from low lying areas where the soil around them has been eroded away."
]));
}

void init() {
  ::init();
  do_random_encounters(({"/d/attaya/mon/solstice.c","/d/common/mon/scorpion.c", "/d/attaya/mon/uwarrior.c","/d/attaya/mon/toclahar.c","/d/common/mon/necrophidius.c"}),30,6);
}
