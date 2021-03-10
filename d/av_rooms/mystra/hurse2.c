// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("hurse2");
    set_property("indoors",0);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("city");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^BLACK%^%^BOLD%^Hurse Lane%^RESET%^");

    set_long("%^WHITE%^Hurse Lane %^MAGENTA%^turns back towards the north.  To the east, a large %^BOLD%^%^WHITE%^palace %^RESET%^%^MAGENTA%^gleams atop a rolling %^BOLD%^%^GREEN%^meadow%^RESET%^%^MAGENTA%^, lookin"
	"g down upon the city.  A bit further to the north, another large structure can be seen though you can't quite make out the details of it yet.  As you move deeper into the city, traffic thins out but b"
	"usiness does continue.  A few %^BOLD%^%^BLACK%^city guards %^RESET%^%^MAGENTA%^can be seen patrolling among the locals, keeping order to the apparant chaos.%^RESET%^"
	);

    set_smell("default","
%^CYAN%^The sweat of travelers brings tears to your eyes%^RESET%^");
    set_listen("default","%^BOLD%^%^YELLOW%^Hammering from the south drowns out some of the voices%^RESET%^");


    set_exits(([ 
		"south" : "/d/av_rooms/mystra/hurse1",
		"north" : "/d/av_rooms/mystra/hurse3",
	]));

}