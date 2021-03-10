//updated by Circe 9/10/04
//changed to add exit to Bane's temple.  Circe 4/13/04
#include "/d/dagger/tonovi/town/short.h"

inherit CITYMAIN;

void create(){
    ::create();
    set_light(2);
    set_short("Main Street");
    set_long(
      "%^BOLD%^%^GREEN%^Main Street%^RESET%^\n"+
      "You are on the main street through Tonovi.  It runs "+
      "east and west through the heart of the city.  In the "+
      "middle of the city it crosses %^BOLD%^%^BLACK%^Ekan "+
      "Street%^RESET%^, which travels north and south.  Here, your eyes "+
      "are drawn to the %^BOLD%^%^BLACK%^towering building %^RESET%^"+
      "to the north.  This "+
      "impressive structure seems to dominate the city, and it "+
      "is visible from all directions.  To the south you can see "+
      "the gates to the city in the distance, along %^BOLD%^%^GREEN%^"+
      "Gateway Street%^RESET%^.  A once-mighty structure of pure "+
      "%^BOLD%^%^BLACK%^onyx %^RESET%^lies in ruin just to the "+
      "north, and no-one seems in a particular hurry to remove it.\n"
    );
    set_items( ([
	({"gate", "gates"}) : "The great gates of the city stand to the south.",
	({"walls","wall","stone","stone walls"}) : "%^BOLD%^%^BLACK%^"+
         "Walls made of black stone mined from veins in the northern "+
         "mountains encircle the city.",
	({"street","ground"}) : "The streets here are made of "+
         "%^BOLD%^%^BLACK%^gray cobblestone%^RESET%^ kept mostly "+
         "clean of refuse, though here and there some recent trash "+
         "has been left by travellers.",
      ({"structure","ruin"}) : "An enormous building made of %^BOLD%^%^BLACK%^"+
         "black stone%^RESET%^ must have once stood to the north, but now it "+
         "lies in ruin.  No-one seems to be in a hurry to tidy up its remains, "+
         "and the derision with which passers-by regard it makes you wonder if "+
         "perhaps it has been left deliberately as an example."
      ]) );
    set_exits( ([
	"east" : RPATH "street4",
	"west" : RPATH "street5",
	"south" : RPATH "street2",
      ]) );
}
