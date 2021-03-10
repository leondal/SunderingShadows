//updated by Circe 9/10/04
#include "/d/dagger/tonovi/town/short.h"

inherit CITYMAIN;

void create(){
    ::create();
    set_travel(BACK_ALLEY);
    set_property("light", 2);
    set_short("Ekan Street");
    set_long(
      "%^BOLD%^%^BLACK%^Ekan Street%^RESET%^\n"+
      "This stretch of %^BOLD%^%^BLACK%^Ekan Street %^RESET%^"+
      "leads north from the center of the city towards a strange "+
      "%^ORANGE%^fenced-in area %^RESET%^to the north.  The sides "+
      "of %^BOLD%^shops %^RESET%^rise up on each side of you, but "+
      "no entrance is visible from here.\n"
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
      ({"structure","strange structure","area","fenced-in area"}) : "Far "+
          "to the north, you can "+
          "barely make out what looks to be some sort of compound.  "+
          "You can tell few details from here, though, only a rooftop "+
          "and another wall.",
      ]) );
    set_exits( ([
	"north" : RPATH "street16",
	"south" : RPATH "street18",
      ]) );
}