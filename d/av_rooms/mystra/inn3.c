// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("inn3");
    set_property("indoors",1);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^Castwater Lounge%^RESET%^");

    set_long("The lounge area of the inn tries to make it's occupants extremely comfortable in as many ways as possible.  All around are %^ORANGE%^soft leather sofas %^RESET%^designed to seat two comfortably.  They"
	" are grouped three sofas at a time making a 'U' formation with a 4' x 4' table sitting in the middle, allowing several adventurers to converse without crowding.  On the tables rest three%^BOLD%^%^BLAC"
	"K%^black pewter %^RESET%^candle-holders in a triangle pattern three different sizes.  %^BOLD%^%^YELLOW%^Golden candles %^RESET%^emerse the area when lit with a soft-lighting scenario.  %^MAGENTA%^Mura"
	"ls %^RESET%^and %^MAGENTA%^paintings %^RESET%^decorate the walls of the lounge, some depicting %^GREEN%^scenery %^RESET%^while others represent portraits of powerful adventurers long lost.  Wall to wa"
	"ll, the floor is covered with a %^ORANGE%^tan%^RESET%^, shag carpet - very soft on the feet.  Back north lies the %^CYAN%^foyer %^RESET%^from which you entered the lounge.  On the south wall, a %^BOLD"
	"%^Cigar Vendor%^RESET%^ stands behind a counter with glass bins behind him full of several types of tobacco products for sale.  On the west wall, two doors with markings on their oaken exterior."
	);

    set_smell("default","
%^CYAN%^Tobacco smoke and perfumes seize your senses%^RESET%^");
    set_listen("default","%^BOLD%^%^YELLOW%^Soft chatter goes on around you%^RESET%^");


    set_exits(([ 
		"north" : "/d/av_rooms/mystra/inn1",
	]));

}