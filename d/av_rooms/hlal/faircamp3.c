// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("faircamp3");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("foot path");
    set_climate("temperate");

    set_short("%^GREEN%^Inside a %^BOLD%^large %^RESET%^%^GREEN%^green caravan%^RESET%^");

    set_long("%^BOLD%^%^GREEN%^Probably the largest caravan in the entire camp, it looks as if it could easily support a family. There is very little privacy offered and much of the space is cluttered with costumes"
	", makeup,and other oddities that must have been picked up along the way. The loft extends from one end of the building to the other, seperated only by curtains, the only hint of privacy there is betwe"
	"en the comfortable bedding for four or more people.%^RESET%^"
	);

    set_smell("default","
%^MAGENTA%^A sweet perfume scents the air.");
    set_listen("default","%^BOLD%^%^MAGENTA%^A small music box plays a haunting song.");


    set_exits(([ 
		"out" : "/d/av_rooms/hlal/faircamp1",
	]));

}