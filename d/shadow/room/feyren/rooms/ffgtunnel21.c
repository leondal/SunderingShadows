#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFTT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^WHITE%^The tunnel "+
    "continues to the south and west.%^RESET%^");
    set_exits( ([ "south" : FFGTR"22", "west" : FFGTR"20"]) ); 
}
