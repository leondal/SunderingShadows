//Coded by Bane//
//Updated by ~Circe~ 8/13/15 to add the river and carriage house

#include <std.h>
inherit "/d/laerad/plains_base.c";

void create(){
    ::create();
    set_long(::query_long()+"\nTo the east stands a ramshackle "
       "%^RESET%^%^ORANGE%^building %^BOLD%^%^BLACK%^that has seen "
       "better days. Just beyond it, a murky, sulfurous %^RESET%^river %^BOLD%^%^BLACK%^cuts "
       "through the land, burbling and belching steam.%^RESET%^\n");
    add_item("river","The murky waters of the river might be gray or "
       "black - or perhaps even a muddy blue. The waters do not babble "
       "like the pleasant brooks of Parnelli Forest but instead belch "
       "up viscous, thick bubbles that burst to release a decaying, "
       "sulfurous scent.");
    add_item("building","The building has a sagging roof, but the "
       "doors are open, revealing a somewhat pleasant interior.");
    set_exits( ([
	"west":"/d/laerad/plains/plains47",
	"north":"/d/laerad/plains/plains59",
	"east":"/d/laerad/parnelli/forest/carr1"
    ]) );
}
