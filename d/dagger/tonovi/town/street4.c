//updated by Circe 9/10/04
#include "/d/dagger/tonovi/town/short.h"

inherit CITYMAIN;

void create(){
    ::create();
    set_light(2);
    set_short("Main Street");
    set_long(
      "%^BOLD%^%^GREEN%^Main Street%^RESET%^\n"+
      "You are on the %^BOLD%^%^BLACK%^main street %^RESET%^"+
      "through %^BOLD%^%^GREEN%^Tonovi%^RESET%^.  It runs east "+
      "and west through the heart of the city.  In the middle of "+
      "the city it crosses %^BOLD%^%^BLACK%^Ekan Street%^RESET%^, "+
      "which travels north and south.\n\n"+
      "This is the easternmost end of %^BOLD%^%^BLACK%^main street"+
      "%^RESET%^.  From here, you can see a well-kept path that "+
      "leads northeast to the %^BLUE%^officers' barracks%^RESET%^, "+
      "and an %^RED%^alley %^RESET%^to the northwest that travels "+
      "around behind some of the %^BOLD%^buildings%^RESET%^.\n"
    );
    set_items( ([
	({"walls","wall","stone","stone walls"}) : "%^BOLD%^%^BLACK%^"+
         "Walls made of black stone mined from veins in the northern "+
         "mountains encircle the city.",
	({"street","ground"}) : "The streets here are made of "+
         "%^BOLD%^%^BLACK%^gray cobblestone%^RESET%^ kept mostly "+
         "clean of refuse, though here and there some recent trash "+
         "has been left by travellers.",
      ({"building","buildings"}) : "The buildings of the city rise "+
         "around you.  There is a mixture of buildings made of "+
         "black, white, and gray stone, as well as the occasional "+
         "wooden building.",
      ({"barracks","officers' barracks"}) : "The barracks is a low "+
         "building made of gray stone that blends in well with "+
         "the other buildings of the city.",
      "alley" : "The narrow alley is still paved with the %^BOLD%^"+
         "%^BLACK%^cobblestone %^RESET%^of the rest of the city "+
         "streets.  However, the walls close in even more, and "+
         "you can see more piles of refuse that way."
      ]) );
    set_exits( ([
	"west" : RPATH "street3",
	"northeast" : RPATH "officer1",
	"northwest" : RPATH "street11",
      ]) );
}