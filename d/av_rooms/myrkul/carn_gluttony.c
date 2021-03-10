// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("carn_gluttony");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("village");
    set_travel("foot path");
    set_climate("temperate");

    set_short("%^RESET%^%^ORANGE%^A %^YELLOW%^b%^RED%^o%^YELLOW%^is%^RED%^t%^YELLOW%^ero%^RED%^u%^YELLOW%^s%^RESET%^%^ORANGE%^ Tavern!%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^Sloppy drunk patrons are slamming down %^YELLOW%^booze%^RESET%^%^ORANGE%^, as a %^MAGENTA%^beautiful, %^BOLD%^buxom%^RESET%^%^MAGENTA%^ bartender%^ORANGE%^ keeps the alcohol flowing"
	". The tent is a drab brown with a bar at the back and tall tables scattered throughout. It is %^BOLD%^%^WHITE%^standing room only%^RESET%^%^ORANGE%^ in here, with a heavy flow of foot traffic. A sign "
	"at the front %^BOLD%^%^RED%^boldly%^RESET%^%^ORANGE%^ states, %^YELLOW%^-Outdrink the Orc, and the liquors free-%^RESET%^%^ORANGE%^ The reigning champion, a beer bellied half-orc stands nearby, perfor"
	"ming feats of %^BOLD%^%^GREEN%^liver regeneration%^RESET%^%^ORANGE%^ and alcohol induced %^RED%^fire-breathing%^ORANGE%^ to much applause.%^RESET%^"
	);

    set_smell("default","
You smell hops from all the beer.");
    set_listen("default","Its a noisy, boisterous bar, full of people getting sloppy drunk.");

    
set_items(([ 
	"tent" : "Its rather large and dimly lit. But there's a lot of cheer in here nonetheless.",
	"sign" : "The sign says - Outdrink the Orc, and the liquors free - But it does not seem like the tent is losing much money on the deal, because the orc must have a fiercesome constitution.",
	"bar" : "Its a wooden bar that can be taken apart as the carnival moves around quite often.",
	]));

    set_exits(([ 
		"south" : "/d/av_rooms/myrkul/carn_main_e",
	]));

}