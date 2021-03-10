
#include <std.h>

inherit ROOM;

void create(){
	::create();
      set_terrain(ROCKY);
      set_travel(RUBBLE);
	set_short("Path winding across volcanic rock on Attaya Island.");
	set_property("indoors",0);
	set_property("light",3);
set_long("
    You climb up over a volcanic rift and behold a scene of a land in volcanic upheval.  rivers of molten lava mar the landscape and there are no signs of life.  Ash and dust falls upon you as tremendous heat forces you to cover your face.  The ground beneath you shakes violently.
    To the north and south, tall jagged cliffs slowly crumble as streams of lava pour over them.  To the east, a great river of fire stretches out of view into a wall of smoke.
");
       set_exits(([
          "west":"/d/attaya/jun32",
         "east":"/d/attaya/firedock"
]));
	
      set_smell("default", "%^BOLD%^%^BLACK%^Thick smoke assaults your nose and stings your eyes");
       set_listen("default", "The nearby river of lava churns loudly");
	
}
