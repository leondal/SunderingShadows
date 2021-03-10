// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("swamp_entrance");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("foot path");
    set_climate("temperate");

    set_short("%^YELLOW%^Before a Fort%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^You stand before a crude %^YELLOW%^fort%^RESET%^%^ORANGE%^. Rough hewn logs have been bound together to form a sturdy %^GREEN%^barricade.%^ORANGE%^ The tops of the logs have been wh"
	"ittled down into points, and a large gate can be closed in defense. A foot path worn down by many bare feet lead up to the fort.%^RESET%^"
	);

    set_smell("default","
You can smell wood smoke, and the rotting funk of the swamp.");
    set_listen("default","The swamp is alive with mosquitos and other vermin that never quiets.");

    
set_items(([ 
	"barricade" : "The walls look very strong and a good ten feet tall.",
	"wall" : "The fort is just a couple low slung buildings with the wall for protection.",
	"path" : "The path is very crude and mostly due to being worn down by bare feet.",
	"fort" : "You can't see much behind the tall walls.",
	]));

    set_exits(([ 
		"north" : "/d/laerad/swamp/swamp44",
		"south" : "/d/av_rooms/myrkul/swamp_fort",
	]));

    set_door("gate","/d/av_rooms/myrkul/swamp_fort","south","gate key","lock");
    add_lock("gate","gate key","lock","This is a standard lock.");
    set_locked("gate",1,"lock");
    lock_difficulty("gate",-20,"lock");
    set_open("gate",0);
    set_string("gate","knock","pounds on the");
    set_string("gate","open","The gate swings open silently.");
    set_string("gate","close","The gate swings closed silently.");
    set_door_description("gate","This is a sturdy gate made of wooden logs. It has iron hinges and is very heavy.");
}