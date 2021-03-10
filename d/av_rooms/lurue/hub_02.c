// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("hub_02");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^Passage of Cities%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This hall leads away from the central hub and down along a tapestry lined corridor.  Each tapestry is life like and filled with detail so clear that it seems you might be able to step"
	" through them and stand upon the part of the world they display.%^RESET%^"
	);

    set_smell("default","
The air is faintly tinged with a hint of moss and earth.");
    set_listen("default","The room is silent except for the quiet ticking of your heartbeat.");


    set_exits(([ 
		"lothwaite" : "/d/barriermnts/lothwaite/rooms/pathway20",
		"azha" : "/d/azha/town/high1",
		"muileann" : "/d/koenig/town/room1",
		"antioch" : "/d/antioch/antioch2/rooms/street2",
		"verbobone" : "/d/deku/town/road5",
		"daggerdale" : "/d/dagger/Daggerdale/fountain/fountain",
		"southwest" : "/d/av_rooms/lurue/hub_01",
		"drowroads" : "/d/dagger/keep/road/road7",
		"shadow" : "/d/shadow/room/city/adventure",
		"muuldaan" : "/d/shadow/room/muuldaan/rooms/cavern1",
		"offestry" : "/d/newbie/rooms/town/square",
		"kildare" : "/d/shadow/room/kildare/rooms/ptrail1",
		"tonovi" : "/d/dagger/tonovi/town/street5",
		"tabor" : "/d/darkwood/tabor/room/cnchall",
		"kinaro" : "/d/dagger/kinaro/guard3",
		"tharis" : "/d/tharis/Tharis/main8",
		"asgard" : "/d/laerad/parnelli/asgard/as08",
		"exchange" : "/d/dagger/exchange/rooms/hallway",
		"juran" : "/d/shadow/juran/city/quest_room",
		"seneca" : "/d/attaya/seneca/questhall",
		"torm" : "/d/dagger/Torm/city/c45",
	]));

}