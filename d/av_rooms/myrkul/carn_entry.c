// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("carn_entry");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("village");
    set_travel("rutted track");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^Path to a %^YELLOW%^C%^RED%^a%^YELLOW%^r%^BLUE%^n%^CYAN%^i%^RED%^v%^YELLOW%^al%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^You find yourself on a %^RESET%^%^ORANGE%^dirt weather-beaten track%^BOLD%^%^WHITE%^ off the main road. The city of %^CYAN%^Tabor%^WHITE%^ lies to the south, and to the east lies a ca"
	"mp site. Down the road a ways you can see a bunch of %^MAGENTA%^brightly colored tents%^WHITE%^ and crowds of people -- a %^YELLOW%^C%^RED%^a%^YELLOW%^r%^BLUE%^n%^CYAN%^i%^RED%^v%^YELLOW%^al%^WHITE%^."
	" Garbage litters the side of the path as many revelers have left their food, bottles, and trinkets on the ground.%^RESET%^"
	);

    set_smell("default","
It smells like fried food, stale beer, and garbage.");
    set_listen("default","Crowds are roaring in the distance at the Carnival.");


    set_exits(([ 
		"northeast" : "/d/koenig/streams/camp1",
		"west" : "/d/av_rooms/myrkul/carn_main_e",
	]));

}