#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFTT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^WHITE%^The tunnel opens "+
    "into a large dirt chamber to the north. The opening is "+
    "partially obscurred by thick spider web. The tunnel "+
    "continues to the southeast and southwest.");
    set_exits( ([ "southeast" : FFGTR"2", "north" : FFTR"40", "southwest" : FFGTR"17"]) ); 
}
