#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFTT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^WHITE%^The tunnel "+
    "continues to the north and southwest.%^RESET%^");
    set_exits( ([ "north" : FFGTR"3", "southwest" : FFGTR"8"]) ); 
}
