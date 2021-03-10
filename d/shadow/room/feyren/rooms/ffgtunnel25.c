#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFTT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^WHITE%^The tunnel "+
    "continues to the northeast, south, and west.%^RESET%^");
    set_exits( ([ "northeast" : FFGTR"24", "south" : FFGTR"26", "west" : FFGTR"27"]) ); 
}
