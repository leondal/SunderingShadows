#include "elf.h"
#include <std.h>

inherit ROOM;

void create() {
        ::create();
    set_terrain(ICE);
    set_travel(SLICK_FLOOR);
        set_climate("arctic");
        set_name("ruined rampart");
        set_short("ruined rampart");
        set_long("%^CYAN%^This is a the ruins of a defensive"+
		" rampart that has been mostly destroyed by the "+
		"relentless %^BOLD%^ice%^RESET%^%^CYAN%^ around it.  The ground is a mix of"+
		" ice with stone blocks lodged within them.  There"+
		" is a large %^BOLD%^throne%^RESET%^%^CYAN%^ made of ice sitting strangely"+
		" on top of the highest point of the ruins.");
        set_listen("default","You hear the sound of cold wind rushing"+
				" through the mountains.");
        set_items(([
                "ice" : "Glacial ice has destroyed the rampart.",
                "rocks" :"These rocks look to be the remains of a wall.",
                ({"throne","chair"}) : "This throne seems made of"+
				" icicles going from the ground to the sky. "+
				"  It would be very cold and uncomfortable to sit in.",
        ]));
        set_exits(([

                "down"  : ROOMS"ruin",
        ]));
}
