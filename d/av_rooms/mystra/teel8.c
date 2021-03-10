// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("teel8");
    set_property("indoors",0);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("city");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^CYAN%^Teel Street%^RESET%^");

    set_long("%^MAGENTA%^You have reached the end of %^CYAN%^Teel Street %^MAGENTA%^just passed where it intersects with %^CYAN%^Morel%^MAGENTA%^.  This end of the road is less used as it dead ends.  A boarded up b"
	"uilding sits to the north and is one of the few things you've seen in this town to be in disrepair.%^RESET%^"
	);

    set_smell("default","
%^CYAN%^The smells of the inn flow in from the south.%^RESET%^");
    set_listen("default","%^BOLD%^%^YELLOW%^Conversations and chirps of laughter come from every direction.%^RESET%^");


    set_exits(([ 
		"south" : "/d/av_rooms/mystra/teel7",
	]));

}