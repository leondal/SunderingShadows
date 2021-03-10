#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFC;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^BLUE%^Openings to the northeast and "+
    "southeast lead further into this massive cellar. An opening to the west "+
    "leads back toward the entrance.%^RESET%^");
    set_exits( ([ "west" : FFCR"2", "northeast" : FFCR"10", "southeast" : FFCR"4"]) );
}

