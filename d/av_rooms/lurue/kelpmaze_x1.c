// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("kelpmaze_x1");
    set_property("indoors",0);
    set_property("light",-2);
    set_property("no teleport",1);
    set_terrain("deep water");
    set_travel("fresh blaze");
    set_climate("temperate");

    set_short("%^BOLD%^%^GREEN%^A vast kelp forest%^RESET%^");

    set_long("%^RESET%^%^CYAN%^Growing over a hundred feet in length, the kelp finds itself rooted amongst the remains of an ancient %^GREEN%^hedge garden%^CYAN%^.  Holdfasts, the roots of these mighty plants, clin"
	"g to the stone walls that once created the structure of the maze, while the thick stipes, supported by gas filled floats, rise swiftly up in a swaying grove of slowly moving %^GREEN%^green%^CYAN%^, %^"
	"ORANGE%^orange %^CYAN%^and %^BOLD%^%^BLACK%^gray %^RESET%^%^CYAN%^fronds.  Sea creatures of every size and shape can be seen moving throughout this vast forest, swimming, hiding and living their lives"
	" in the %^BLUE%^deep waters%^CYAN%^, protected by the thick kelp bed and fed by the nutrients that spill from these plants and cloud the water into a murky haze.%^RESET%^"
	);

    set_smell("default","
The water has a mild gritty taste.");
    set_listen("default","You hear the sound of water moving through the kelp.");

    set_search("holdfast","%^RESET%^%^ORANGE%^You give the root like bundle of the holdfast a good hardy shake and watch as tiny crabs, small silver fish and a host of other little animals all scamper out onto the soil in fear.  You're so mean!%^RESET%^");
    set_search("kelp","%^BOLD%^%^GREEN%^You search through the kelp, but find nothing you want to take with you.%^RESET%^");
    
set_items(([ 
	({ "fish", "creatures" }) : "%^BOLD%^%^WHITE%^Living within the vast forest of kelp is a whole ecosystem of living creatures.  Silvery fish, tiny crustaceans and a host of other beings like star fish, octopus, jellyfish and sea anemones.%^RESET%^",
	({ "water", "grit", "cloud" }) : "%^RESET%^%^CYAN%^The water is filled with a fine cloud of floating debris, cast off from the kelp and small creatures that call the kelp bed their home, as well as sand and grit from the bottom, stirred up by your passing.%^RESET%^",
	({ "kelp", "forest", "kelp forest" }) : "%^RESET%^%^GREEN%^The kelp forest is vast and grows thickly here where the old maze garden provides a foundation for the root like holdfasts to cling.  Stalks as thick as a man's body can be seen growing upward for over a hundred feet toward the surface, lined with leafy fronds and studded with the air filled floats that give it buoyancy.",
	({ "holdfast", "holdfasts", "roots" }) : "%^RESET%^%^ORANGE%^You look closely at the root ball shaped growths that anchor these vast underwater trees and see their main purpose is to cling to unground structures and provide an anchor against the ever shifting currents.%^RESET%^",
	({ "float", "floats", "frond", "fronds", "leaves", "leaf" }) : "%^RESET%^%^GREEN%^Extending from the stripe, these fronds have two parts to them.  The first, located close to the stock, is a bulb of trapped air like gas that gives the plant buoyancy.  The second part is a blade of kelp that can grow several feet long and extends out like leaves upon a tree, floating and waving in the water.%^RESET%^",
	]));
}