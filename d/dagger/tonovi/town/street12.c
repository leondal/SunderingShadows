//updated by Circe 9/10/04
#include "/d/dagger/tonovi/town/short.h"

inherit CITYMAIN;

void create(){
    ::create();
    set_travel(BACK_ALLEY);
    set_property("light", 2);
    set_short("Alleyway");
    set_long(
      "%^RED%^A Dark Alley%^RESET%^\n"+
      "This %^RED%^alleyway %^RESET%^runs between the %^BLUE%^soldiers' "+
      "barracks %^RESET%^and the %^BOLD%^%^BLUE%^officers' quarters"+
      "%^RESET%^.  It is commonly traveled by the officers that wish "+
      "to avoid the %^BOLD%^%^BLACK%^main streets%^RESET%^ of the city.  It "+
      "seems to be somewhat more neglected than the main thoroughfares, "+
      "but that is countered by the fact that the soldiers are less "+
      "prone to throw %^GREEN%^refuse %^RESET%^on the ground, leaving "+
      "it altogether as clean as the rest of the city.\n"
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
      ({"barracks","soldiers' barracks"}) : "This town seems to be "+
          "in a constant state of war.  "+
          "Attesting to this fact are the rather nondescript buildings "+
          "that house the common soldiers of the city.  Many "+
          "of them can often be seen entering and leaving there.",
      ({"quarters","officers' quarters"}) : "The lone officers' "+
         "barracks in the city looks from "+
         "the outside to be much like the barracks for the common "+
         "soldiers.  It is a squat, nondescript building to the "+
         "southeast."
      ]) );
    set_exits( ([
	"south" : RPATH "street11",
	"north" : RPATH "street13",
      ]) );
}
