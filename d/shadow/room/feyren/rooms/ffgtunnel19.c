#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFTT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^WHITE%^The tunnel "+
    "continues to the northeast and east.%^RESET%^");
    set_exits( ([ "northeast" : FFGTR"18", "east" : FFGTR"20"]) ); 
}
