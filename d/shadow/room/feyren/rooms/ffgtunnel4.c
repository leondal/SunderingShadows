#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFTT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^WHITE%^The tunnel "+
    "continues to the east and west here.%^RESET%^");
    set_exits( ([ "east" : FFGTR"5", "west" : FFGTR"3"]) ); 
}
