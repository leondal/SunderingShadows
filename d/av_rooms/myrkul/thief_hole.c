// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("thief_hole");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^A Bolt Hole in the Wall%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^You stand in a shadowy chamber, that appears empty. It is a thief hole, where villains plot their deeds and hold counsel away from prying eyes. It is lit by an orb suspended over a sh"
	"adowy table. Little is here, except the way in and the way out.%^RESET%^"
	);

    set_smell("default","
It smells like dust.");
    set_listen("default","You hear nothing.");

    
set_items(([ 
	"orb" : "The orb sways on a chain, casting a dingy light.",
	]));
}