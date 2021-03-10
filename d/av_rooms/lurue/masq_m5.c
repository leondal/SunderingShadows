// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit ROOM;

void create()
{
    ::create();
    set_name("masq_m5");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("garden");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^RESET%^%^MAGENTA%^Land of %^RESET%^Mist %^MAGENTA%^and %^BOLD%^%^CYAN%^Dreams%^RESET%^");

    set_long("%^RESET%^%^GREEN%^A small, %^RESET%^mist shrouded %^GREEN%^garden complete with a twisting %^BOLD%^hedge maze %^RESET%^%^GREEN%^that vanishes off into the twilight %^RESET%^mist%^GREEN%^.  Here, a %^B"
	"OLD%^%^WHITE%^marble fountain %^RESET%^%^GREEN%^burbles quietly as water spills over four ever-expanding tiers before falling into the basin at the bottom.  Tiny flickering %^MAGENTA%^l%^BOLD%^i%^WHIT"
	"E%^g%^RESET%^%^MAGENTA%^h%^BOLD%^%^BLACK%^t%^RESET%^%^MAGENTA%^s %^GREEN%^dart in and out throughout the water, though their source is impossible to make out.  A few %^RESET%^marble benches %^GREEN%^a"
	"re arranged around the fountain, offering places to sit and rest outside, taking in the perpetual night time.%^RESET%^"
	);

    set_smell("default","
A rich, earthy, damp scent fills the air.");
    set_listen("default","The sound of laughter drifts through the open glass doors of the ballroom.");

    
set_items(([ 
	({ "fountain", "marble fountain", "water" }) : "%^BOLD%^%^WHITE%^Made of white marble shot through with veins of gold and quartz, this lovely fountain has several tiers that catch the water that spills downward and into a wide blue tile basin.  The faint burble of water is deafened a bit by the sounds coming through the open glass doors of the ballroom.%^RESET%^",
	({ "maze", "hedges", "hedge maze" }) : "%^BOLD%^%^GREEN%^The maze seems to stretch out and around the building, leading into any number of hidden pathways.  Who knows what lurks deep within that strange grove of ancient hedges.  Maybe its better if you don't go looking.%^RESET%^",
	({ "moon", "stars", "sky", "moons", "star" }) : "%^BOLD%^%^BLUE%^A moon shines pale overhead.  Full and yellowish, it gleams with a waxy pallor that isn't completely healthy.  The stars beyond blaze in the not quite dark sky which seems perpetually caught in the last moments of twilight.%^RESET%^",
	({ "mist", "twilight" }) : "%^RESET%^%^BLUE%^Despite the time of day you believe it is, here the world seems cast in perpetual twilight.  A soft %^RESET%^mist%^BLUE%^ settles about the garden bathed in the last faint light of day.  High above the moon and stars shine though the sky is not yet truly dark.  Almost as if it clings to that moment before darkness settles in.%^RESET%^",
	({ "lights", "flickering lights", "light" }) : "%^RESET%^%^MAGENTA%^Dodging in and out of the water tiny little lights dart back and forth.  Looking random, you realize that these are tiny little fey creatures whose wings glow as they flap.  Every now and again, one of the little creatures will alight upon the marble of the fountain and you catch a glimpse of a feline like features.%^RESET%^",
	({ "benches", "bench" }) : "%^BOLD%^%^WHITE%^Made of marble, these white stone benches are probably not very comfortable, yet they are set about the fountain to allow someone to pause and enjoy the fountain's music, or take in the last bit of twilight, should they wish to.%^RESET%^",
	({ "doors", "glass doors" }) : "%^BOLD%^%^CYAN%^Made of glass, these doors stand open allow guests to come and go as they wish, traversing between the garden and the ballroom easily.%^RESET%^",
	({ "castle", "building", "estate", "palace" }) : "%^BOLD%^%^WHITE%^A majestic castle stands before you, shrouded in mist to the point where seeing details is difficult, almost as if the whole thing wasn't quite there.  Stone walls sweep upward several stories and the building seems impossibly large, yet every time you try to focus on it, things seem to blur and you can't quite make out the details you expected.  Only the glass doors that lead back into the ballroom seem solid.%^RESET%^",
	]));

    set_exits(([ 
		"ballroom" : "/d/av_rooms/lurue/masq_m2",
	]));

}