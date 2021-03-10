// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("attaya_12");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("garden");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^GREEN%^Center of the City of Seneca%^RESET%^");

    set_long("%^RESET%^%^GREEN%^This garden looks like it might once have been a city park, but it has been overrun with wild growing %^BOLD%^flytraps %^RESET%^%^GREEN%^that cover the lush grounds and have all but "
	"stifled out the %^RED%^hibiscus %^GREEN%^plants that were once the landscape's border.  %^RESET%^Stone benches %^GREEN%^ring a small courtyard and hold this wilderness back.  In the center a highly de"
	"tailed %^BOLD%^%^WHITE%^statue %^RESET%^%^GREEN%^can be seen standing above a algae covered %^CYAN%^pond%^GREEN%^.%^RESET%^"
	);

    set_smell("default","
The clean scent of the ocean rises on the breeze.");
    set_listen("default","You can faintly hear the crashing of waves on the shore.");

    
set_items(([ 
	({ "pond", "algae" }) : "%^RESET%^%^CYAN%^The pond is thick with %^GREEN%^algae %^CYAN%^and nearly try, but it was likely at one time a beautiful reflecting pool.%^RESET%^",
	({ "benches", "bench" }) : "%^BOLD%^%^BLACK%^ Several stone benches have been placed around the garden, the tall flowers between them creating the illusion of separate alcoves.  Each bench is made from a slate top supported by columns of slate pieces arranged like bricks.%^RESET%^",
	({ "flowers", "hibiscus", "flower" }) : "%^RESET%^%^GREEN%^ The leafy hibiscus plants each sprout six-inch blossoms of five rounded petals.  Huge and beautiful, the blossoms range in a variety of colors from the lightest pinks to the darkest maroons.%^RESET%^",
	({ "flytraps", "flytrap" }) : "%^RESET%^%^GREEN%^Most unusual flowers, each of the Attaya flytraps looks much like a tall stalk supporting several clam-shaped 'blossoms'.  Each blossom is lined with long, thin filaments that have the appearance of needle-like teeth.  The inner portion of each blossom is colored %^RED%^red%^GREEN%^, making the flowers look like nothing so much as gaping maws.%^RESET%^",
	"statue" : "%^BOLD%^%^WHITE%^Captured mid-whirl, this kilted warrior is a force to be reckoned with.  He holds twin scimitars, his left hand curved over his head while his right whips around in front of his waist.  Cleverly designed to be in mid-leap, only the toes of one sandaled foot touch the statue's base, while the other is kicked up behind him, flaring the pleated kilt he wears to his knees.  His mouth is open in a battle shout, visible beneath his blazing eyes - the only facial features to be seen through the T-shaped openings in his helmet.  A crest of horse hair bristles from the top, the tail whipping around with the warrior's motion.  Like the other statues in the city gardens, this one is likewise defaced.  The front of his chest once held a chestguard of some sort, but it has been removed.%^RESET%^",
	]));

    set_exits(([ 
		"northwest" : "/d/av_rooms/lurue/attaya_10",
	]));

}