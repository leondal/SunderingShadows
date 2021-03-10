#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFTT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^WHITE%^The tunnel "+
    "continues to the southeast and north.%^RESET%^");
    set_exits( ([ "southeast" : FFGTR"15", "north" : FFGTR"10"]) ); 
}
