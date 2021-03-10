#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFTT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^WHITE%^The tunnel "+
    "continues to the east. A marble door has been set into "+
    "the western wall.%^RESET%^");
    set_exits( ([ "east" : FFGTR"25", "west" : FFGTR"28"]) ); 

    set_door("marble door",FFGTR"28","west");

    set_door_description("marble door",MARBLE_DOOR);
}
