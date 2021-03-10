// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("asylum1");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^A hallway in the %^WHITE%^Asylum%^RESET%^");

    set_long("You stand in a hallway in the %^RESET%^%^CYAN%^asylum%^RESET%^. It is made of solid stone. Dim light casts shadows. There is some misery that weighs on your soul in this place. %^RED%^Locked doors%^RE"
	"SET%^ line the hall."
	);

    set_smell("default","
You smell urine and mildew.");
    set_listen("default","There are screams, cries, and inconsolate sobbing. This place could %^BOLD%^%^RED%^drive you %^MAGENTA%^m%^RESET%^%^MAGENTA%^a%^BOLD%^d%^RESET%^.");


    set_exits(([ 
		"south" : "/d/av_rooms/myrkul/asylum2",
		"east" : "/d/tharis/newtharis/rooms/san1",
	]));

}