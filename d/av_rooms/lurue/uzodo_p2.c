// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("uzodo_p2");
    set_property("indoors",0);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("heavy forest");
    set_travel("game track");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^A thickly wooded forest%^RESET%^");

    set_long("%^RESET%^%^GREEN%^Cutting through the forest, you follow random %^BOLD%^%^BLACK%^game trails %^RESET%^%^GREEN%^that snake through the trees and foliage.  The heavy %^ORANGE%^branches %^GREEN%^of the s"
	"pruce and pine, hemlock and fir, cypress and cedar all make it difficult to see beyond a few feet and the thick canopy above makes navigating by %^BOLD%^%^CYAN%^sky %^RESET%^%^GREEN%^even harder.  %^B"
	"OLD%^Nettles %^RESET%^%^GREEN%^cluster on the ground, making it %^BOLD%^%^BLACK%^spongy %^RESET%^%^GREEN%^and %^RESET%^thick%^GREEN%^, easy to tread upon until an unseen branch gives way.%^RESET%^"
	);

    set_smell("default","
The earthy smell of plant decay and crushed nettles lingers here.");
    set_listen("default","Animals move through the forest, snapping a twig here and there.");

    
set_items(([ 
	({ "ground", "nettles" }) : "%^BOLD%^%^GREEN%^The thick blanket of nettles covers the ground, hiding small ruts and holes from view until you step into them.  Thankfully, none seem to be deep enough to break an ankle, but twist it perhaps.%^RESET%^",
	({ "trails", "game trails" }) : "%^BOLD%^%^BLACK%^The trails meander about, cutting through the forest with some sort of purpose that isn't completely clear.%^RESET%^",
	({ "tree", "trees", "foliage" }) : "%^BOLD%^%^GREEN%^The trees grow thickly together here creating a natural blind and preventing you from seeing further into the island.  Cypress, cedar, fir, hemlock, pine, spruce, and juniper cluster and spread their thickly nettled branches outward.%^RESET%^",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/lurue/uzodo_p1",
		"north" : "/d/av_rooms/lurue/uzodo_p2",
		"south" : "/d/av_rooms/lurue/uzodo_p2",
		"cave" : "/d/av_rooms/lurue/uzodo_c1",
		"east" : "/d/av_rooms/lurue/uzodo_p2",
	]));

}