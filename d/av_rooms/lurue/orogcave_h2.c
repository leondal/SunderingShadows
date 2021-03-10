// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("orogcave_h2");
    set_property("indoors",1);
    set_property("light",-2);
    set_property("no teleport",1);
    set_terrain("built cave");
    set_travel("slick floor");
    set_climate("mountain");

    set_short("%^RESET%^%^BLUE%^a %^BOLD%^%^BLACK%^gr%^BLUE%^a%^BLACK%^n%^RESET%^i%^BOLD%^%^BLACK%^te%^RESET%^%^BLUE%^ cave%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This tunnel is tall and wide, hollowed out from the granite stone of the mountain.  Smoothed walls show no sign of tool mark, though there are a few places where long %^RESET%^scratch"
	"es %^BOLD%^%^BLACK%^can be seen about shoulder height on an Orog.  The passage rises upward at a slow incline curving around to the northwest as it does, while an %^RESET%^%^BLUE%^alcove %^BOLD%^%^BLA"
	"CK%^of some sort appears to be off to the southwest.%^RESET%^"
	);

    set_smell("default","
The deep scent of earth, metal and bodies permeates the air.");
    set_listen("default","The sounds of Orog can be heard echoing through the halls.");


    set_exits(([ 
		"northeast" : "/d/av_rooms/lurue/orogcave_h1",
		"southwest" : "/d/av_rooms/lurue/orogcave_r7",
		"northwest" : "/d/av_rooms/lurue/orogcave_h3",
	]));

}