#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFC;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^BLUE%^Openings in the northwest, southeast, and "+
    "southwest lead further into this massive cellar.%^RESET%^");
    set_exits( ([ "northwest" : FFCR"3", "southwest" : FFCR"5", "southeast" : FFCR"7"]) );
}
