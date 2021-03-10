#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFTT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^WHITE%^The tunnel "+
    "continues to the northeast and southwest.%^RESET%^");
    set_exits( ([ "northeast" : FFGTR"1", "southwest" : FFGTR"18"]) ); 
}
