#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFO;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^RESET%^%^GREEN%^The road continues to the east and west. "+
    "The entrance to one of the ruined buildings is here.%^RESET%^");
    set_exits( ([ "west" : FFOR"3", "east" : FFOR"1", "building" : FFOR"b1"]) );
}
