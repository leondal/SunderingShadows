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
      "This is the end of %^GREEN%^Guardian Way%^RESET%^, where it "+
      "opens up into the %^CYAN%^great bazaar %^RESET%^of %^BOLD%^"+
      "%^GREEN%^Tonovi%^RESET%^.  From here you can see a large "+
      "%^ORANGE%^platform %^RESET%^forming the center of the %^CYAN%^"+
      "bazaar%^RESET%^, but you cannot quite see what goes on there.  "+
      "All around the %^ORANGE%^platform%^RESET%^, various %^CYAN%^"+
      "vendors %^RESET%^proffer their wares.\n"
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
      ({"gate","gates"}) : "The gates are to the northwest, and you "+
          "cannot quite see them from here.",
      ({"bazaar","platform","marketplace","vendors"}) : "%^CYAN%^To the "+
          "south is the open air bazaar, teeming with people.  "+
          "Vendors call out their prices and display their wares "+
          "while customers wander by.  The focus of the whole "+
          "bazaar, however, seems to the wooden platform at its "+
          "center.  You cannot quite make out what is going on "+
          "there from here."
      ]) );
    set_exits( ([
	"north" : RPATH "street21",
	"south" : RPATH "bazaar2",
      ]) );
}
