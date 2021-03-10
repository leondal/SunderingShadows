#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFTT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^WHITE%^The tunnel "+
    "continues to the north, southeast, and southwest.%^RESET%^");
    set_exits( ([ "north" : FFGTR"21", "southeast" : FFGTR"16", "southwest" : FFGTR"23"]) ); 
}
