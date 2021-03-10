// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("fissure2");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLUE%^M%^CYAN%^i%^BLUE%^sshapen C%^CYAN%^a%^BLUE%^ve%^RESET%^");

    set_long("You stand in a misshapen cave. The ceiling seems like a triangular mishmash of fallen stones. The floor, by contrast, seems quite unnatural. A white metal seems to have been shredded by an earthquake,"
	" leaving a hole into what seems to be a vault. A fine dust seems to have spread around the hole, and a silent dread seems to exude from the vault."
	);

    set_smell("default","
It smells like dirt.");
    set_listen("default","You hear the shifting of the earth.");

    
set_items(([ 
	"dust" : "There appears to be footprints in the dust leading from the Vault.",
	"metal" : "Unfortunately for you, you do not have dragon fire, because it looks like Adamantium.",
	"stones" : "The stones for a vague roof over the vault, while others have tumbled into the depths. The entire area seems unstable.",
	]));

    set_exits(([ 
		"fissure" : "/d/av_rooms/myrkul/fissure1",
		"hole" : "/d/av_rooms/myrkul/vault",
	]));

}