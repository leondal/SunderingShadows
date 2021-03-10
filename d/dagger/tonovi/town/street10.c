//updated by Circe 9/10/04
#include "/d/dagger/tonovi/town/short.h"

inherit CITYMAIN;

void create(){
    ::create();
    set_property("light",1);
    set_short("Ekan Street");
    set_long(
      "%^BOLD%^%^BLACK%^Ekan Street%^RESET%^\n"+
      "This is a lonely and dark stretch of %^BOLD%^%^BLACK%^Ekan "+
      "Street%^RESET%^ that falls between the %^BOLD%^%^GREEN%^"+
      "crossroads %^RESET%^to the north and the %^YELLOW%^bustling "+
      "area %^RESET%^to the south.  Here, %^BOLD%^%^BLACK%^shadows "+
      "%^RESET%^dance along the ground, created by the %^BOLD%^%^BLACK%^"+
      "stone walls %^RESET%^of the city even during the day.\n"
    );
    set_items( ([
	({"area","bustling area"}) : "To the south, streetlights burn "+
         "even during the day, creating a well-lit area where people "+
         "seem to be coming and going from two store fronts.  This "+
         "section of the road seems eerily deserted in comparison.",
	"crossroads" : "%^BOLD%^%^BLACK%^Ekan Street %^RESET%^meets "+
         "%^BOLD%^%^GREEN%^Main Street %^RESET%^just to the north.",
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
      ({"shadow","shadows"}) : "The combination of tall walls and "+
         "a lack of natural light here create deep shadows the "+
         "cover the ground.  Occasionally you see a small beggar "+
         "child dart in or out of them."
      ]) );
    set_exits( ([
	"north" : RPATH "street7",
	"south" : RPATH "street9"
      ]) );
}
