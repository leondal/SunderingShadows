//updated by Circe 6/2/04 with color, etc.
#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create() {
	::create();
	set_travel(DIRT_ROAD);
	set_terrain(CITY);
	set_name("archery range");
	set_light(2);
	set_short("The Archery Range in the Fields, Tabor");
	set_long(
@TABOR
%^BOLD%^The Archery Range in the Fields, Tabor%^RESET%^
All around you is %^GREEN%^trampled grass %^RESET%^where the %^ORANGE%^soft leather boots %^RESET%^of the 
Guards archers have stood for hours firing at the targets.  The Archers 
come here and shoot at the %^RED%^targets %^RESET%^to the north.  Often the great ones 
will have competitions trying to hit the farthest target.  That target 
seems to be porportionately hardest to hit.  There is a %^BOLD%^line %^RESET%^marked in 
the ground that all Archers know never to cross, as the obvious result 
could be an %^RED%^arrow %^RESET%^in the back. 

%^BOLD%^Note:%^RESET%^ Use the trainer to the west to apply proficiency slots for ranged 
weapons before practicing here.
TABOR
	);
	set_items(([
		"line" : "This dirt line is the mark to stand on. Obvious "+
               "true competitors would never cross it..",
		"targets" :"These target are gradually farther and farther "+
               "away.  Obviously hitting a more distant target will "+
               "result in better training",
	]));
    set_listen("default","You hear the whoosh of arrows in the air.");
    set_smell("default","You smell the earthy scent of trampled grass.");
	set_exits(([
	"north" : "/d/darkwood/tabor/include/arch1",
        "west" : ROOMDIR+"trainer",
	]));
	set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
}

int GoThroughDoor(){
	if(avatarp(TP)) return 1;
	write("You realize that would be really dumb as you start to cross the line.");
	return 0;
}
