// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("schooner_m7");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("boats");
    set_travel("slick floor");
    set_climate("tropical");

    set_short("%^RESET%^%^ORANGE%^Forecastle of a Schooner%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^The silence of this room is near deafening in comparison to the snap of sail lines and the constant splash of the ship cutting through the water.  Thick walls of richly polished %^RES"
	"ET%^%^ORANGE%^cedar %^BOLD%^%^BLACK%^and %^RESET%^%^RED%^redwood %^BOLD%^%^BLACK%^provide heavy dampening to the otherwise noisy sounds of sailing.  At the back, where the ship's stern narrows, a sitt"
	"ing area is set.  Surrounded by glittering %^RESET%^windows%^BOLD%^%^BLACK%^, paneled in deep wood, the view of the churning %^RESET%^%^BLUE%^ocean %^BOLD%^%^BLACK%^stretches out endlessly beyond.  On"
	" the table a %^RESET%^%^ORANGE%^map%^BOLD%^%^BLACK%^ has been stretched across the surface, held in place by a few large %^RED%^gems%^BOLD%^%^BLACK%^.%^RESET%^"
	);

    set_smell("default","
The brine filled ocean air fills your senses.");
    set_listen("default","Waves lap at the boat's hull, rocking it back and forth.");

    
set_items(([ 
	({ "gems", "gem" }) : "%^RED%^On second look, the gems appear to be just glass, perhaps meant to fool greedy bandits.%^RESET%^",
	({ "window", "ocean", "windows" }) : "%^CYAN%^The windows spill across the back of the room, looking out over a nearly endless swath of water.  Crystal clear, the view never fogs or becomes distorted.  %^RESET%^",
	({ "walls", "wood", "cedar", "redwood", "panels", "cabin" }) : "%^RESET%^%^ORANGE%^This room is decorated in warm woods and rich grains.  Cedar and redwood are primary, giving a soft warmth to the room and dampening the sounds coming in from outside.%^RESET%^",
	"map" : "%^RESET%^%^ORANGE%^The map appears to be of the Dagger Sea, you can see several trade routes marked upon the surface along with strange notations that make no sense. The port of Torm is clearly marked as are two other smaller notations that might also be of importance.  One far to the south, near the shore line, and the other more out in the open.%^RESET%^",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/lurue/schooner_m6",
	]));

    set_door("cabin door","/d/av_rooms/lurue/schooner_m6","west","schooner key","brass lock");
    add_lock("cabin door","schooner key","brass lock","This brass lock looks secure and strong.  Set into the wood of the door, you'll either need a key to unlock it or a lot of force to batter it down.");
    set_locked("cabin door",1,"brass lock");
    lock_difficulty("cabin door",-1000,"brass lock");
    set_open("cabin door",0);
    set_string("cabin door","knock","rap on the");
    set_string("cabin door","open","With a rush of air, the cabin door opens.");
    set_string("cabin door","close","The door closes with a final sound.");
    set_door_description("cabin door","This wooden door is finely carved and decorated with delicate carvings.  To either side of it, frosted windows can be seen along the walls, and in the center of the door, a glass oval depicting the endless sea is set.");
}