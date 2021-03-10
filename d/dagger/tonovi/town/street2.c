//updated by Circe 9/10/04
#include "/d/dagger/tonovi/town/short.h"

inherit CITYMAIN;

void create(){
    ::create();
    set_light(2);
    set_short("Streets of Tonovi");
    set_long("%^BOLD%^%^GREEN%^Gateway Street%^RESET%^\n"+
       "This %^BOLD%^%^BLACK%^cobblestone street %^RESET%^marches "+
       "through the towering city of %^BOLD%^%^GREEN%^Tonovi%^RESET%^.  "+
       "To the east the %^BOLD%^%^BLACK%^dark stone walls %^RESET%^"+
       "of the city rise above you, while to the west you can see "+
       "a fantastic %^MAGENTA%^mural %^RESET%^painted on the side "+
       "of a %^BOLD%^building%^RESET%^.   The %^BOLD%^%^BLACK%^gates "+
       "%^RESET%^to the city are off in the distance to the south, "+
       "and the main street is just north of you.\n"
    );
    set_items( ([
	({"gate", "gates"}) : "The great gates of the city stand to the south.",
	({"walls","wall","stone","stone walls"}) : "%^BOLD%^%^BLACK%^"+
         "Walls made of black stone mined from veins in the northern "+
         "mountains encircle the city.",
	({"building", "hotel","restaurant"}) : "The side of this building, which is "+
         "the local hotel and restauraunt, has been decorated with a mural.",
	({"street","ground"}) : "The streets here are made of "+
         "%^BOLD%^%^BLACK%^gray cobblestone%^RESET%^ kept mostly "+
         "clean of refuse, though here and there some recent trash "+
         "has been left by travellers.",
	({"mural","painted mural"}) : "This colorful mural depicts the "+
         "armies of %^BOLD%^%^GREEN%^Tonovi %^RESET%^waging war deep "+
         "in the %^GREEN%^Kilkean forest%^RESET%^.  Captains in "+
         "%^BOLD%^%^BLACK%^full plate %^RESET%^atop proud steeds "+
         "direct their soldiers in combat against elves defending "+
         "themselves with spell and blade.  In the right corner, a "+
         "line of soldiers is leading away %^CYAN%^chained elves "+
         "%^RESET%^even while the battle wages.\nYou see several "+
         "marks where bold elves have tried to deface the mural.",
      ]) );
    set_exits( ([
	"south" : RPATH "street1",
	"north" : RPATH "street3",
      ]) );
}
