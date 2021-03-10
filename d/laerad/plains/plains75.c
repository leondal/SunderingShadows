//Coded by Bane//
//Updated by ~Circe~ 8/13/15 to add the towers and river
#include <std.h>
inherit "/d/laerad/plains_mobs.c";

void create(){
    ::create();
    set_long(::query_long()+"\n"
       "To the north, "
       "you can see what seem to be crude %^RESET%^"
       "%^ORANGE%^towers %^BOLD%^%^BLACK%^rising over the plains. "
       "To the east, a murky, sulfurous %^RESET%^river %^BOLD%^%^BLACK%^cuts "
       "through the land, burbling and belching steam.%^RESET%^\n");
    add_item("river","The murky waters of the river might be gray or "
       "black - or perhaps even a muddy blue. The waters do not babble "
       "like the pleasant brooks of Parnelli Forest but instead belch "
       "up viscous, thick bubbles that burst to release a decaying, "
       "sulfurous scent.");
    set_exits( ([
	"west":"/d/laerad/plains/plains67",
	"north":"/d/laerad/plains/plains74"
    ]) );
}
