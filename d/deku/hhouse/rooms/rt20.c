#include <std.h>
#include "../inherits/area_stuff.h"
inherit RT;

void create() 
{
    ::create();
    set_long(TO->query_long() + "%^BOLD%^%^WHITE%^ You are on the edge of the "+
    "roof and could %^BOLD%^%^MAGENTA%^jump%^BOLD%^%^WHITE%^ down into the "+
    "courtyard far below if you were so inclined.%^RESET%^");

    set_exits((["west" : RROOMS+"19", "south" : RROOMS+"15", "north" : RROOMS+"25", 
    "southwest" : RROOMS+"14", "northwest" : RROOMS+"24"]));

    set_property("jump_destination", "east");

}
