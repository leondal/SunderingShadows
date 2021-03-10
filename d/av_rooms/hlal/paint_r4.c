// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("paint_r4");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^MAGENTA%^Trapped within a painting %^WHITE%^- %^YELLOW%^Treasure Room%^RESET%^");

    set_long("%^ORANGE%^The lighting here is dim. A few %^RED%^small %^ORANGE%^torches are centered on the cold stone walls, giving off %^BOLD%^%^BLACK%^shadows %^RESET%^%^ORANGE%^in random locations. %^RED%^Dark r"
	"ed velvet %^ORANGE%^curtains the walls, pulled aside only to reveal paintings of %^YELLOW%^lustful encounters. %^RESET%^%^ORANGE%^Near the back of the room is a large table marked as -Private-. Behind"
	" it are shelves that are all neatly arranged with unbelievable %^GREEN%^treasures. %^ORANGE%^Strangely enough everyone is too busy with their own pleasures to guard the loot.%^RESET%^ "
	);

    set_smell("default","
It smells like lust and money.");
    set_listen("default","%^BOLD%^%^WHITE%^Erotic moans can be heard coming from the shadows");

    
set_items(([ 
	"treasures" : "%^YELLOW%^The shelves are full of wealth. The only thing that looks out of place is a small ivory statue that faces the %^CYAN%^northwest.%^RESET%^",
	]));

    set_exits(([ 
		"northwest" : "/d/av_rooms/hlal/paint_r5",
	]));



    set_invis_exits(({ "northwest" }));

}