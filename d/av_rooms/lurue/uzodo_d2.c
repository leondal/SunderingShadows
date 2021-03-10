// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("uzodo_d2");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("beach");
    set_travel("dirt road");
    set_climate("temperate");

    set_short("%^YELLOW%^A sharply sloping beach%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^The thin strip of shore along the inlet gives way to a wider part of the beach where the %^BLUE%^ocean %^ORANGE%^meets the %^CYAN%^stream%^ORANGE%^.  Here the land flows sharply dow"
	"n to the ocean in a spill of dark %^BOLD%^%^BLACK%^gray-brown sand %^RESET%^%^ORANGE%^spotted here and there with a few %^BOLD%^%^BLACK%^rocks %^RESET%^%^ORANGE%^and %^RESET%^shells%^ORANGE%^.  Beyond"
	" the %^BLUE%^deep blue waters %^ORANGE%^of the Saakrune Sea spread, rolling in and out over the beach with crashing waves.  Inland, the %^GREEN%^trees %^ORANGE%^cluster close together, preventing you "
	"from seeing anything beyond.%^RESET%^"
	);

    set_smell("default","
The tang of salt air blows in from the ocean.");
    set_listen("default","The crash of waves fills the air.");

    set_search("sand","%^ORANGE%^You search around in the sand but come up with only rocks and seashells this time.%^RESET%^");
    
set_items(([ 
	({ "ocean", "sea" }) : "%^BOLD%^%^BLUE%^The vast Saakrune Sea stretches out to the horizon, its deep blue waters flickering with waves.%^RESET%^",
	({ "trees", "tree", "foliage", "plants" }) : "%^BOLD%^%^GREEN%^The trees grow thickly together here creating a natural blind and preventing you from seeing further into the island.  Cypress, cedar, fir, hemlock, pine, spruce, and juniper cluster and spread their thickly nettled branches outward.%^RESET%^",
	({ "seashells", "shells", "rocks", "rock", "sand" }) : "%^BOLD%^%^BLACK%^The sand here is a mixture of grit and sand, making it far more coarse then the sandy beach one might find near more civilized places.  Spotted here and there by rocks or seashells that have washed up on shore.%^RESET%^",
	({ "inlet", "stream" }) : "%^BLUE%^A narrow stream makes its way out of the forest and down to the ocean.  Wide enough to navigate a small boat up, the stream turns a bit muddy where it meets the ocean.%^RESET%^",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/lurue/uzodo_d1",
	]));

}