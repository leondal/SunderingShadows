#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFC;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^BLUE%^Openings to the north and east lead further "+
    "into this massive cellar.  An opening to the west leads back to the entrance.%^RESET%^");
    set_exits( ([ "north" : FFCR"15", "west" : FFCR"1", "east" : FFCR"3"]) );
}
