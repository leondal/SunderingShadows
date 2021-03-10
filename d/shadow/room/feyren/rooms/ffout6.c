#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFO;

void create() 
{
    ::create();
    set_long(TO->query_long() + "%^RESET%^%^GREEN%^The road continues to the north "+
    " and east. The entrance to one of the ruined buildings is here.%^RESET%^");
    set_exits( ([ "east" : FFOR"7", "north" : FFOR"5", "building" : FFOR"b3"]) );
    set_door("cellar door",FFCR"1","down");
    set_door_description("cellar door",C_DOOR);
}
