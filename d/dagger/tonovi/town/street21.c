//updated by Circe 9/10/04
#include <std.h>
#include "/d/dagger/tonovi/town/short.h"

inherit CITYMAIN;

void create(){
    ::create();
    set_property("light", 2);
    set_short("Guardian way");
    set_long(
      "%^GREEN%^Guardian Way%^RESET%^\n"+
      "You are on a stretch of %^GREEN%^Guardian Way %^RESET%^that "+
      "leads around the west side of the %^BLUE%^barracks %^RESET%^and "+
      "near the %^BOLD%^%^BLACK%^northwestern gates %^RESET%^of the "+
      "city.  From here you can see the %^BOLD%^%^BLACK%^gates %^RESET%^"+
      "to the northwest, while the road continues to the northeast and "+
      "south.  To the east is the back side of the %^BLUE%^soldiers' "+
      "barracks%^RESET%^.\n"
    );
    set_items( ([
	({"walls","wall","stone","stone walls"}) : "%^BOLD%^%^BLACK%^"+
         "Walls made of black stone mined from veins in the northern "+
         "mountains encircle the city.",
	({"street","ground"}) : "The streets here are made of "+
         "%^BOLD%^%^BLACK%^gray cobblestone%^RESET%^ kept mostly "+
         "clean of refuse, though here and there some recent trash "+
         "has been left by travellers.",
      ({"building","buildings","shops","shop"}) : "The buildings of the city rise "+
         "around you.  There is a mixture of buildings made of "+
         "black, white, and gray stone, as well as the occasional "+
         "wooden building.",
      "barracks" : "This town seems to be in a constant state of war.  "+
          "Attesting to this fact are the rather nondescript buildings "+
          "that house the common soldiers of the city.  Many "+
          "of them can often be seen entering and leaving there.",
      ({"soldiers","soldier"}) : "Soldiers dressed in chainmail "+
          "come and go in pairs - clearly either on their way to "+
          "or from guard duty.",
      ({"gate","gates"}) : "The gates to the northwest look to be "+
          "made of thick wooden planks reinforced with sturdy "+
          "%^BOLD%^%^BLACK%^iron bands%^RESET%^."
      ]) );
    set_exits( ([
	"northeast" : RPATH "street20",
	"south" : RPATH "street22",
	"northwest" : RPATH "NWgate"
      ]) );
}