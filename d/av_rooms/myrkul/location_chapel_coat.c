// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("location_chapel_coat");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^RESET%^%^MAGENTA%^Chapel Coatroom%^RESET%^");

    set_long("%^RESET%^%^MAGENTA%^This room once held all the %^RED%^c%^BLUE%^o%^RED%^ats%^MAGENTA%^ and %^GREEN%^h%^ORANGE%^a%^GREEN%^ts%^MAGENTA%^ for parishioners at the chapel. Long %^BOLD%^%^BLACK%^bars%^RESET"
	"%^%^MAGENTA%^ run on either side of the door to the back wall. Hangers and the %^RED%^tattered remains%^MAGENTA%^ of old coats and hats litter the floor. The low ceiling, shallow walls, and marble flo"
	"or reveal nothing but %^WHITE%^cold stone%^MAGENTA%^. Light flows in from the Chapel entry room.%^RESET%^"
	);

    set_smell("default","
It smells musty like %^RED%^rot%^RESET%^ and %^GREEN%^mold%^RESET%^.");
    set_listen("default","Distant sounds of movement outside can be heard in here.");

    set_search("remains","You find the random curious memento in the pile of rotting coats, but little else.");
    
set_items(([ 
	({ "walls", "ceiling", "wall", "floor" }) : "The ceiling, walls, and floor reveal no secrets and are quite ordinary.",
	({ "remains", "rotting remains" }) : "The old coats have been left here to rot.",
	"hangers" : "The old wire hangers are of little use now.",
	"bars" : "The bars were once used to rack coats and hats on hangers.",
	]));

    set_exits(([ 
		"south" : "/d/av_rooms/myrkul/location_chapel_entry",
	]));

}