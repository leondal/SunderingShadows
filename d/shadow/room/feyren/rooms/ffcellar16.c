#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFC;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^BLUE%^Openings to the northwest "+
    "and southeast lead further into this massive cellar.%^RESET%^");
    set_exits( ([ "northwest" : FFCR"17", "southeast" : FFCR"15"]) );
}
