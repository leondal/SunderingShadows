// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("teel7");
    set_property("indoors",0);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("city");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^CYAN%^Teel Street%^RESET%^");

    set_long("%^CYAN%^Teel Street %^MAGENTA%^continues running north and south.  Here %^CYAN%^Teel %^MAGENTA%^meets up with %^CYAN%^Morel, %^MAGENTA%^a bustling %^BOLD%^%^BLACK%^nightmare %^RESET%^%^MAGENTA%^of act"
	"ivity.  The %^RED%^c%^RESET%^o%^RED%^bbl%^RESET%^e%^RED%^st%^RESET%^o%^RED%^n%^RESET%^e %^MAGENTA%^merges seamlessly to the east.  Further to the east, a large structure stands out above all the rest."
	"  The %^BOLD%^%^YELLOW%^castle %^RESET%^%^MAGENTA%^of %^BOLD%^%^YELLOW%^Lady Genavive%^RESET%^%^MAGENTA%^.%^RESET%^ "
	);

    set_smell("default","
%^CYAN%^The smells of the inn flow in from the south.%^RESET%^");
    set_listen("default","%^BOLD%^%^YELLOW%^Conversations and chirps of laughter come from every direction.%^RESET%^");


    set_exits(([ 
		"south" : "/d/av_rooms/mystra/teel6",
		"north" : "/d/av_rooms/mystra/teel8",
		"east" : "/d/av_rooms/mystra/morel1",
	]));

}