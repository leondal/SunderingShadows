//updated by Circe 9/10/04 - changed to use CROOM and updated desc
#include "/d/dagger/tonovi/town/short.h"

inherit CROOM;

void create(){
    set_monsters(({ "/d/dagger/tonovi/guards/loeb" }),({ 1 }));
    ::create();
    set_light(2);
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_name("Streets of Tonovi");
    set_short("Gates of Tonovi");
    set_long(
       "%^BOLD%^%^GREEN%^Gates of Tonovi%^RESET%^\n"+
       "You are standing just inside the %^BOLD%^%^BLACK%^great "+
       "gates%^RESET%^ of the city of %^BOLD%^%^GREEN%^Tonovi"+
       "%^RESET%^.  To the northeast and south, you see the "+
       "%^BOLD%^passageways %^RESET%^through the %^BOLD%^%^BLACK%^"+
       "black stone walls %^RESET%^around the city.  To the "+
       "southeast is the %^GREEN%^Yniam plains%^RESET%^, while "+
       "to the north a %^BOLD%^street %^RESET%^travels between "+
       "the %^BOLD%^%^BLACK%^walls %^RESET%^of the city and "+
       "several buildings to the northwest.\n"
    );
    set_smell("default","A slight dank undercurrent of refuse "+
       "pervades the air.");
    set_listen("default","Beneath the bustle of the city, you "+
       "occasionally hear the wail of a child.");
    set_items( ([
	({"gate", "gates"}) : "These great gates are made of wood "+
         "and reinforced with %^BOLD%^%^BLACK%^great iron "+
         "crossbars%^RESET%^.  It has seen some battle damage, "+
         "but has withstood all.",
	({"walls","wall","stone","stone walls"}) : "%^BOLD%^%^BLACK%^"+
         "Walls made of black stone mined from veins in the northern "+
         "mountains encircle the city.",
	({"Yniam plains","plains"}) : "%^GREEN%^The emerald hills of "+
         "the Yniam plains roll to the south in their beauty.",
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
	"southeast" : "/d/dagger/tonovi/road2",
	"northeast" : RPATH "wall1",
	"north" : RPATH "street1",
	"west" : RPATH "wall3"
      ]) );
}
