// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("carn_greed");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("village");
    set_travel("foot path");
    set_climate("temperate");

    set_short("%^BOLD%^%^GREEN%^A Tent Full of Games of Chance%^RESET%^");

    set_long("%^BOLD%^%^GREEN%^This tent has many flaps rolled down to prevent light from coming inside. %^MAGENTA%^Gem stones%^GREEN%^ flicker and glow with their own light. A man stands behind a booth, %^YELLOW%^"
	"heckling%^GREEN%^ customers who have come to try their luck. You see games of %^RED%^dice,%^BLUE%^ darts,%^CYAN%^ and cards%^GREEN%^ everywhere. There is a giant wall of %^RED%^p%^BLUE%^r%^YELLOW%^i%^"
	"CYAN%^z%^WHITE%^e%^RED%^s%^GREEN%^ for the lucky winners to choose from!%^RESET%^"
	);

    set_smell("default","
There is a faint aroma of sweat and oil on the prizes.");
    set_listen("default","You hear the cheers of winners and the groans of losers.");

    
set_items(([ 
	({ "gem", "gem stones", "stones" }) : "These gems are tied down pretty well, but hardly worth the effort compared to the wall of prizes.",
	"prizes" : "This wall has %^YELLOW%^everything%^RESET%^ you could desire for a carnival prize. The %^RED%^lowest%^RESET%^prizes range from teddy bears to cotton candy. The more %^CYAN%^ serious prizes%^RESET%^ are further up the wall. Prominently displayed are swords, axes, rings, bracers, armor of all shapes and sizes. While doubtless some are replicas, your trained adventuring eye can see that there is some %^YELLOW%^serious hardware%^RESET%^ up there too.",
	]));

    set_exits(([ 
		"north" : "/d/av_rooms/myrkul/carn_main_w",
	]));

}