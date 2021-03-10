// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("smitheri");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^GREEN%^Sangri Smitheri%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^This large building once served as a warehouse for storage and supplies, but over time and bit by bit, it has given way to the massive %^CYAN%^metal work shop %^ORANGE%^that it has "
	"become.  Sprawling piles of armor, weapons and other sundries stack in %^RED%^enormous heaps %^ORANGE%^all throughout the large stone and metal building.  Piling high and spilling down in unorganized "
	"clusters and clumps.  Rare is the piece that appears to be %^GREEN%^whole %^RESET%^%^ORANGE%^and %^BOLD%^%^BLACK%^finished%^RESET%^%^ORANGE%^. In fact, more then a few of the items seem to be mish mas"
	"hed together out of whatever piece of %^CYAN%^metal %^ORANGE%^was handy at the time.  Likewise, the two mechanical guardians that stoke the %^RED%^massive furnace %^ORANGE%^and maintain the heated for"
	"ge, appear to be made in a similar way.  Their hulking forms formed from hundreds of different pieces of armor, weapons and other, less identifiable, items.  Only one spot in this entire building seem"
	"s organized and orderly, and that is where the tools are kept.  Their %^CYAN%^steel forms %^ORANGE%^bright and pulsing with %^GREEN%^imbued energy%^RESET%^%^ORANGE%^, neatly set out on a scarred woode"
	"n counter that ends at a mammoth %^BOLD%^%^BLACK%^anvil%^RESET%^%^ORANGE%^.%^RESET%^"
	);

    set_smell("default","
The whole building smells of metal and magic.");
    set_listen("default","The buzz of energy through the ruined goods nearly drowns out the crackle of the fire.");

}