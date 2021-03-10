#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit GY_ROAD;

void create() {
    int x;
    ::create();
    set_long(TO->query_long() + "%^BOLD%^%^WHITE%^  The road "+
    "turns southward and continues southeast.  To the northwest "+
    "the road meets a %^RESET%^stone wall%^BOLD%^%^WHITE%^, an "+
    "old graveyard visible on the otherside of it.  A gate set "+
    "between two of its columns serves as a pathetic "+
    "barrier between you and the graveyard beyond.%^RESET%^");
    
    for(x = 0;x < sizeof(SW_ITEM);x++) {
	    add_item(SW_ITEM[x],"%^BOLD%^%^WHITE%^This pathetic "+
        "stone wall is only around two feet high and is mostly "+
        "in a state of ruin.  There are two taller stone columns "+
        "in the northwest corner which host a flimsy gate.  "+
        "It runs toward the north and the west here, "+
		"serving as a marker for the territory of the graveyard.%^RESET%^");
	}

    set_exits(([ "northwest" : GY_ROOMS+"grave1",
    "southeast" : "/d/deku/open/road3",
    ]));  

    set_door("gate",GY_ROOMS+"grave1","northwest");
    set_string("gate", "open", "%^RED%^The gate swings open with "+
    "a loud creaking noise.%^RESET%^");
    set_door_description("gate","%^BOLD%^%^BLACK%^This flimsy "+
    "makeshift gate is constructed of four slabs of rotten wood "+
    "that have been wired together haphazardly, placed on rusted "+
	"hinges, and set in between two large stone columns.  Painted "+
    "onto the slabs of wood are several types of flowers, bright "+
    "at one time they have now all faded.  Strangely, they seem "+
    "to meld with the atmosphere of the graveyard perfectly, as if "+
    "there fading was intended.%^RESET%^");
}

