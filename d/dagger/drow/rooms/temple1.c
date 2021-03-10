//This room needs a new description. For now, I'm removing the part that 
//prompted a typo report (that it would be done soon). Circe 4/27/11
#include <std.h>
#include "/d/dagger/drow/short.h"
inherit ROOM;
void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("Temple Sanctum");
    set_long(
	"%^BLACK%^%^BLUE%^Congratulations, you managed to somehow gain "
	"access to the Drow temple sanctum. If you solved the quest to "
	"open the doors you were granted experience for it. You will not "
	"ever be granted this xp again. However, you now will always "
	"be able to open the temple doors without gathering the symbols "
	"first...making it easier to come into the temple and out. "
        "Also, there are two exits from this room...one takes you to the "
	"start of the caverns just prior to the fog one-way entrance to "
	"the city. This is a good means of leaving the city as that exit "
	"is blocked by the fog. The other will take you into the Drow temple."
/*    "At this present time it is still being worked on and only the first two levels are in. The rest will be added "
	"to the game shortly.\n%^RESET%^%^RED%^Grazzt, Lord of the "
	"Drow%^RESET%^"*/
	); 	
    set_exits(([
    "temple" : "/d/dagger/drow/temple/rooms/first1",
        "portal": RPATH "tun10"
    ]));
}
