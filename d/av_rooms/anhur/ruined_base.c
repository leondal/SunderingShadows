// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("ruined_base");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("rubble");
    set_climate("temperate");

    set_short("A room in shambles");

    set_long("Piles of %^BOLD%^%^WHITE%^rubble%^RESET%^ and dust are scattered about this room. The walls are made of steel with a slight %^BOLD%^%^BLUE%^bluish%^RESET%^ tint.  The walls contain plenty of scraps an"
	"d scratches from all different types of weapons. At one time the west and east exits used to lead to another chamber, but there are currently piles of rubble that would take an army of people weeks to"
	" dig through. The northern exit used to have huge %^BOLD%^%^WHITE%^IRON%^RESET%^ doors leading to the next chamber."
	);

    set_smell("default","
The smell of sulfur and dust settles upon your nose.");
    set_listen("default","The only sound is that of your own %^BOLD%^%^CYAN%^BREATHING%^RESET%^ ");

    set_search("rubble"," A pile of rubble blocks both the west and east exit along with piles scattered about the floor");
    
set_items(([ 
	"doors" : "Massive Iron Doors hang in their hinges lopside and don't impeded movement in the slightest",
	"walls" : " These walls have holes and dents all about them. The cause of this could range from any number of weapon or spell",
	]));

    set_exits(([ 
		"north" : "/d/av_rooms/anhur/ruined_base2",
	]));

}