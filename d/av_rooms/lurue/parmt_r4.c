// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("parmt_r4");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("rocky");
    set_travel("game track");
    set_climate("mountain");

    set_short("%^BOLD%^%^CYAN%^Middle of the River%^RESET%^");

    set_long("%^BOLD%^%^BLUE%^You wade out into the stream, finding your way as much by feel as by sight.  Your feet slip over %^BLACK%^boulders %^BLUE%^and %^RESET%^stones%^BOLD%^%^BLUE%^, occasionally catching in"
	" submerged %^RESET%^%^ORANGE%^branches%^BOLD%^%^BLUE%^.  Small fish dart past tickling your legs at times, their %^WHITE%^silvery scales%^BLUE%^ flashing briefly under the water.  Thankfully the water"
	" never grows deeper then about waist height on a human, and this is only toward the center where the current is faster.  The majority of the river thins out to only a foot or so deep.%^RESET%^"
	);

    set_smell("default","
The mountain air is fresh and clean, and scented with the smell of damp earth.");
    set_listen("default","The sound of the river burbling over rocks and boulders fills the air.");

    
set_items(([ 
	({ "water", "current" }) : "%^BOLD%^%^BLUE%^The water is only fast moving toward the center of the river, but even there, someone with a bit of determination could likely cross if they took care.%^RESET%^",
	({ "bank", "shore", "river bank" }) : "%^RESET%^%^ORANGE%^The river bank is very narrow and appears to have at once been under the river.  Likely during spring melt the river overflows its usual boundaries and scars this part of the land, leaving a narrow trail to follow.  Small, well worn %^RESET%^rocks%^ORANGE%^, scraggly %^GREEN%^grass %^ORANGE%^and various %^BLACK%^%^BOLD%^twigs %^RESET%^%^ORANGE%^and roots line the narrow bank, making a difficult path to follow.%^RESET%^",
	({ "mountains", "mountain" }) : "%^BOLD%^%^BLACK%^Further to the north you can see a tall, %^WHITE%^snow capped %^BLACK%^mountain range which is likely the source of water for this river.  Dark granite stone crags jut upward, offering a stunning display against the deep blues and cloud grays of the sky.%^RESET%^",
	({ "tree", "tree limb", "limb", "rocks", "rock", "boulder", "boulders" }) : "%^RESET%^Many small boulders and rocks can be seen below the surface of the river's water.  Even a few tree limbs that have bloated and sunk.  Though several of the rocks have muted color to them, the majority look to be the %^BOLD%^%^BLACK%^dark gray stone %^RESET%^of the granite mountains to the north.%^RESET%^",
	({ "river", "water" }) : "%^RESET%^%^CYAN%^The river here is wide and gentle, though you can see in the center there is a faster current.  Below the surface, %^RESET%^rocks%^CYAN%^, %^BOLD%^%^BLACK%^boulders %^RESET%^%^CYAN%^and an occasional %^ORANGE%^tree limb can %^CYAN%^be seen, causing the water to froth and ripple as it travels down into the Parnelli Valley.%^RESET%^",
	({ "forest", "valley", "city" }) : "%^GREEN%^Further to the south, the magical Parnelli Forest opens up into a wide and beautiful valley that is home to many strange and beautiful creatures.  In the center of the valley, the city of Asgard can be made out, its high turrets and lofty towers an epic tribute to man's ability.%^RESET%^",
	"fish" : "%^BOLD%^%^WHITE%^You only see the occasional flash of them under the water.  But you can feel them now and again swimming past you.%^RESET%^",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/lurue/parmt_r3",
		"east" : "/d/av_rooms/lurue/parmt_r5",
	]));

}