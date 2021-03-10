// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("selune_meadow");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("meadows");
    set_travel("game track");
    set_climate("temperate");

    set_short("%^BOLD%^%^GREEN%^An enclosed meadow%^RESET%^");

    set_long("%^RESET%^%^GREEN%^Long shadows stretch over the lush, %^BOLD%^dark green grass%^RESET%^%^GREEN%^ that grows in this small meadow.  Pines, spruce and alder rise high into the air, encircling the glade "
	"and preventing a view of the world beyond.  Thick clumps of %^MAGENTA%^berry bushes %^GREEN%^edge the grass line and vanish back into the trees, while spots of colored %^YELLOW%^wild flowers %^RESET%^"
	"%^GREEN%^dance lightly upon the breeze over the grass.  Above, the sky is clear and glossy with not a cloud in sight to obscure the dark, star studded expanse of the heavens.  In the center, so close "
	"it seems you could almost touch it, is the silver fullness of the %^WHITE%^%^BOLD%^moon%^RESET%^%^GREEN%^.%^RESET%^"
	);

    set_smell("default","The air is fresh and pure, lightly scented with the sweet scent of wild flowers.");
    set_listen("default","The call of night birds and the chirp of crickets reach your ears.");

    
set_items(([ 
	({ "moon", "sky", "heavens" }) : "%^BOLD%^%^WHITE%^The moon is full and beautiful, and with the air so clear it seems you could almost reach up and touch the silvery depths that hang in a brilliantly intense star blazed sky.%^RESET%^",
	({ "bushes", "berries" }) : "%^RESET%^%^MAGENTA%^Lining the meadow are clumps of berry bushes ripe with small %^RED%^red%^MAGENTA%^ fruits.%^RESET%^",
	({ "birds", "crickets" }) : "%^BOLD%^%^GREEN%^You can't see them, but you can hear them as they chirp and trill within the forest.%^RESET%^",
	({ "wild flowers", "flowers", "grass", "meadow" }) : "%^GREEN%^The meadow is small and contained, filled with a lush dark green grass that looks soft enough to lay down in and idle away your worries.  Here and there, little spots of %^MAGENTA%^wild flowers %^GREEN%^wave in the soft breeze the stirs the grass.%^RESET%^",
	]));

    set_exits(([ 
		"trees" : "/d/magic/temples/selune",
	]));

}