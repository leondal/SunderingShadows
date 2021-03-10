// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("a_tomb6");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^YELLOW%^Secret Armory%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This rooms seems to be a pocket plane that serves as an armory for the defenders of the %^RESET%^%^MAGENTA%^T%^CYAN%^o%^MAGENTA%^mb%^BOLD%^%^BLACK%^. A simple table stands here with v"
	"arious implements on them. The table itself seems to be made out of the stuff of the plane, and everything else is cloaked in shadow. You feel you might take the things from this place and they will e"
	"xist elsewhere but nothing of this plane could withstand survival in the Prime.%^RESET%^"
	);

    set_smell("default","
You smell nothing");
    set_listen("default","No sound echos in this place.");

    
set_items(([ 
	"outline" : "%^BOLD%^%^GREEN%^The %^WHITE%^stars%^GREEN%^ here seem to almost to form a kind of illusionary <passage>.%^RESET%^",
	({ "ceiling", "walls", "wall" }) : "%^BOLD%^%^WHITE%^You see the %^RESET%^%^MAGENTA%^stars%^BOLD%^%^WHITE%^ and %^CYAN%^moons%^WHITE%^ slowly move in their orbit, like a map of the outside %^BLUE%^night sky%^RESET%^.",
	({ "sarcophagus", "sarcophaguses" }) : "%^BOLD%^%^CYAN%^The figures on the sarcophaguses appear to be %^WHITE%^Solar%^CYAN%^ the mighty defenders of the heavens. They appear to be undisturbed. %^RESET%^",
	({ "stand", "scroll" }) : "%^BOLD%^%^BLACK%^The stand sits in the center of the %^RESET%^%^MAGENTA%^warded%^BOLD%^%^BLACK%^ altar. The scroll itself seems to burn bright with %^YELLOW%^power%^BLACK%^ in your minds eye, while at the same time seeming a %^RESET%^simple aged scroll.%^RESET%^",
	"table" : "The table is made of nothingness. The only thing real are those items which might be found here.",
	({ "walls", "ceiling", "floor" }) : "These elements of the pocket plane are insubstantial barriers of shadow.",
	"altar" : "%^YELLOW%^The altar is of solid gold, a simple structure like a table with four tapered square legs and a flat rectangular top. %^RESET%^%^MAGENTA%^R%^BLUE%^u%^MAGENTA%^n%^BLUE%^e%^MAGENTA%^s%^YELLOW%^ of warding, protection, and timelessness are intricately carved into the top.%^RESET%^",
	]));

    set_exits(([ 
		"out" : "/d/av_rooms/asmodeus/a_tomb5",
	]));

}