// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_g3");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("marsh");
    set_travel("game track");
    set_climate("tropical");

    set_short("%^RESET%^%^ORANGE%^A marshy path%^RESET%^");

    set_long("%^RESET%^%^GREEN%^The ground becomes more solid here, climbing up out of the %^CYAN%^marshy swamp %^GREEN%^onto dried ground.  Moss laden limbs and heavy clumps of %^CYAN%^para grass %^GREEN%^and %^BO"
	"LD%^%^GREEN%^alligator weed %^RESET%^%^GREEN%^continue to obscure your view, though you can just make out the %^BOLD%^%^BLACK%^dark form %^RESET%^%^GREEN%^of some sort of structure looming out of the "
	"ground ahead.%^RESET%^"
	);

    set_smell("default","
The heavy smell of rotten vegetation hangs in the air.");
    set_listen("default","The air is alive with the heavy drone of insects.");

    
set_items(([ 
	({ "building", "structure" }) : "%^RESET%^%^ORANGE%^Through the weeds you can just make out some sort of large structure. It looks like there might be a large opening on one side.%^RESET%^",
	({ "plants", "para grass", "weeds", "brush" }) : "%^BOLD%^%^GREEN%^The brush and weed grow close together, obscuring the water and leaving only a faint trial for you to follow through the marshy lands.%^RESET%^",
	]));

    set_exits(([ 
		"south" : "/d/av_rooms/lurue/dekumage_g4",
		"west" : "/d/av_rooms/lurue/dekumage_g2",
	]));

}