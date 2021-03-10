#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFO;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^RESET%^%^GREEN%^The road continues to the south and west.%^RESET%^");
    set_exits( ([ "west" : FFOR"1", "south" : FFOR"11"]) );
}
