// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("sunetemple_11");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^Heart's Chamber%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^This small, oval shaped chamber rests hidden within the base of %^RED%^Sune's%^WHITE%^ state.  Though it is under water, %^CYAN%^magic %^WHITE%^prevents the pool's water from entering"
	", just as it keeps the air fresh and comfortably warm.  Surprisingly simple in design, the chamber is constructed out of  white marble veined through with thin tendrils of %^YELLOW%^gold %^WHITE%^and "
	"%^MAGENTA%^rose %^WHITE%^quartz.  A faint light infuses the walls and provides enough light to see by, but it is the sense of unconditional, welcoming %^RED%^love %^WHITE%^infusing the chamber which m"
	"akes it so serene and perfect for deeper meditation.%^RESET%^"
	);

    set_smell("default","
No scents permeate the simple chamber.");
    set_listen("default","No sounds reach the sanctum of this room.");


    set_exits(([ 
		"out" : "/d/av_rooms/lurue/sunetemple_05",
	]));

}