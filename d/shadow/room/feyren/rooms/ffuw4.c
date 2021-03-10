#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFUT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^GREEN%^This "+
    "flooded tunnel continues into darkness to the "+
    "north and south.%^RESET%^");
    set_exits( ([ "north" : FFUR"3", "south" : FFUR"5"]) ); 
}
