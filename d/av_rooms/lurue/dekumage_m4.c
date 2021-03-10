// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_m4");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("decayed floor");
    set_climate("tropical");

    set_short("%^BOLD%^%^WHITE%^An old manor house%^RESET%^");

    set_long("%^RESET%^This chamber is clearly a sitting room, designed to give guests a place to rest or gather while waiting on the residents of the manor house.  The comfortable looking %^MAGENTA%^chairs %^RESET"
	"%^and %^CYAN%^couches%^RESET%^ that once occupied this room have begun to weather and deteriorate.  The %^RED%^fireplace%^RESET%^ on the north wall is filled with %^BOLD%^%^WHITE%^cobwebs %^RESET%^and"
	" the delicate %^ORANGE%^side tables %^RESET%^are little more then kindling.%^RESET%^"
	);

    set_smell("default","
The air smells of ruin and mold.");
    set_listen("default","The boards under your feet groan with your weight.");

    set_search("fireplace","%^RESET%^%^RED%^You search around in the thick %^WHITE%^cobwebs%^RED%^ and try to find something interesting but all you come back with is moldy %^BOLD%^%^BLACK%^soot %^RESET%^%^RED%^and a case of the sneezes!%^RESET%^");
    
set_items(([ 
	({ "cobweb", "cobwebs" }) : "%^BOLD%^%^WHITE%^The fireplace is full of them.%^RESET%^",
	({ "chairs", "couches", "tables", "chair", "couch", "table" }) : "%^BOLD%^%^WHITE%^Like the rest of the house, this room appears to have fallen on hard times.  The furniture is in poor condition and would likely not support the weight of a guest any longer.%^RESET%^",
	"fireplace" : "%^RESET%^%^RED%^Looking at the brick fireplace you can only imagine how grand it had once been to sit in this parlor and listen to the crackle of flames.%^RESET%^",
	]));

    set_exits(([ 
		"south" : "/d/av_rooms/lurue/dekumage_m2",
	]));

    set_door("entry door","/d/av_rooms/lurue/dekumage_m1","west","manor_key","entry lock");
    add_lock("entry door","manor_key","entry lock","The lock is made of iron and looks to be in fairly good repair.");
    set_locked("entry door",1,"entry lock");
    lock_difficulty("entry door",-30,"entry lock");
    set_open("entry door",0);
    set_string("entry door","knock","pounds on the");
    set_string("entry door","open","You put your weight against the heavy wooden door and shove it open.");
    set_string("entry door","close","With a heave, you close the heavy wooden door.");
    set_door_description("entry door","%^RESET%^%^ORANGE%^This large wooden door is covered in fancy scrollwork and inset with delightful panels of amethyst glass.  Unfortunately, time and weather have swollen the wood to the point that the door is nearly wedged into the door jam.  Though, you do notice evidence of it having been opened recently. %^RESET%^");
}