#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit GRAVEYARD2;

void create() 
{
    int x;
    ::create();
    set_long(TO->query_long() + "%^BOLD%^%^WHITE%^  A %^RESET%^stone wall%^BOLD%^%^WHITE%^"+
    " runs along the outside of the graveyard here with a gate set between two of its columns "+
    "in the southeast corner.");
    for(x = 0;x < sizeof(SW_ITEM);x++) 
    {
        add_item(SW_ITEM[x],"%^BOLD%^%^WHITE%^This pathetic stone wall is only around two feet "+
        "high and is mostly in a state of ruin.  There are two taller stone columns in the "+
        "southeast corner which host a flimsy gate.  It runs toward the north and the west here, "+
        "serving as a marker for the territory of the graveyard.%^RESET%^");
    }

    set_exits(([
    "north" : GY_ROOMS +"grave2",
    "southeast":"/d/deku/open/road4",
    "west" : GY_ROOMS +"grave1-1"
    ] ));   

    set_door("gate","/d/deku/open/road4","southeast");
    set_string("gate", "open", "%^RED%^The gate swings open with a loud creaking noise"+
    ".%^RESET%^");
    set_door_description("gate","%^BOLD%^%^BLACK%^This flimsy makeshift gate is constructed of "+
	"four slabs of rotted wood that have been wired together haphazardly, placed on rusted "+
	"hinges, and set in between two large stone columns.  Painted onto the slabs of wood are "+
	"several types of flowers, bright at one time they have now all faded.  Strangely, "+
	"they seem to meld with the atmosphere of the graveyard perfectly, as if there fading was "+
	"intended.%^RESET%^");
}
