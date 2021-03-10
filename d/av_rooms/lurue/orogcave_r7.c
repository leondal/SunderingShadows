// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("orogcave_r7");
    set_property("indoors",1);
    set_property("light",-2);
    set_property("no teleport",1);
    set_terrain("built cave");
    set_travel("slick floor");
    set_climate("mountain");

    set_short("%^RESET%^%^BLUE%^a %^BOLD%^%^BLACK%^gr%^BLUE%^a%^BLACK%^n%^RESET%^i%^BOLD%^%^BLACK%^te%^RESET%^%^BLUE%^ cave%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This large chamber is little more then a %^RESET%^%^ORANGE%^dirt lined hovel %^BOLD%^%^BLACK%^with several pallets set out in small clusters.  Scraps of fabric and a few small belongi"
	"ngs linger close to these pallets of %^RESET%^%^CYAN%^woven grass %^BOLD%^%^BLACK%^and matted %^RESET%^%^GREEN%^fern leaves%^BOLD%^%^BLACK%^, but nothing of value that you can see.  Clearly the chambe"
	"r for the Orog's slaves, the entryway features a large set of bars that can be drawn down from the ceiling by the use of a lever, and a locking mechanism ensures that the slaves cannot open it till th"
	"eir masters release it in the morning.%^RESET%^"
	);

    set_smell("default","
The deep scent of earth, metal and bodies permeates the air.");
    set_listen("default","The sounds of Orog can be heard echoing through the halls.");


    set_exits(([ 
		"northeast" : "/d/av_rooms/lurue/orogcave_h2",
	]));

}