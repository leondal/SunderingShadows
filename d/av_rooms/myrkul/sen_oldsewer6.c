// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("sen_oldsewer6");
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
You smell fresh air nearby.");
    set_listen("default","You hear the clinking of gold and the low whispers of business nearby.");

    set_search("floor","You see tracks leading to the north wall.");
    set_search("ceiling","The ceiling is made of old bricks. A trap door is hidden by some loose bricks.");
    set_search("north wall","There is a gap in the bricks here, and you think you can go <north> by squeezing through the gap.");
    set_search("bricks","The bricks are shrouded in darkness and the sturdy looking construction might be deceiving.");
    set_search("walls","The bricks are shrouded in darkness and the sturdy looking construction might be deceiving.");
    
set_items(([ 
	"floor" : "The floors are covered in dust.",
	"ceiling" : "The ceiling is made of old bricks.",
	"bricks" : "The bricks are new construction and look quite sturdy.",
	]));

    set_exits(([ 
		"north" : "/d/av_rooms/myrkul/sen_oldsewer3",
		"trapdoor" : "/d/attaya/seneca/cguilds/thief/thief10",
	]));



    set_invis_exits(({ "north", "trapdoor" }));

    set_door("trap door","/d/attaya/seneca/cguilds/thief/thief10","trapdoor","sewer key","lock");
    add_lock("trap door","sewer key","lock","This is a standard lock.");
    set_locked("trap door",1,"lock");
    lock_difficulty("trap door",-20,"lock");
    set_open("trap door",0);
    set_string("trap door","knock","pounds on the");
    set_string("trap door","open","The trapdoor creaks open.");
    set_string("trap door","close","The trapdoor creaks closed.");
    set_door_description("trap door","This is a well built, sturdy trapdoor made out of wood and banded with steel. Once you get it open you can go <trapdoor> to get through the door.");
}