#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFC;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^BLUE%^An opening to the northwest "+
    "leads further into this massive cellar. An opening to the south "+
    "leads back toward the entrance.%^RESET%^");
    set_exits( ([ "south" : FFCR"2", "northwest" : FFCR"16"]) );
}
