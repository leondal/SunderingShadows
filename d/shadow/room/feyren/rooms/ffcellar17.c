#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFC;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^BLUE%^Openings to the northeast, "+
    "southeast, and west lead further into this massive cellar.%^RESET%^");
    set_exits( ([ "west" : FFCR"18", "southeast" : FFCR"16", "northeast" : FFCR"19"]) );
}
