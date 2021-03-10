// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("placeholder");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("marsh");
    set_travel("foot path");
    set_climate("mountain");

    set_short("A Quiet Area");

    set_long("The tunnel opens into the bottom of a narrow ravine, with icy cliffs ranging above you.  A deathly quiet hangs in the air.  It appears that this small protected area was once populated, but there are "
	"no signs of life.  Tents and humble stone dwellings have collapsed or otherwise fallen into disrepair.  Large fire pits are empty of flame or warmth.  Strangely, there are no bodily remains in sight. "
	" Every fiber of you suggests that the answers lie up a steep trail, leading towards an aged keep."
	);

    set_smell("default","
%^ORANGE%^It smells like sickness or decay.");
    set_listen("default","%^GREEN%^You hear little.%^RESET%^");


    set_exits(([ 
		"tunnel" : "/d/shadow/virtual/sea/winter.dock",
		"keep" : "/d/av_rooms/tiamat/castle1",
	]));

}