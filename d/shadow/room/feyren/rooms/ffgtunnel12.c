#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFTT;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^WHITE%^The tunnel "+
    "continues to the southwest. A marble door has been set into "+
    "the eastern wall.%^RESET%^");
    set_exits( ([ "east" : FFGTR"13", "southwest" : FFGTR"11"]) ); 
    set_door("marble door",FFGTR"13","east");
    set_door_description("marble door",MARBLE_DOOR);
}
