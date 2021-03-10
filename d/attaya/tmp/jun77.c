
#include <std.h>

inherit ROOM;

void create(){
	::create();
	set_short("Old growth jungle.");
	set_property("indoors",0);
	set_property("light",1);
set_long("
    This is a rocky cliff that decends to the beach to the northwest.  The ground is made up of small stones and sand in most places here and is very unstable footing.  
    A few palms grow from the rocky hillside.
");
       set_exits(([
         "northwest":"/d/attaya/jun78",
          "east":"/d/attaya/jun76",
]));
	
      set_smell("default", "The air smells of rain and humidity");
      set_listen("default", "It is strangely quiet.  The animals have all been %^RED%^silenced!");
set_items(([
    "canopy": "It completely blocks out the light.",
    "mud": "It is sloppy and brown, and looks like...  wet soil.",
    "graves": "They are overgrown and have been long forgotten.",
    "bones": "A few bones peek out from low lying areas where the soil around them has been eroded away."
]));
}

void init() {
  ::init();
  do_random_encounters(({"/d/attaya/mon/nightstalker.c","/d/attaya/mon/entity.c", "/d/attaya/mon/uwarrior.c","/d/attaya/mon/toclahar.c","/d/common/mon/necrophidius.c"}),50,6);
}
