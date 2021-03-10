// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("location_chapel_balcony");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^RESET%^%^MAGENTA%^Chapel Balcony%^RESET%^");

    set_long("You stand in the balcony of the chapel. There is an old pipe organ here which strangely enough seems to be in working order. There is enough room here for a full choir, and from this height, you have "
	"a commanding view of the rest of the church. The center of the church is dominate by a piles of rotting pews. The front of the church is a stone altar for services, and the back of the church looks to"
	" be something of a gathering area. Alcoves bracket the pews to the north and south. Overall the church has been fiercely damaged by zombies and the undead. "
	);

    set_smell("default","
The air is stale here, and fresh air from outside would be a welcome relief.");
    set_listen("default","Something is moving down there, you can hear it.");

    
set_items(([ 
	"organ" : "%^BOLD%^%^GREEN%^This organ is made of %^YELLOW%^beautiful%^RESET%^%^ORANGE%^ copper pipes%^BOLD%^%^GREEN%^ and seems to be in good working repair. You could even serenade the chapel with a %^BLACK%^fugue%^GREEN%^ if it pleased you.%^RESET%^",
	]));

    set_exits(([ 
		"down" : "/d/av_rooms/myrkul/location_chapel_nalcove",
	]));

}