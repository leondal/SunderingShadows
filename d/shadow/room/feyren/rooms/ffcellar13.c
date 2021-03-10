#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFC;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^BLUE%^Openings in the southeast and "+
    "southwest lead further into this massive cellar.%^RESET%^");
    set_exits( ([ "southeast" : FFCR"14", "southwest" : FFCR"11"]) );
}
