#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFO;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^RESET%^%^GREEN%^The road continues to the east and west. "+
    "The entrance to one of the ruined buildings is here.%^RESET%^");
    set_exits( ([ "east" : FFOR"9", "west" : FFOR"7", "building" : FFOR"b6"]) );
}
