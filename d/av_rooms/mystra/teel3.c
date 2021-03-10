// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("teel3");
    set_property("indoors",0);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("city");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^CYAN%^Teel Street%^RESET%^");

    set_long("%^MAGENTA%^A heavier flow of traffic meanders along this portion of %^CYAN%^Teel%^MAGENTA%^.  Horse drawn carts and pedestrians alike seem to swarm the area with some heading north into the city and o"
	"thers traveling south to make their exit through the gates.  The smell of food is stronger here.  %^RED%^Meats %^MAGENTA%^and %^ORANGE%^stews %^MAGENTA%^permeate the air with a frenzy.  A %^WHITE%^whi"
	"te door %^MAGENTA%^to the west cannot impede the pleasant odors progress into the streets.  The sound of conversations and laughter can also be heard within.%^RESET%^"
	);

    set_smell("default","
%^CYAN%^The smells of the inn linger into the streets here%^RESET%^");
    set_listen("default","%^BOLD%^%^YELLOW%^Conversations and chirps of laughter come from every direction.%^RESET%^");


    set_exits(([ 
		"north" : "/d/av_rooms/mystra/teel4",
		"south" : "/d/av_rooms/mystra/teel2",
		"west" : "/d/av_rooms/mystra/inn1",
	]));

}