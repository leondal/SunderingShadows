#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFTT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^WHITE%^The tunnel "+
    "continues to the east and southwest.%^RESET%^");
    set_exits( ([ "east" : FFGTR"23", "southwest" : FFGTR"25"]) ); 
}
