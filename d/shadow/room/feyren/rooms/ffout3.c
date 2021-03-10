#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFO;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^RESET%^%^GREEN%^The road continues to the east and south. "+
    "The entrance to one of the ruined buildings is here.%^RESET%^");
    set_exits( ([ "south" : FFOR"4", "east" : FFOR"2", "building" : FFOR"b2"]) );
}
