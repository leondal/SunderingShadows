// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("crypt_archeology_west");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^Un%^BLUE%^t%^BLACK%^ouched R%^RED%^e%^BLACK%^mains of an %^YELLOW%^A%^BLACK%^ncient %^CYAN%^T%^BLACK%^emple%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^You stand in the remains of an ancient temple. Before you lies the bars of a prison cell. The bars have been bent apart by someone with %^RED%^tremendous strength%^BLACK%^, so much so"
	" that the impressions of fingers have been left in the metal. In the cell itself, the walls are covered with %^YELLOW%^hopeful%^BLACK%^ devotions.%^RESET%^"
	);

    set_smell("default","It smells like freedom.");
    set_listen("default","Nothing stirs the air, but a roar of titannic rage still echos through the very fabric of time here.");

    set_search("devotions","You find a phrase here, 'Strength of the Rising Sun'");
    
set_items(([ 
	"devotions" : "It is hard to make out the words, but it seems to be prayers to Lathander. Whoever was here was imprisoned for at least 20 years before he lost track.",
	"bars" : "Pure adamantium. Whatever bent this had unfathomable strength. Too bad you don't have any tools to take a piece or two.",
	]));

    set_exits(([ 
		"up" : "/d/av_rooms/myrkul/crypt_vault_east",
	]));

}
