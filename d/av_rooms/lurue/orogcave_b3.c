// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("orogcave_b3");
    set_property("indoors",1);
    set_property("light",-2);
    set_property("no teleport",1);
    set_terrain("built cave");
    set_travel("slick floor");
    set_climate("mountain");

    set_short("%^RESET%^%^BLUE%^a %^BOLD%^%^BLACK%^gr%^BLUE%^a%^BLACK%^n%^RESET%^i%^BOLD%^%^BLACK%^te%^RESET%^%^BLUE%^ cave%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^Located partway up the dark stone gr%^BLUE%^a%^BOLD%^%^BLACK%^n%^RESET%^i%^BOLD%^%^BLACK%^te cliff, this crag is not large enough to be a proper cave, but it could serve well as a loo"
	"k out point or a %^RESET%^%^RED%^murder hole%^BOLD%^%^BLACK%^.  The narrow slash into the stone wall is only a short way up the cliff side, but it gives a good view of the entry to the cave below.  Fr"
	"om here, one could easily drop %^RESET%^heavy stones %^BOLD%^%^BLACK%^or %^RESET%^%^CYAN%^boiling liquids %^BOLD%^%^BLACK%^down upon invader's heads.   One might even be able to %^RESET%^%^RED%^jump %"
	"^BOLD%^%^BLACK%^from here, though without practice the landing might hurt considerably.%^RESET%^"
	);

    set_smell("default","
The deep scent of earth, metal and bodies permeates the air.");
    set_listen("default","The sounds of Orog can be heard echoing through the halls.");


    set_exits(([ 
		"southwest" : "/d/av_rooms/lurue/orogcave_h4",
	]));

}