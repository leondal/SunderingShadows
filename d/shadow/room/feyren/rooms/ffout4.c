#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFO;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^RESET%^%^GREEN%^The road continues to the north and south.%^RESET%^");
    set_exits( ([ "south" : FFOR"5", "north" : FFOR"3"]) );
}
