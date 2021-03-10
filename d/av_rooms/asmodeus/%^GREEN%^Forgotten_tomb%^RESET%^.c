// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("%^GREEN%^Forgotten_tomb%^RESET%^");
    set_property("indoors",1);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("rubble");
    set_climate("mountain");

    set_short("%^BOLD%^BLACK%^A da%^BOLD%^%^WHITE%^r%^BOLD%^%^BLACK%^k c%^BOLD%^%^WHITE%^ol%^BOLD%^%^BLACK%^d tomb%^RESET%^");

    set_long("%^BOLD%^%^ORANGE%^This is a steep sloping %^BOLD%^%^MAGENTA%^shaft %^BOLD%^%^ORANGE%^that leads further into the depths of the %^BOLD%^%^BLACK%^tomb. %^BOLD%^%^ORANGE%^It is not very big and the %^BOL"
	"D%^%^BLACK%^cold granite %^BOLD%^%^ORANGE%^of the walls seem to close in around you, almost as if it were a living being trying to %^GREEN%^strangle %^BOLD%^%^ORANGE%^the last bits of %^WHITE%^life %^"
	"BOLD%^%^ORANGE%^from your body. %^BOLD%^%^ORANGE%^To the north you see that the hallway continues into the %^BOLD%^%^BLACK%^darkness. %^BOLD%^%^ORANGE%^South is the hallway you came from upon entering"
	" this %^BOLD%^%^BLACK%^death %^BOLD%^%^WHITE%^ridden %^BOLD%^%^BLACK%^tomb%^RESET%^ "
	);

    set_smell("default","
%^BOLD%^%^ORANGE%^The scent of death is over powering%^RESET%^");
    set_listen("default","%^BOLD%^%^WHITE%^angelic %^BOLD%^%^GREEN%^hymns fill the halls%^RESET%^");

}