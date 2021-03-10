// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("castle9");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("back alley");
    set_climate("temperate");

    set_short("Castle Halls");

    set_long("%^RESET%^This is an aging castle interior.  The major walls, floor and ceiling are built from roughly cut stones, thinly mortared.  Judging from the way noises are absorbed, the walls must be very thi"
	"ck and durable indeed.  Years have left their mark on many features around you.  %^BOLD%^Cobwebs%^RESET%^ obscure many of the open spaces and drift lazily in the open air.  A %^RED%^dank%^RESET%^, %^R"
	"ED%^oily%^RESET%^ feeling suggests that organisms still thrive somewhere, making it somewhat difficult to breathe.  The occasional rusting %^BOLD%^%^BLACK%^sconce%^RESET%^ or %^ORANGE%^hanging%^RESET%"
	"^ suggests that civilized things once lived here, but not for quite some time.%^RESET%^"
	);

    set_smell("default","
%^GREEN%^It smells like age and mildew.%^RESET%^");
    set_listen("default","%^ORANGE%^You hear distant dripping.%^RESET%^");

    
set_items(([ 
	({ "webs", "cobwebs" }) : "Cobwebs riddle the castle ruins, everywhere they can.  The webbing is just a little too thick, suggesting very big spiders.",
	({ "hanging", "hangings" }) : "%^ORANGE%^The walls look like they once proudly displayed a variety of hangings, tapestries and banners.  They have long since decayed so as to be unrecognizable.%^RESET%^",
	({ "sconce", "sconces" }) : "Rusting sconces probably once held torches.  Very little light penetrates here now.",
	]));

    set_exits(([ 
		"south" : "/d/av_rooms/tiamat/castle10",
		"north" : "/d/av_rooms/tiamat/castle8",
	]));

}