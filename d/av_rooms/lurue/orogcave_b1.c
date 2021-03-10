// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("orogcave_b1");
    set_property("indoors",1);
    set_property("light",-2);
    set_property("no teleport",1);
    set_terrain("built cave");
    set_travel("slick floor");
    set_climate("mountain");

    set_short("%^RESET%^%^BLUE%^a %^BOLD%^%^BLACK%^gr%^BLUE%^a%^BLACK%^n%^RESET%^i%^BOLD%^%^BLACK%^te%^RESET%^%^BLUE%^ cave%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^Located partway up the dark stone gr%^BLUE%^a%^BOLD%^%^BLACK%^n%^RESET%^i%^BOLD%^%^BLACK%^te cliff, this crag is not large enough to be a proper cave, but it could serve well as a loo"
	"k out point or a %^RESET%^%^RED%^murder hole%^BOLD%^%^BLACK%^.  The narrow slash into the stone wall is near the top of the cliff, and gives a good view of the surrounding forest and pathway leading u"
	"p toward the entrance.  From here, one could use bows to attack those approaching.  For certain, the spot is perfect for watching a %^RESET%^%^RED%^battle %^BOLD%^%^BLACK%^happening below and being ab"
	"le to see all the forces that might be amassed.   One might even be able to %^RESET%^%^RED%^jump %^BOLD%^%^BLACK%^from here, though without practice the landing might hurt considerably.  Unlike the ot"
	"her balconies, this one even has a chair and %^YELLOW%^spyglass %^BOLD%^%^BLACK%^set up for viewing the on-goings below.%^RESET%^"
	);

    set_smell("default","
The deep scent of earth, metal and bodies permeates the air.");
    set_listen("default","The sounds of Orog can be heard echoing through the halls.");


    set_exits(([ 
		"west" : "/d/av_rooms/lurue/orogcave_r8",
	]));

}