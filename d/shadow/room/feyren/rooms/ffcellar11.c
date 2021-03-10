#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFC;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^BLUE%^Openings in the northeast, northwest, and "+
    "southwest lead further into this massive cellar.%^RESET%^");
    set_exits( ([ "northeast" : FFCR"13", "southwest" : FFCR"10", "northwest" : FFCR"12"]) );
}
