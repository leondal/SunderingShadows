// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("arena_01");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^RED%^The abandoned halls of the Seneca Arena%^RESET%^");

    set_long("%^RESET%^You stand at the entranceway to the ancient %^YELLOW%^Seneca Arena%^RESET%^.  Once a battleground for trained warriors to match their abilities against one another, the Arena fell out of use "
	"in the late sixth century SG.  Closed for repairs it would never be opened again.  The short corridor here leads into the main area of the arena.  On the walls, a few remaining tatters of %^ORANGE%^po"
	"sters %^RESET%^and %^RED%^pennants %^RESET%^can be seen.%^RESET%^"
	);

    set_smell("default","
Dust and rot tingle your nose.");
    set_listen("default","The coo and chirp of nesting birds reaches you once in a while.");

    
set_items(([ 
	({ "gate", "corridor" }) : "%^RESET%^The corridor leads between the large iron gates that serve as an entrance way to the Arena's outer structure.  Ahead, beyond this covered passage, you can see another gate that leads into the sandy pit of the Arena proper.%^RESET%^",
	({ "walls", "pennants", "pennant", "wall", "posters", "poster" }) : "%^RED%^You look at the stone walls and can see the ancient posters that once announced the times and dates of the epic battles that were held here.  Though they're mostly too faded to read, the images painted on them are of powerful warriors posing or locked in combat.  Between the posters, you can see the pennants of sponsors with their insignias faded beyond recognition.%^RESET%^",
	]));

    set_exits(([ 
		"out" : "/d/attaya/seneca/street6",
		"east" : "/d/av_rooms/lurue/arena_02",
	]));

}