// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("a_tomb5");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^BOLD%^%^YELLOW%^V%^CYAN%^a%^YELLOW%^u%^CYAN%^l%^YELLOW%^t%^RESET%^%^MAGENTA%^ of %^BOLD%^%^WHITE%^S%^YELLOW%^t%^WHITE%^a%^YELLOW%^r%^WHITE%^s%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^An %^RESET%^%^MAGENTA%^oval %^BOLD%^%^BLACK%^room opens up before. The ceiling is high and arched forming a great dome and becoming one with the walls, with %^YELLOW%^gl%^CYAN%^i%^YEL"
	"LOW%^mmer%^CYAN%^i%^YELLOW%^ng %^BOLD%^%^WHITE%^stars%^BLACK%^ that seem to shift and move in to match the %^CYAN%^night sky%^BLACK%^. In the center of the room is a great %^YELLOW%^Altar%^BLACK%^, br"
	"acketed by two sarcophaguses on either side. The sarcophaguses have %^YELLOW%^a%^WHITE%^n%^YELLOW%^ge%^WHITE%^l%^YELLOW%^ic%^BLACK%^ figures of mighty beings engraved on the lids. On the altar itself "
	"sits a simple stand on which might hold a scroll. Unlike the rooms leading to this %^RESET%^%^MAGENTA%^vault%^BOLD%^%^BLACK%^, this place seems untouched by the %^GREEN%^tides of time%^RESET%^. "
	);

    set_smell("default","
You smell nothing.");
    set_listen("default","%^YELLOW%^A%^WHITE%^n%^YELLOW%^gel%^WHITE%^i%^YELLOW%^c %^RESET%^%^CYAN%^hymns voiced in a %^GREEN%^forgotten language%^CYAN%^ reverberate from the walls, without %^WHITE%^source%^CYAN%^ and without %^BOLD%^%^BLACK%^end.%^RESET%^");

    set_search("outline","%^BOLD%^%^GREEN%^The %^WHITE%^stars%^GREEN%^ here seem to almost to form a kind of illusionary <passage>.%^RESET%^");
    set_search("stars","You think that the stars seem to form some kind of %^BOLD%^%^BLUE%^outline.%^RESET%^");
    
set_items(([ 
	"outline" : "%^BOLD%^%^GREEN%^The %^WHITE%^stars%^GREEN%^ here seem to almost to form a kind of illusionary <passage>.%^RESET%^",
	({ "ceiling", "walls", "wall" }) : "%^BOLD%^%^WHITE%^You see the %^RESET%^%^MAGENTA%^stars%^BOLD%^%^WHITE%^ and %^CYAN%^moons%^WHITE%^ slowly move in their orbit, like a map of the outside %^BLUE%^night sky%^RESET%^.",
	({ "sarcophagus", "sarcophaguses" }) : "%^BOLD%^%^CYAN%^The figures on the sarcophaguses appear to be %^WHITE%^Solar%^CYAN%^ the mighty defenders of the heavens. They appear to be undisturbed. %^RESET%^",
	({ "stand", "scroll" }) : "%^BOLD%^%^BLACK%^The stand sits in the center of the %^RESET%^%^MAGENTA%^warded%^BOLD%^%^BLACK%^ altar. The scroll itself seems to burn bright with %^YELLOW%^power%^BLACK%^ in your minds eye, while at the same time seeming a %^RESET%^simple aged scroll.%^RESET%^",
	"stars" : "%^BOLD%^%^WHITE%^You see the %^RESET%^%^MAGENTA%^stars%^BOLD%^%^WHITE%^ and %^CYAN%^moons%^WHITE%^ slowly move in their orbit, like a map of the outside %^BLUE%^night sky%^RESET%^.",
	"altar" : "%^YELLOW%^The altar is of solid gold, a simple structure like a table with four tapered square legs and a flat rectangular top. %^RESET%^%^MAGENTA%^R%^BLUE%^u%^MAGENTA%^n%^BLUE%^e%^MAGENTA%^s%^YELLOW%^ of warding, protection, and timelessness are intricately carved into the top.%^RESET%^",
	]));

    set_exits(([ 
		"south" : "/d/av_rooms/asmodeus/a_tomb4",
		"passage" : "/d/av_rooms/asmodeus/a_tomb6",
	]));



    set_invis_exits(({ "passage" }));

}