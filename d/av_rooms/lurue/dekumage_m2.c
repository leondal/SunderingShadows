// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_m2");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("decayed floor");
    set_climate("tropical");

    set_short("%^BOLD%^%^WHITE%^An old manor house%^RESET%^");

    set_long("%^RESET%^The start of a long hallway begins here and leads further back into the manor house.   Just as was found outside, so the interior suffers from %^BOLD%^%^BLACK%^time %^RESET%^and %^CYAN%^dampn"
	"ess%^RESET%^, slowly deteriorating as the swamp encroaches.  The once beautiful panels of %^ORANGE%^wood %^RESET%^that lined the walls are peeling, leaving raw patches of wood and splinters to contend"
	" with.  Stretching along the floor is a %^RED%^threadbare rug%^RESET%^, its color long since lost to a %^ORANGE%^dirty brown%^RESET%^.  To the east the hall continues, and you can see sitting areas bo"
	"th north and south of you."
	);

    set_smell("default","
The air smells of ruin and mold.");
    set_listen("default","The boards under your feet groan with your weight.");

    
set_items(([ 
	({ "floor", "rug" }) : "%^RED%^Looking at the floor you can see that a once plush rug stretched along the length of the hallway.  Though you see only a small amount of design work along the edges it was probably at one time very soft under foot.  Now it is thredbare and dirty.%^RESET%^",
	({ "walls", "panels", "wood" }) : "%^ORANGE%^The walls appear to have at one time been layered with thin panels of painted wood.  The paper thin sheets are nearly all curled and ruined, though you can see how they once held fanciful images.%^RESET%^",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/lurue/dekumage_m1",
		"north" : "/d/av_rooms/lurue/dekumage_m4",
		"south" : "/d/av_rooms/lurue/dekumage_m6",
		"east" : "/d/av_rooms/lurue/dekumage_m3",
	]));

    set_door("entry door","/d/av_rooms/lurue/dekumage_m1","west","manor key","entry lock");
    add_lock("entry door","manor key","entry lock","The lock is made of iron and looks to be in fairly good repair.");
    set_locked("entry door",1,"entry lock");
    lock_difficulty("entry door",-30,"entry lock");
    set_open("entry door",0);
    set_string("entry door","knock","pounds on the");
    set_string("entry door","open","You put your weight against the heavy wooden door and shove it open.");
    set_string("entry door","close","With a heave, you close the heavy wooden door.");
    set_door_description("entry door","%^RESET%^%^ORANGE%^This large wooden door is covered in fancy scrollwork and inset with delightful panels of amethyst glass.  Unfortunately, time and weather have swollen the wood to the point that the door is nearly wedged into the door jam.  Though, you do notice evidence of it having been opened recently. %^RESET%^");
}