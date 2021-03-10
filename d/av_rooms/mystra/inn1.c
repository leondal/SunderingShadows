// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("inn1");
    set_property("indoors",1);
    set_property("light",4);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^Castwater Inn Foyer%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^You've entered the foyer of the Castwater Inn, near the %^RESET%^%^ORANGE%^Sou%^BOLD%^%^BLACK%^th G%^RESET%^%^ORANGE%^ate %^BOLD%^%^WHITE%^of the city of Creen.  The inn is one of the"
	" more popular meeting places in town for travelers and locals to get together for a good time.  Here in the entryway, %^YELLOW%^lavish golden carpet %^WHITE%^lines the floor from wall to wall.  In the"
	" middle of the carpet is the same symbol the city bears on it's flag, that of a %^RED%^R%^YELLOW%^o%^RESET%^%^ORANGE%^c %^BOLD%^%^WHITE%^in all it's glory holding a mighty %^BLUE%^t%^CYAN%^r%^WHITE%^i"
	"%^BLUE%^d%^CYAN%^e%^WHITE%^n%^BLUE%^t%^WHITE%^.  PaintingS hang along the depicting local %^RESET%^%^GREEN%^landscapes and scenery%^BOLD%^%^WHITE%^.  From the ceiling hangs a very beautiful %^CYAN%^cr"
	"ystal chandelier %^WHITE%^to illuminate the room.  Exits from this room lead north to what appears to be a dining area, west to a staircase, and south to a lounge area.%^RESET%^"
	);

    set_smell("default","
%^CYAN%^Mutton, veal, and beef stew radiates from the north.%^RESET%^");
    set_listen("default","%^BOLD%^%^YELLOW%^Many conversations reach your ears from all around.%^RESET%^");


    set_exits(([ 
		"west" : "/d/av_rooms/mystra/inn4",
		"south" : "/d/av_rooms/mystra/inn3",
		"north" : "/d/av_rooms/mystra/inn2",
		"east" : "/d/av_rooms/mystra/teel3",
	]));

}