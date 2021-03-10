// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("arena_05");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^YELLOW%^The Grand Arena of Senca%^RESET%^");

    set_long("%^RESET%^Huge granite blocks, each weighing at least a ton, create the giant oval arena pit of the %^YELLOW%^Seneca Arena%^RESET%^.  The whole focus of the entire building is where you stand.  Where s"
	"oft %^ORANGE%^sand %^RESET%^once cushioned and supported epic battles of blood and death, of heroism and prowess.  Where blood splashed, weapons clanged, and armor was optional.  What remains of the a"
	"rena is not so grandiose.  %^BOLD%^%^BLACK%^Hard packed earth %^RESET%^is all that's left of the fine sand, and the granite blocks so carefully placed are %^CYAN%^crumbling %^RESET%^under the constant"
	" ware of wind and weather.  To the west the %^RED%^Warriors Gate %^RESET%^stands leading out of the arena and into the stands.  To the east the %^RED%^Gladiator's Lounge %^RESET%^awaits. %^RESET%^"
	);

    set_smell("default","
You can smell %^RED%^blood%^ORANGE%^ still, even though it looks all washed away.");
    set_listen("default","The coo and chirp of nesting birds reaches you once in a while.");

    
set_items(([ 
	({ "gate", "warrior's gate", "warrior gate", "warriors gate" }) : "%^BOLD%^%^RED%^This wrought iron gate is huge and serves as the entry way to the sand lined arena.  The depiction of two huge men locked in epic combat can be seen on the gate.  The image so detailed that you can see where the artist showed cuts in the warrior's bodies, and the spills of blood upon the earth.  Unfortunately, one of the hinges has given way, causing the gate to twist and fall open partway.  Enough for you to scramble over, if you wanted to access the outside.%^RESET%^",
	({ "gladiators lounge", "gladiator's lounge", "lounge" }) : "%^RESET%^%^ORANGE%^You can't make out much about what is beyond the iron gate.  All you can see is a set of stairs leading down into the earth.%^RESET%^",
	({ "earth", "sand", "hard packed earth", "ground" }) : "%^RESET%^%^ORANGE%^What was once soft, fine sand is now little more then hard packed earth.  The rain and winds have scooped away everything and left a caked hard earth in its place.%^RESET%^",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/lurue/arena_02",
		"east" : "/d/av_rooms/lurue/arena_06",
	]));

}