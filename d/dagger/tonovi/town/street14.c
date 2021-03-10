//updated by Circe 9/10/04
#include "/d/dagger/tonovi/town/short.h"

inherit CITYMAIN;

void create(){
    ::create();
    set_property("light", 2);
    set_short("Guardian way");
    set_long(
      "%^GREEN%^Guardian Way%^RESET%^\n"+
      "You are standing on %^GREEN%^Guardian Way%^RESET%^.  To the west "+
      "the road continues along the northern end of town.  To the "+
      "northwest, there is a strange %^ORANGE%^walled compound"+
      "%^RESET%^, and you can see people moving behind the %^ORANGE%^"+
      "fence%^RESET%^.  To the south is one of the smaller %^BLUE%^"+
      "barracks%^RESET%^ for the city's military forces.\n"
    );
    set_items( ([
	"fence" : "This high wooden fence is built to keep some people "+
         "within this strange compound.",
	({"compound","encampment","strange encampment"}) : "Surrounded "+
         "by a high %^ORANGE%^wooden fence%^RESET%^, this strange "+
         "encampment looks nothing like the rest of the city - save "+
         "that %^BLUE%^well-armed guards %^RESET%^patrol there as "+
         "well.  Scattered along the %^GREEN%^ground %^RESET%^within "+
         "the fence are various %^ORANGE%^tents %^RESET%^and flimsy "+
         "looking %^ORANGE%^wooden buildings%^RESET%^, around "+
         "which elves and other slaves work.",
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
          "of them can often be seen entering and leaving there."
      ]) );
    set_exits( ([
	"east" : RPATH "street13",
	"west" : RPATH "street15",
	"south" : RPATH "brcks-a1"
      ]) );
}
