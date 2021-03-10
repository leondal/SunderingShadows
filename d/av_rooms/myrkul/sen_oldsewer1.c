// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("sen_oldsewer1");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("built tunnel");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^RESET%^%^ORANGE%^Old S%^GREEN%^e%^ORANGE%^wer%^CYAN%^ Beneath %^BOLD%^S%^RESET%^%^CYAN%^e%^BOLD%^neca%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This is an ancient aqueduct system left over from the old city. The air is tight here, and the walls feel very close in. Water no longer flows here as the new sewers have blocked off "
	"the old construction. Bricks block the canal in either direction. The dust is thick with age. You can see an old maintenance %^RESET%^%^ORANGE%^trap door%^BOLD%^%^BLACK%^ in the brick wall here.%^RESE"
	"T%^"
	);

    set_smell("default","
It smells like sewer");
    set_listen("default","The familiar sound of rats scratching echos from somewhere in the darkness.");

    set_search("floor","You see tracks leading to the north wall and to the west wall.");
    set_search("ceiling","Very little light is here, and what little there is comes from tiny cracks and phosphorescent moss.");
    set_search("north wall","There is a gap in the bricks here, and you think you can go <north> by squeezing through the gap.");
    set_search("west wall","There is a gap in the bricks here, and you think you can go <west> by squeezing through the bricks here.");
    set_search("walls","The bricks here are shrouded in darkness, and what looks like a firm wall might be deceiving.");
    
set_items(([ 
	"floor" : "The floors are covered in dust.",
	"ceiling" : "The ceiling is made of old bricks. ",
	"bricks" : "The bricks are new construction and look quite sturdy.",
	"walls" : "The bricks are new construction compared to the walls and they block the channel leaving this part of the sewer entombed.",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/myrkul/sen_oldsewer3",
		"north" : "/d/av_rooms/myrkul/sen_oldsewer2",
		"trapdoor" : "/d/av_rooms/myrkul/sen_sewer6",
	]));



    set_invis_exits(({ "trapdoor", "trapdoor", "north", "west" }));

    set_door("trap door","/d/av_rooms/myrkul/sen_sewer6","trapdoor","sewer key","lock");
    add_lock("trap door","sewer key","lock","This is a simple lock.");
    set_locked("trap door",1,"lock");
    lock_difficulty("trap door",-20,"lock");
    set_open("trap door",0);
    set_string("trap door","knock","pounds on the");
    set_string("trap door","open","The trapdoor creaks open");
    set_string("trap door","close","The trapdoor creaks closed");
    set_door_description("trap door","This is an old maintenance trap door. It looks very rusty. To squeeze through, you will have to go <trapdoor>.");
}