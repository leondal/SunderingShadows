// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("sunetemple_02");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("garden");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^Dryad's Garden%^RESET%^");

    set_long("%^GREEN%^Flourishing here is a young %^BOLD%^%^RED%^rosetree %^RESET%^%^GREEN%^ripe with richly scented blooms.  The %^ORANGE%^trunk %^GREEN%^is slender and straight dividing near the top into three b"
	"ranches which curve outward and vanish into the leafy, %^BOLD%^emerald %^RESET%^%^GREEN%^dome.  Brilliant, %^BOLD%^%^RED%^crimson roses %^RESET%^%^GREEN%^crown the canopy, bursting forth with their %^"
	"RED%^ruby petals %^GREEN%^in a glorious display of sensual perfection.  Surrounding the garden is a palisade created of statuesque columns and %^BOLD%^%^WHITE%^white marble %^RESET%^%^GREEN%^walls bro"
	"ken only by the billowing waves of an occasional silk curtain.  A sloping %^BOLD%^%^WHITE%^white gravel %^RESET%^%^GREEN%^walkway makes its way from one of these billowing decorations of diaphanous si"
	"lk.  Winding across a %^BOLD%^deep green lawn %^RESET%^%^GREEN%^decorated with %^CYAN%^myrtle-leaf topiaries %^GREEN%^tenderly shaped into the form of small %^ORANGE%^animals%^GREEN%^.  These life-lik"
	"e creatures appear to be caught mid-caper as they play about the young %^BOLD%^%^RED%^rosetree %^RESET%^%^GREEN%^or romp their way down toward the central %^BOLD%^%^BLUE%^pool %^RESET%^%^GREEN%^that g"
	"limmers in the light.  Only upon closer inspection do you realize that some of these small %^ORANGE%^animals %^RESET%^%^GREEN%^are not topiaries at all.%^RESET%^"
	);

    set_smell("default","
The delightful scent of roses fills your senses.");
    set_listen("default","The delicate, joyous laugher of a woman catches your attention.");


    set_exits(([ 
		"northeast" : "/d/av_rooms/lurue/sunetemple_01",
		"south" : "/d/av_rooms/lurue/sunetemple_06",
		"northwest" : "/d/av_rooms/lurue/sunetemple_03",
	]));

}