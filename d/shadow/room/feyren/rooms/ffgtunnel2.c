#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFTT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^WHITE%^The tunnel "+
    "continues to the northwest and southeast.%^RESET%^");
    set_exits( ([ "northwest" : FFGTR"1", "southeast" : FFGTR"3"]) ); 
}
