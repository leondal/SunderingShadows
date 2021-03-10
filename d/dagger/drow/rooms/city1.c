#include <std.h>
#include "/d/dagger/drow/short.h"
inherit ROOM;
void create() {
    ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("%^BLUE%^City street%^RESET%^");
    set_long(
	"%^BLUE%^You stand at the entrance to the Drow city of "
	"Underdark. Before you transpires to %^CYAN%^large towers%^BLUE%^. "
	"The city lies within a mammoth underground cavern surrounded by "
	"a %^BOLD%^large lake%^RESET%^%^BLUE%^. In the distance, within "
	"the center of the city, you can see a structure which appears to "
   "be a %^RED%^temple%^BLUE%^. %^BLUE%^The city street is made of "
	"cobblestones winding through the existing structures around you. "
	"The wind blows back your hair as you wander through the city "
	"pathways.\n%^RED%^There is, for some unknown reason, numerous "
	"small spiders crawling all over various parts of the "
	"city.%^RESET%^"
    );
    set_listen("default",
	"The wind howls a strangled cry which causes you to feel nervous "
	"about being here."
    );
    set_smell("default",
	"The smell of blood hangs thick in the air."
    );
    set_items(([
	"temple":"%^BLUE%^The temple looms in the distance. A large statue "
	"has been mounted atop the temple.%^RESET%^",
	"statue":"%^BLUE%^The statue is of a large spider with a female "
	"human head.%^RESET%^",
	"spiders":"The spiders scurry about the city with some unknown "
	"business that concerns the insect world...not humanoids.",
	"cobblestone":"There are numerous cobblestones lining the city "
	"pathways.",
	"cobblestones":"The city pathway is made up of various colored "
	"cobblestones which must have been mined in the caverns near here.",
	"street":"The street is made up of cobblestones and winds through "
	"the buildings.",
	"pathway":"The pathway winds through the city and is made up of "
	"cobblestones.",
	"buildings":"There are buildings lining the city streets."
    ]));
    set_exits(([
	"north": RPATH "city2",
	"west": RPATH "city3",
	"east": RPATH "city20",
	"south": RPATH "bridge2",
        "up": RPATH "city1"
    ]));
    set_pre_exit_functions(({"up"}),({"exit_fun"}));
}
int exit_fun() {
    write(
	"You do not have a flying steed on which to fly up with!"
    );
    say(
	"%^RED%^"+TPQCN+" tries to fly and falls flat on "
	+TP->query_possessive()+
	" face!%^RESET%^"
    ,TP);
    return 0;
}

