#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFC;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^BLUE%^Openings in the northeast, northwest, and southeast "+
    "lead further into this massive cellar.%^RESET%^");
    set_exits( ([ "northeast" : FFCR"8", "southeast" : FFCR"9", "northwest" : FFCR"4"]) );
}
