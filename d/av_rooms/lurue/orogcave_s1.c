// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("orogcave_s1");
    set_property("indoors",1);
    set_property("light",-2);
    set_property("no teleport",1);
    set_terrain("built cave");
    set_travel("slick floor");
    set_climate("mountain");

    set_short("%^RESET%^%^BLUE%^a %^BOLD%^%^BLACK%^gr%^BLUE%^a%^BLACK%^n%^RESET%^i%^BOLD%^%^BLACK%^te%^RESET%^%^BLUE%^ cave%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^Sectioned off behind a tall wooden structure, this portion of the cavern is where the Orog keep their %^RESET%^%^ORANGE%^engines of war%^BOLD%^%^BLACK%^.  Lined up an orderly manner, "
	"the pair of hide covered %^RESET%^%^ORANGE%^wooden devices%^BOLD%^%^BLACK%^ are arranged in such a way that they could easily be moved out of the cavern at a moment's notice.  A few other items are st"
	"aged here as well.  Large %^RESET%^%^BLUE%^metal pots %^BOLD%^%^BLACK%^for boiling tar or pitch, %^RESET%^%^ORANGE%^wooden ladders %^BOLD%^%^BLACK%^for scaling walls and a number of other smaller tool"
	"s, all stockpiled and ready to go.%^RESET%^"
	);

    set_smell("default","
The deep scent of earth, metal and bodies permeates the air.");
    set_listen("default","The sounds of Orog can be heard echoing through the halls.");


    set_exits(([ 
		"east" : "/d/av_rooms/lurue/orogcave_h1",
	]));

}