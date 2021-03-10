#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFC;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^BLUE%^Openings in the northeast and southwest "+
    "lead further into this massive cellar.%^RESET%^");
    set_exits( ([ "northeast" : FFCR"4", "southwest" : FFCR"6"]) );
}
