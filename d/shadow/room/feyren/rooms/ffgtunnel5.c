#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFTT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^WHITE%^The tunnel "+
    "continues to the north and west here.%^RESET%^");
    set_exits( ([ "north" : FFGTR"6", "west" : FFGTR"4"]) ); 
}
