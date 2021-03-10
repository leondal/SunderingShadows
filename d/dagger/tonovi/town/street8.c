//updated by Circe 9/10/04
//updated 4/17/04 for return of Bane by Circe
#include "/d/dagger/tonovi/town/short.h"

inherit CITYMAIN;

void create(){
    ::create();
    set_property("light",2);
    set_short("Main Street");
    set_long(
      "%^BOLD%^%^GREEN%^Main Street%^RESET%^\n"+
      "This is the west end of main street where it "+
      "opens out into the open air %^CYAN%^bazaar%^RESET%^.  To the "+
      "east you can see the %^BOLD%^%^BLACK%^road %^RESET%^as it "+
      "travels back towards the gates of the city.  To the south a "+
      "%^GREEN%^massive temple %^RESET%^stands in ruins as if crushed "+
      "from above.   A %^ORANGE%^sign %^RESET%^hangs over the door "+
      "to the north.\n"
    );
    set_items( ([
      "bazaar" : "This open air marketplace seems to be constantly "+
          "bustling with people.  It seems to center around some "+
          "strange stage.",
      ({"north sign","sign"}) : ({"This plain wooden sign has a "+
          "message burned into its surface you could probably read.",
         "%^BOLD%^Tonovi General Store%^RESET%^","common"}),
	"gates" : "You can't see them very well from here.",
	({"temple","ruined building","ruins","ruined temple"}) : "This "+
         "was once an impressive stone structure dedicated to the "+
         "the worship of Iyactu Xvim.  Now, it lies in utter ruins, "+
         "and seems to have been smashed by some magnificent force "+
         "from above.",
	({"walls","wall","stone","stone walls"}) : "%^BOLD%^%^BLACK%^"+
         "Walls made of black stone mined from veins in the northern "+
         "mountains encircle the city.",
	({"street","ground","road"}) : "The streets here are made of "+
         "%^BOLD%^%^BLACK%^gray cobblestone%^RESET%^ kept mostly "+
         "clean of refuse, though here and there some recent trash "+
         "has been left by travellers.",
      ({"building","buildings"}) : "The buildings of the city rise "+
         "around you.  There is a mixture of buildings made of "+
         "black, white, and gray stone, as well as the occasional "+
         "wooden building.",
      ({"general store","shop"}) : "%^BOLD%^%^BLACK%^This shop is "+
         "made of the same black stone as the walls of the city.  "+
         "It is not an ornate building, but it seems well-made, "+
         "and you can see various supplies inside when the door "+
         "opens as a customer enters or leaves."
      ]) );
    set_exits( ([
	"east" : RPATH "street7",
	"south" : RPATH "temple1",
      "north" : RPATH "general_store",
	"west" : RPATH "bazaar3"
      ]) );
}
