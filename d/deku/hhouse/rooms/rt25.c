#include <std.h>
#include "../inherits/area_stuff.h"
inherit RT;

void create() 
{
    ::create();
    set_long(TO->query_long() + "%^BOLD%^%^WHITE%^ You are on the edge of the "+
    "roof and could %^BOLD%^%^MAGENTA%^jump%^BOLD%^%^WHITE%^ down into the "+
    "courtyard far below if you were so inclined.%^RESET%^");

    set_exits((["west" : RROOMS+"24", "south" : RROOMS+"20", "north" : RROOMS+"30", 
    "southwest" : RROOMS+"19", "northwest" : RROOMS+"29"]));

    set_property("jump_destination", "east");

}
