// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("teel4");
    set_property("indoors",0);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("city");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^CYAN%^Teel Street%^RESET%^");

    set_long("%^CYAN%^Teel Street %^MAGENTA%^continues running north and south.  A master-masoned %^RED%^c%^RESET%^o%^RED%^bbl%^RESET%^e%^RED%^st%^RESET%^o%^RED%^n%^RESET%^e %^MAGENTA%^street lies in front of you. "
	" The stones laid and mortared have been sanded to a precise leveling.  On either side of the street, %^BOLD%^%^YELLOW%^shops %^RESET%^%^MAGENTA%^line up awaiting merchants and travelers alike to buy, "
	"sell, and trade their wares.%^RESET%^"
	);

    set_smell("default","
%^CYAN%^The smells of the inn flow in from the south.%^RESET%^");
    set_listen("default","%^BOLD%^%^YELLOW%^Conversations and chirps of laughter come from every direction.%^RESET%^");


    set_exits(([ 
		"south" : "/d/av_rooms/mystra/teel3",
		"north" : "/d/av_rooms/mystra/teel5",
	]));

}