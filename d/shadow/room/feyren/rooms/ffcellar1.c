#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFC;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^BLUE%^A thick wooden door has been set into the "+
    "ceiling here, with a rickety wooden ladder leading up to it. An opening on the "+
    "east wall leads further into the cellar.%^RESET%^");
    set_exits( ([ "east" : FFCR"2", "up" : FFOR"b6"]) );
    set_door("cellar door",FFOR"6","up");
    set_door_description("cellar door",C_DOOR);
}
