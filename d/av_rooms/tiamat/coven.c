// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("coven");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("hut");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^RESET%^%^GREEN%^Coven Lair%^RESET%^");

    set_long("%^RESET%^%^GREEN%^The surrounding area confuses the senses, making it difficult to discern if you are indoors or out.  Overhead, gnarled %^RESET%^%^ORANGE%^tree branches%^GREEN%^ have grown into somet"
	"hing like a natural domed ceiling, obscuring the view of the sky.  Dry, dead pine needles cover the simple soil floor.  In the center of the 'room' a large %^BOLD%^%^BLACK%^iron cauldron%^RESET%^%^GRE"
	"EN%^ simmers aggressively over a weak %^YELLOW%^f%^RED%^i%^YELLOW%^r%^RED%^e%^RESET%^%^GREEN%^.  Flames licking the sides of the cauldron cast the area in %^BOLD%^%^BLACK%^dancing shadows%^RESET%^%^GR"
	"EEN%^.  Strewn about the floor is a hodgepodge of animal bones, rotten fruits, empty bottles and dried up salves, lending the place not only a sense of claustrophobia, but also a fetid %^BOLD%^odor%^R"
	"ESET%^%^GREEN%^."
	);

    set_smell("default","
%^ORANGE%^It reeks of organic decay and smoke.%^RESET%^");
    set_listen("default","%^GREEN%^You hear the steady crackle of a wood fire.");

    
set_items(([ 
	"cauldron" : "%^BOLD%^%^BLACK%^This is a large, well used cauldron.  Probably originally used for cooking, it now serves as container for some foul smelling brew.%^RESET%^",
	]));

    set_exits(([ 
		"leave" : "/d/deku/forest/dforest6-3",
	]));

}