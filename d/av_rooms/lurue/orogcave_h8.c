// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("orogcave_h8");
    set_property("indoors",1);
    set_property("light",-2);
    set_property("no teleport",1);
    set_terrain("built cave");
    set_travel("slick floor");
    set_climate("mountain");

    set_short("%^RESET%^%^BLUE%^a %^BOLD%^%^BLACK%^gr%^BLUE%^a%^BLACK%^n%^RESET%^i%^BOLD%^%^BLACK%^te%^RESET%^%^BLUE%^ cave%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^Large, blocky stairs cut their way sharply upward through the granite mountain, curving slightly to the southeast as they spiral toward the top of the mountain.  A platform about half"
	" way up the stairwell leads to an %^RESET%^%^CYAN%^iron door%^BOLD%^%^BLACK%^.  Covered in strange symbols, the most noticeable of which is the large %^RESET%^%^CYAN%^steal fist%^BOLD%^%^BLACK%^ with "
	"%^GREEN%^green rays%^BLACK%^ extending from it, the door looks as though it would take a lot of force to open.  Above the door a dark %^RESET%^%^BLUE%^lantern hangs%^BOLD%^%^BLACK%^, casting this part"
	" of the hall into complete darkness.%^RESET%^"
	);

    set_smell("default","
The deep scent of earth, metal and bodies permeates the air.");
    set_listen("default","The sounds of Orog can be heard echoing through the halls.");


    set_exits(([ 
		"southeast" : "/d/av_rooms/lurue/orogcave_h9",
		"northeast" : "/d/av_rooms/lurue/orogcave_h7",
		"south" : "/d/av_rooms/lurue/orogcave_g1",
	]));

}