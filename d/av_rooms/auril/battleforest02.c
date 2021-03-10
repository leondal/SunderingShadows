// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("battleforest01");
    set_property("indoors",0);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("heavy forest");
    set_travel("ledge");
    set_climate("temperate");

    set_short("%^BOLD%^%^GREEN%^Within a forest%^RESET%^");

    set_long("%^BOLD%^%^GREEN%^You stand within the tall trees of %^BOLD%^%^YELLOW%^Tharis %^RESET%^%^GREEN%^Forest %^BOLD%^%^GREEN%^. The sky is mostly blocked by the expansive limbs of the trees above. The ground is covered by a thin %^RESET%^%^GREEN%^underbrush %^BOLD%^%^GREEN%^. The dark bark of the trees accents against the lushness of the environment around. Though beautiful,something about this place seems out of place, as if nature herself knows something horrible is about to take place.%^RESET%^"
	);

    set_smell("default","
%^BOLD%^%^GREEN%^You smell the leaves and sap of the forest.%^RESET%^");
    set_listen("default","%^BOLD%^%^BLUE%^You hear birds chirping.%^RESET%^");


    set_exits(([ 
		"east" : "/d/av_rooms/auril/battleforest03",
		"south" : "/d/av_rooms/auril/battleforest07",
		"west"	: "/d/av_rooms/auril/battleforest01",
	]));

}