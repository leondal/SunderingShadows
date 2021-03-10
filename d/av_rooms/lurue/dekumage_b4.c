// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_b4");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("tropical");

    set_short("a basement room");

    set_long("This chamber seems to have fared well against the encroaching swamp.  There is little sign of water damage to the walls and the equipment stored in here, mostly old bedding, clothes and discarded supp"
	"lies, appear to be in good condition.  Crates and boxes keep everything neat, and wooden planks across the floor keep things dry should water ever flood the room.  A small walkway along the southern e"
	"dge of the room provides a means of navigating without having to walk across these boards. "
	);

    set_smell("default","
The crisp scent of cedar mingles with a somewhat acidic smell.");
    set_listen("default","You could have sworn you heard something hiss when you opened the door.");

    set_search("planks","%^GREEN%^You search around on the ground and under the planks, and notice a ladder leading down!%^RESET%^");
    set_search("crates","The crates are in good condition and are packed full of bedding and unused clothing.");
    set_search("boxes","The boxes are in good condition and are packed full of bedding and unused clothing.");
    
set_items(([ 
	({ "floor", "planks", "boards" }) : "You look about on the floor and notice a few of the planks look to be a bit loose.  Maybe they could be moved?",
	({ "crates", "boxes" }) : "The boxes and crates are neatly piled up so that they are quite tall.  Oddly they don't cover the whole surface of the floor.",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/lurue/dekumage_b3",
		"down" : "/d/av_rooms/lurue/dekumage_b7",
	]));

    set_door("east door","/d/av_rooms/lurue/dekumage_b3","west","manor key","storage");
    add_lock("east door","manor key","storage","A new looking padlock, it appears to be well made and strong.");
    set_locked("east door",1,"storage");
    lock_difficulty("east door",-50,"storage");
    set_open("east door",0);
    set_string("east door","knock","knock on the door");
    set_string("east door","open","The door swings open on its hinges. ");
    set_string("east door","close","The door swings closed on its hinges. ");
    set_door_description("east door","A fairly new wooden door, it looks in good repair and appears to have a new lock.");
}