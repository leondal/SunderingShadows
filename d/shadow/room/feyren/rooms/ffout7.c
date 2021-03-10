#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFO;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^RESET%^%^GREEN%^The road continues to the east and west.%^RESET%^");
    set_exits( ([ "east" : FFOR"8", "west" : FFOR"6"]) );
}
