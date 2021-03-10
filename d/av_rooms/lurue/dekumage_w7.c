// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_w7");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("built tunnel");
    set_travel("decayed floor");
    set_climate("mountain");

    set_short("%^BOLD%^%^BLACK%^Underground Cave%^RESET%^");

    set_long("%^RESET%^%^MAGENTA%^This miserable little hole in the %^ORANGE%^earth %^MAGENTA%^is little more then a gouged out area that serves as a sleeping chamber for whatever creature makes its home here.   Li"
	"ke the rest of this warren, the walls are covered in %^BLACK%^%^BOLD%^claw %^RESET%^%^MAGENTA%^and %^RESET%^scrape %^MAGENTA%^marks where they were torn away at.  In one corner a scattered mess of %^R"
	"ESET%^trash %^MAGENTA%^has been gathered into a sleeping pallet.  More like a trash pile, you can only guess at what might be included in it.%^RESET%^"
	);

    set_smell("default","
The stink of unwashed bodies and fur linger in the air.");
    set_listen("default","You can hear something hissing near by.");

    set_search("trash","%^MAGENTA%^You search around in the messy pile of trash but find nothing you'd want to keep!%^RESET%^");
    
set_items(([ 
	({ "trash", "pallet", "bed", "trash pile" }) : "%^RESET%^The pile of trash seems to be mostly scraps of fur, bits of paper and some plant matter, but occasionally you think you see something sparkling in there.%^RESET%^",
	({ "tunnel", "earth", "stone", "ceilings", "walls", "floor" }) : "%^RESET%^%^ORANGE%^The tunnel seems to curve, dip and follow the path of least resistance, cutting through the stone and earth wherever the diggers found it easiest to excavate.  This causes the tunnel to narrow and widen at odd points and makes for a rather claustrophobic feeling as you explore through the confining passageway.%^RESET%^",
	({ "lichen", "phosphorescent", "phosphorescents", "moss" }) : "%^GREEN%^In a few of the cracks and gouges in the walls, you can make out small growths of a %^BOLD%^fa%^CYAN%^i%^GREEN%^nt%^WHITE%^l%^GREEN%^y il%^CYAN%^l%^GREEN%^u%^WHITE%^m%^GREEN%^ina%^CYAN%^t%^GREEN%^ed %^RESET%^%^GREEN%^moss that glows with a sickly phosphorescence.  The faint glow is difficult to see by, but keeps the tunnels from being completely pitch black.%^RESET%^",
	({ "claw marks", "marks", "scrapes", "gouges" }) : "%^BOLD%^%^BLACK%^The uneven crafting of the walls here shows the marks where claws and a few tools have dug away at the stone and earth to burrow deeper into the ground.  More then a few glow faintly with bits of phosphorescent moss.%^RESET%^	",
	]));

    set_exits(([ 
		"north" : "/d/av_rooms/lurue/dekumage_t9",
	]));

}