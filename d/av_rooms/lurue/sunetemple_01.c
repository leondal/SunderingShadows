// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("sunetemple_01");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("garden");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^Altar Garden%^RESET%^");

    set_long("%^RESET%^%^GREEN%^Stretching before you is the temple garden of %^BOLD%^%^RED%^Sune Firehair%^RESET%^%^GREEN%^.  Surrounded by a white marble palisade, a sprawling emerald lawn slopes downward to the "
	"deep blue waters of the central pool.  Trees and flowers dot the manicured landscape, while columns shaped in the forms of beautiful men and women of all races decorate the marble walls of the encircl"
	"ing structure.  Directly before the pool is an elaborate altar.  Made from pink marble, its surface has been delicately carved and inset with %^RED%^rubies%^GREEN%^, %^BOLD%^%^MAGENTA%^carnelians %^RE"
	"SET%^%^GREEN%^and %^BOLD%^%^RED%^fire opals%^RESET%^%^GREEN%^.  Centered on the altar and displayed by a delicate ivory stand is a %^YELLOW%^golden tablet %^RESET%^%^GREEN%^displaying the charge of th"
	"e Lady of Love.   A backdrop of crimson rose bushes, flush with richly scented blossoms frame the altar from behind.  Their brilliant dark-red blooms lifting in praise toward the %^BOLD%^%^WHITE%^stat"
	"ue %^RESET%^%^GREEN%^which who rises from the center of the pool, her hands held out in welcoming embrace.%^RESET%^"
	);

    set_smell("default","
The breeze carries the perfume of roses to you.");
    set_listen("default","Murmured prayers and soft laughter reach your ears.");


    set_exits(([ 
		"out" : "/d/dagger/Torm/city/c109",
		"northwest" : "/d/av_rooms/lurue/sunetemple_04",
		"southwest" : "/d/av_rooms/lurue/sunetemple_02",
	]));

}