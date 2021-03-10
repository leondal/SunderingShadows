// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("sunetemple_09");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^Hall of Creation%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^This wide hallway stretches along the northwestern side of the temple grounds, connecting the alcoves of %^CYAN%^beauty %^WHITE%^and %^MAGENTA%^passion %^WHITE%^together.  Lining each"
	" side of the marble corridor is a myriad of delicate %^RESET%^%^CYAN%^glass %^BOLD%^%^WHITE%^display cases.  Within each can be seen many stunning representations of the varied %^YELLOW%^crafts %^WHIT"
	"E%^created within the Realm.  Each of the items were selected for their exceptional %^CYAN%^beauty%^WHITE%^, as well as the clear %^MAGENTA%^passion %^WHITE%^and %^RED%^love %^WHITE%^that the crafter "
	"had for their work.  Sheets of %^RESET%^%^RED%^burgundy %^BOLD%^%^WHITE%^or %^RESET%^ivory %^BOLD%^%^WHITE%^velvet offer a back drop for many of the pieces, while larger items are suspended upon intri"
	"cately carved %^RESET%^%^ORANGE%^wooden stands %^BOLD%^%^WHITE%^that support their weight without detracting from their splendor.  Below or beside each piece is a small %^RESET%^%^CYAN%^plaque %^BOLD%"
	"^%^WHITE%^telling a bit of the history of the item as well as notes about their creator.  It would be very easy to spend hours %^GREEN%^viewing %^WHITE%^all the many display pieces.%^RESET%^"
	);

    set_smell("default","
The hallway is filled with murmurs of visitors admiring the display pieces.");
    set_listen("default","The scent of polish mixes with the faint hint of roses that drifts in from outside.");


    set_exits(([ 
		"northeast" : "/d/av_rooms/lurue/sunetemple_10",
		"southwest" : "/d/av_rooms/lurue/sunetemple_08",
	]));

}