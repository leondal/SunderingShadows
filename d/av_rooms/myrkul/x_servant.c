// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("x_servant");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^BOLD%^%^CYAN%^Servant Quarters%^BLACK%^ of House %^YELLOW%^X%^RESET%^%^ORANGE%^o%^YELLOW%^r%^RESET%^%^ORANGE%^l%^YELLOW%^o%^RESET%^%^ORANGE%^r%^YELLOW%^r%^RESET%^%^ORANGE%^i%^YELLOW%^n%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^Cots line the back wall of this stark stone room where %^CYAN%^exhausted%^GREEN%^ e%^RESET%^%^GREEN%^l%^BOLD%^ven %^RED%^s%^RESET%^%^RED%^l%^BOLD%^aves%^BLACK%^ come to rest. Above th"
	"e cots, glowing %^CYAN%^s%^RESET%^%^CYAN%^i%^BOLD%^g%^RESET%^%^CYAN%^i%^BOLD%^ls%^BLACK%^ have been etched into the stone. Mops, brooms, and buckets are arranged tidily next to a well in the center of"
	" the room. A few rags of extra clothing hang from a line. It is clear that no filth is tolerated in the House, even here. A glowing %^YELLOW%^orb%^BLACK%^ hangs near the ceiling providing some light. "
	"%^RESET%^"
	);

    set_smell("default","
This smells like cleaning product.");
    set_listen("default","You hear snoring servant");

    
set_items(([ 
	({ "cots", "cot" }) : "The cots are the only comfort in this room.",
	({ "rags", "clothing", "clothes" }) : "The clothes are made of threadworn burlap, doubtless fashioned by the slaves themselves.",
	({ "mop", "mops", "bucket", "buckets", "broom", "brooms" }) : "The mop, bucket, and brooms are in good condition, but have clearly seen a lot of use.",
	({ "sigils", "sigil" }) : "The sigils are written magically so that even an illiterate person can understand the meaning. The sigils say, --%^BOLD%^%^RED%^The old, weak, sick, and lazy shall be fed to the %^RESET%^%^MAGENTA%^spiders%^RESET%^--",
	"well" : "The well looks very deep, but it must have clean water.",
	]));

    set_exits(([ 
		"northeast" : "/d/av_rooms/myrkul/x_whall",
	]));

}