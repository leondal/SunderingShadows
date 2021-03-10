#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFO;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^RESET%^%^GREEN%^The road continues to the north and west. "+
    "The entrance to one of the ruined buildings is here.%^RESET%^");
    set_exits( ([ "north" : FFOR"10", "west" : FFOR"8", "building" : FFOR"b5"]) );
}
