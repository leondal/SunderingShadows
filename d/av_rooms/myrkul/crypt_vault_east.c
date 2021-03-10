// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("crypt_vault_east");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^Crypt Vault%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^You stand in the inky blackness of a vault deep underground inside the crypt. The remains of decomposing coffins litters the floor and skeletal remains lie out in the open. This place"
	" is truly ancient.%^RESET%^"
	);

    set_smell("default","
It smells like ancient skeletons and rotted coffins");
    set_listen("default","The only sound is that of your own footsteps.");

    set_search("wall","The <shadows> seem rather deeper here.");
    
set_items(([ 
	({ "skeletons", "skeleton" }) : "Yep, the skeletons rest in pieces.",
	({ "coffin", "coffins" }) : "The coffins seem to be covering part of the wall.",
	"wall" : "The back wall here seems oddly distorted.",
	]));

    set_exits(([ 
		"up" : "/d/av_rooms/myrkul/crypt_hall_east2",
		"shadows" : "/d/av_rooms/myrkul/crypt_archeology_east",
	]));



    set_invis_exits(({ "shadows" }));

}