//updated by Circe 9/10/04
//added exit for hitching post.  Circe 4/23/04
#include "/d/dagger/tonovi/town/short.h"

inherit CITYMAIN;

void create(){
    ::create();
    set_light(2);
    set_short("Streets of Tonovi");
    set_long("%^BOLD%^%^GREEN%^Gateway Street%^RESET%^\n"+
       "This %^BOLD%^%^BLACK%^cobblestone street %^RESET%^is the "+
       "only thoroughfare that leads from the %^BOLD%^%^BLACK%^main "+
       "gates %^RESET%^to the main street of the town.  To the east "+
       "the street is surrounded by high %^BOLD%^%^BLACK%^walls"+
       "%^RESET%^, making it dark and ominous.  There is an archway "+
       "in the western wall that leads to a %^GREEN%^courtyard %^RESET%^"+
       "of sorts.   The gates to the city are to the south, and you "+
       "can see the %^BOLD%^%^GREEN%^main street %^RESET%^far to "+
       "the north.\n"
    );
    set_items( ([
	({"gate", "gates"}) : "The great gates of the city stand to the south.",
	({"walls","wall","stone","stone walls"}) : "%^BOLD%^%^BLACK%^"+
         "Walls made of black stone mined from veins in the northern "+
         "mountains encircle the city.",
      ({"courtyard","archway"}) : "The archway in the western wall "+
         "leads into a walled, grassy area.",
	({"street","ground"}) : "The streets here are made of "+
         "%^BOLD%^%^BLACK%^gray cobblestone%^RESET%^ kept mostly "+
         "clean of refuse, though here and there some recent trash "+
         "has been left by travellers.",
      ({"building","buildings"}) : "The buildings of the city rise "+
         "around you.  There is a mixture of buildings made of "+
         "black, white, and gray stone, as well as the occasional "+
         "wooden building."
      ]) );
    set_exits( ([
	"south" : RPATH "maingate",
	"north" : RPATH "street2",
      "west" : RPATH "tether"
      ]) );
}