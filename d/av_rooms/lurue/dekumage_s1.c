// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_s1");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("rutted track");
    set_climate("tropical");

    set_short("%^BOLD%^%^BLACK%^A carriage house%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^Once, grand carriages must have driven here from %^YELLOW%^Verbobone %^RESET%^%^ORANGE%^to attend stately parties and functions.  Now the grand dome has cracked and crumbled, giving"
	" way to the %^BOLD%^%^CYAN%^sky %^RESET%^%^ORANGE%^above and the limbs of the heavy %^BOLD%^%^GREEN%^cypress trees%^RESET%^%^ORANGE%^.  The carriage stand still looks sturdy though and judging by the "
	"fresh looking %^BOLD%^%^BLACK%^tack %^RESET%^%^ORANGE%^on the wall hooks, someone still uses this place for their mounts.  A small portion of this area has been penned off and made into a shelter for "
	"a pair of %^MAGENTA%^%^BOLD%^sows %^RESET%^%^ORANGE%^who watch mutely as you pass. %^RESET%^"
	);

    set_smell("default","
The heavy smell of rotten vegetation hangs in the air.");
    set_listen("default","You hear the melody of someone whistling nearby.");

    
set_items(([ 
	({ "stand", "carriage stand" }) : "%^RESET%^%^ORANGE%^This stand is made from a ornately carved square of oak wood.  Designed with two steps so that a lady would be as comfortable as a mount climbing them, they provide a means of making oneself level with the saddle of a horse, rather then having to jump up by use of the stirrups.%^RESET%^",
	({ "bow", "arrows", "sheath" }) : "%^BOLD%^%^BLACK%^You look closer at the sheath and see that it's designed for fitting on a riding saddle.  Most likely for when out hunting to keep the bow out of the way or the arrows handy.%^RESET%^",
	({ "pigs", "pig", "sow", "sows" }) : "%^BOLD%^%^MAGENTA%^The pigs rut about in their pen searching for something to eat amongst the muck.%^RESET%^",
	"tack" : "%^BOLD%^%^BLACK%^The tack looks fresh and well tended, making you think someone must live here and ride often.  There is a bit and bridle, as well as a saddle and pair of saddle bags.  You also notice a sheath for holding a bow and arrows.%^RESET%^",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/lurue/dekumage_s2",
		"east" : "/d/av_rooms/lurue/dekumage_g4",
		"northwest" : "/d/av_rooms/lurue/dekumage_s3",
	]));

}