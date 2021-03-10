// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("sen_oldsewer4");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("built tunnel");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^RESET%^%^ORANGE%^Old S%^GREEN%^e%^ORANGE%^wer Beneath %^BOLD%^%^CYAN%^S%^RESET%^%^CYAN%^e%^BOLD%^neca%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This is an ancient aqueduct system left over from the old city. The air is tight here, and the walls feel very close in. Water no longer flows here as the new sewers have blocked off "
	"the old construction. Bricks block the canal in either direction. The dust is thick with age.%^RESET%^"
	);

    set_smell("default","
You air smells very stale here, and it is getting hard to breathe.");
    set_listen("default","The familiar sound of rats scratching echos from somewhere in the darkness.");

    set_search("southeast wall","There is a gap in the bricks here, and you think you can go <southeast> by squeezing through the gap.");
    set_search("floor","You see tracks leading to the southeast wall and to the west wall.");
    set_search("ceiling","Very little light is here, and what little there is comes from tiny cracks and phosphorescent moss.");
    set_search("west wall","There is a gap in the bricks here, and you think you can go <west> by squeezing through the gap.");
    set_search("bricks","The bricks are shrouded in darkness and the sturdy looking construction might be deceiving.");
    set_search("walls","The bricks here are shrouded in darkness, and what looks like a firm wall might be deceiving.");
    
set_items(([ 
	"floor" : "The floors are covered in dust.",
	"ceiling" : "The ceiling is made of old bricks.",
	"bricks" : "The bricks are new construction and look quite sturdy.",
	"walls" : "The bricks are new construction compared to the walls and they block the channel leaving this part of the sewer entombed.",
	]));

    set_exits(([ 
		"southeast" : "/d/av_rooms/myrkul/sen_oldsewer2",
		"west" : "/d/av_rooms/myrkul/sen_oldsewer5",
	]));



    set_invis_exits(({ "southeast", "west" }));

}