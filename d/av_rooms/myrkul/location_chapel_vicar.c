// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("location_chapel_vicar");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^RESET%^%^MAGENTA%^Vicar's Chamber%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This is the room of a man driven %^YELLOW%^m%^GREEN%^a%^RED%^d%^BLACK%^. Insane %^WHITE%^s%^BLUE%^p%^RESET%^%^MAGENTA%^i%^BOLD%^%^WHITE%^r%^BLUE%^a%^RESET%^%^MAGENTA%^l%^BOLD%^%^WHITE"
	"%^s%^BLACK%^ are drawn repetitively across the walls. %^RESET%^%^CYAN%^M%^BLUE%^y%^CYAN%^stic s%^BLUE%^y%^CYAN%^mbols%^BOLD%^%^BLACK%^ are scrawled inside the walls of the designs with religious atten"
	"tion to detail. %^RESET%^%^ORANGE%^Books%^BOLD%^%^BLACK%^ and %^WHITE%^scrolls%^BLACK%^ are tossed haphazardly across the room. A table leans against the ground with three legs, the fourth leg carved "
	"on. Dismembered humanoid body parts have also been carved on, and %^RED%^blood%^BLACK%^ is spattered everywhere.%^RESET%^"
	);

    set_smell("default","
It smells like %^YELLOW%^murder.%^RESET%^");
    set_listen("default","You hear not a sound.");

    
set_items(([ 
	({ "symbols", "spirals" }) : "%^RED%^You feel something %^WHITE%^tug%^RED%^ on your very soul as you gaze upon them. Look too long, and you feel as if you might %^MAGENTA%^unhinge%^RESET%^ your mind.%^RESET%^",
	"books" : "Some have been written on human skin. The words and symbols shift as you read them making them impossible to understand.",
	"leg" : "This was being fashioned into some kind of gruesome rod, perhaps for enchantment.",
	"blood" : "It looks rather fresh.",
	"scrolls" : "There might be some scroll that is halfway useful in here...",
	]));

    set_exits(([ 
		"down" : "/d/av_rooms/myrkul/location_chapel_hidden",
	]));

}