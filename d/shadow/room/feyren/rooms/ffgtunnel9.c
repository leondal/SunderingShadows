#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFTT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^WHITE%^The tunnel "+
    "continues to the northeast, southeast, and west.%^RESET%^");
    set_exits( ([ "northeast" : FFGTR"8", "southeast" : FFGTR"10", "west" : FFGTR"16"]) ); 
}
