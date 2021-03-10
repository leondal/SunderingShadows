// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("ankheg6");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("nat tunnel");
    set_travel("game track");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^an u%^RESET%^%^ORANGE%^n%^BOLD%^%^BLACK%^d%^RESET%^e%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^g%^BOLD%^%^BLACK%^r%^RESET%^o%^BOLD%^%^BLACK%^u%^RESET%^%^ORANGE%^n%^BOLD%^%^BLACK%^d h%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^t%^RESET%^ch%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^y%^RESET%^");

    set_long("%^ORANGE%^Smaller than the preceding cavern, the edges of this dirt chamber are littered with hundreds of large, l%^WHITE%^e%^ORANGE%^a%^WHITE%^th%^BOLD%^%^BLACK%^e%^RESET%^r%^ORANGE%^y %^BOLD%^eggs%^"
	"RESET%^%^ORANGE%^, each of them nearly two feet long and covered in a bright, %^BOLD%^%^GREEN%^greenish goo%^RESET%^%^ORANGE%^. Dust and bits of debris hang easily in the air of this cramped space, an"
	"d it is difficult to avoid breathing in some of it as you move about.%^WHITE%^"
	);

    set_smell("default","
The stench of the goo is overpowering.");
    set_listen("default","You can hear a faint clicking from within some of the eggs.");

    
set_items(([ 
	({ "egg", "eggs" }) : "%^ORANGE%^Each of the eggs is about two feet long, and has a brown, leathery surface that is slightly rough to the touch. A %^GREEN%^t%^BOLD%^%^BLACK%^h%^RESET%^%^GREEN%^i%^BOLD%^%^BLACK%^c%^RESET%^%^GREEN%^k %^BOLD%^g%^RESET%^r%^BOLD%^ee%^RESET%^n%^BOLD%^i%^RESET%^s%^BOLD%^%^GREEN%^h g%^WHITE%^o%^GREEN%^o %^RESET%^%^ORANGE%^seems to hold the eggs in place, giving off an %^GREEN%^a%^YELLOW%^c%^GREEN%^r%^WHITE%^i%^RESET%^%^GREEN%^d %^BOLD%^stench %^RESET%^%^ORANGE%^and seeping into the dirt below it, hardening the soil into a %^BOLD%^%^BLACK%^solid%^RESET%^%^ORANGE%^, %^BOLD%^%^BLACK%^r%^RESET%^o%^BOLD%^%^BLACK%^ck%^RESET%^%^ORANGE%^-%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^ke %^RESET%^%^ORANGE%^state.%^WHITE%^",
	]));

    set_exits(([ 
		"southwest" : "/d/av_rooms/brandobaris/ankheg5",
	]));

}