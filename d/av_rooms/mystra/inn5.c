// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("inn5");
    set_property("indoors",1);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^Balcony of the Inn%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^The balcony on the second story overlooks the entry hall of the %^RESET%^%^CYAN%^Castwater Inn%^BOLD%^%^WHITE%^.  The hallway runs north and south of here leading to a single door on "
	"each end.  The long wall behind you holds several %^RESET%^%^MAGENTA%^paintings %^BOLD%^%^WHITE%^of various individuals whose blank expressions contradict the grandeur the inn attempts to resonate.%^R"
	"ESET%^"
	);

    set_smell("default","
%^CYAN%^The hallway smells fresh and clean%^RESET%^");
    set_listen("default","%^BOLD%^%^YELLOW%^It is quiet in this part of the inn%^RESET%^");


    set_exits(([ 
		"south" : "/d/av_rooms/mystra/inn7",
		"north" : "/d/av_rooms/mystra/inn6",
		"down" : "/d/av_rooms/mystra/inn4",
	]));

}