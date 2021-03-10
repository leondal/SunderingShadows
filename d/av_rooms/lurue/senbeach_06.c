// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("senbeach_06");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("shallow water");
    set_travel("rutted track");
    set_climate("temperate");

    set_short("%^BOLD%^%^CYAN%^S%^BLUE%^w%^RESET%^%^CYAN%^i%^BOLD%^mm%^BLUE%^i%^RESET%^%^CYAN%^n%^BOLD%^g %^WHITE%^in the Attaya Cove%^RESET%^");

    set_long("%^RESET%^%^CYAN%^You swim from the %^BOLD%^%^BLACK%^hole %^RESET%^%^CYAN%^and break the surface of the ocean.  Gasping your first breath of %^BOLD%^f%^WHITE%^r%^CYAN%^e%^WHITE%^s%^CYAN%^h a%^WHITE%^i%"
	"^CYAN%^r %^RESET%^%^CYAN%^since you entered the underwater tunnel, you glance about your surroundings, taking in the breath taking beauty of the shoreline and the natural cove created by the %^BOLD%^%"
	"^BLACK%^j%^RESET%^%^ORANGE%^e%^RESET%^t%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^i%^RESET%^e%^ORANGE%^s %^CYAN%^that stretch out into the ocean.  Flanked by a crown of %^YELLOW%^g%^WHITE%^o%^RESET%^l%^YELL"
	"OW%^d%^WHITE%^e%^RESET%^n %^CYAN%^cliffs, the beach is a swath of %^ORANGE%^f%^YELLOW%^l%^RESET%^a%^ORANGE%^x%^YELLOW%^e%^RESET%^%^ORANGE%^n %^CYAN%^colored sand that spills into the brilliant %^BOLD%"
	"^%^BLUE%^b%^GREEN%^l%^CYAN%^u%^BLUE%^e%^GREEN%^-%^CYAN%^g%^BLUE%^r%^GREEN%^e%^CYAN%^e%^BLUE%^n%^RESET%^ %^CYAN%^waters.  Creating a breakwater, the long fingers of the %^BOLD%^%^BLACK%^j%^RESET%^%^ORA"
	"NGE%^e%^RESET%^t%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^i%^RESET%^e%^ORANGE%^s %^CYAN%^extend out into those waves, breaking up the rolling current and calming their movements, allowing you to easily swi"
	"m to the shore.%^RESET%^"
	);

    set_smell("default","
The clean scent of the ocean rises on the breeze.");
    set_listen("default","You can hear the crashing of waves on the shore above the occasional cry of a seagull.");

    
set_items(([ 
	({ "jetties", "jetty" }) : "%^RESET%^Stretching out into the sea like arms, the jetties look to be natural rock, though it's anyone's guess as to whether or not magic was used in their creation.  Their position provides a safe, relatively concealed cove here for the people of Seneca to enjoy.",
	({ "ocean", "water", "waves" }) : "%^RESET%^The breathtaking ocean %^BOLD%^%^BLUE%^s%^CYAN%^p%^BLUE%^a%^CYAN%^r%^BLUE%^k%^CYAN%^l%^BLUE%^e%^CYAN%^s %^RESET%^%^CYAN%^green %^RESET%^and %^BOLD%^%^BLUE%^blue %^RESET%^in the light, while the crashing waves create %^BOLD%^%^WHITE%^white surf %^RESET%^upon the shore.",
	({ "cliffs", "cliff" }) : "%^RESET%^Rising high overhead are the %^ORANGE%^cliffs %^RESET%^supporting the town of Seneca.  The deep brown rock is shot through with %^YELLOW%^golden veins%^RESET%^, causing the cliff to sparkle when the light hits it.  A  winding pathway meanders up the cliff's face, leading to the town.",
	({ "sand", "sands" }) : "%^RESET%^The soft sand of the beach seems to glitter %^YELLOW%^golden %^RESET%^in any light.  The beach itself is not very wide between the crashing surf and the cliffs upon which this path is carved, but there is definitely enough usable space for people to enjoy.",
	"hole" : "%^BOLD%^%^BLACK%^The rock of one of the jetties appears to have broken or collapsed, opening a jagged hole leading into some sort of underwater cave or tunnel.%^RESET%^",
	]));

    set_exits(([ 
		"shore" : "/d/attaya/newseneca/rooms/shore1",
		"hole" : "/d/av_rooms/lurue/senbeach_05",
	]));

}