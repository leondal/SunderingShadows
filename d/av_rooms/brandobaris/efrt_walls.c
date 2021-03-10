// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("efrt_walls");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("stairway");
    set_climate("temperate");

    set_short("%^ORANGE%^atop the %^BOLD%^courtyard %^RESET%^%^ORANGE%^walls%^WHITE%^");

    set_long("%^BOLD%^Atop the %^RESET%^high white walls %^BOLD%^of the fortress, you can see almost entirely unimpeded in any direction, offering a clear view of both the surrounding %^GREEN%^landscape %^WHITE%^an"
	"d of the %^RESET%^%^ORANGE%^courtyard %^BOLD%^%^WHITE%^below. This particular segment of wall stretches around the entirety of the courtyard, presumably offering a useful vantage point should any inva"
	"ders manage to breach the %^BLACK%^front gates%^WHITE%^. The walls are wide enough to walk comfortably upon, nearly twenty feet thick, but there does not look to be much of note up here, otherwise.%^R"
	"ESET%^"
	);

    set_smell("default","
The air here is clean.");
    set_listen("default","Wind whistles past you, this high up, and you can hear the noise of the courtyard's fountain below.");


    set_exits(([ 
		"down" : "/d/av_rooms/brandobaris/efrt_courtyard",
	]));

}